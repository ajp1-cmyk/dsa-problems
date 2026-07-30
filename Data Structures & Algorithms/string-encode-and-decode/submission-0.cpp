class Solution {
public:

    string encode(vector<string>& strs) {
      string res = "";
      
      for(auto word: strs){
        res += to_string(word.length()) + "#" + word;
      }
      
      return res;
    }

    vector<string> decode(string s) {
      vector<string> res;
      int i = 0;

      while(i < s.length()){
        int j = i;
        int l = 0;
        while(s[j]!='#'){
          j+=1;
          l+=1;
        }
        int length = stoi(s.substr(i,l));
        res.push_back(s.substr(j+1,length));
        i= j + length+1;
      }
      return res;
    }
};
