
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;
        vector<vector<string>> anagrams;

        for(auto word: strs){
            string str= word;
          sort(word.begin(),word.end());

          if(groups.contains(word)){
            groups[word].push_back(str);
          }else{
            groups[word] = {str};
          }
        
        }

        for(auto& [word,words]: groups ){
            anagrams.push_back(words);
        }
        return anagrams;
    }
};
