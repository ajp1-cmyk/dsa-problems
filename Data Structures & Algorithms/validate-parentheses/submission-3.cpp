class Solution {
public:
    bool isValid(string s) {
        
        stack<char> leftOperation;
        unordered_map<char,char> match = {
            {']','['},
            {'}','{'},
            {')','('}
        };

        for (char ch: s){
        
          if(!match.contains(ch)){
            leftOperation.push(ch);
            continue;
          }
          
          if(leftOperation.empty() || leftOperation.top()!= match[ch]){
                return false;
          }

            leftOperation.pop();
            
        }

        if(!leftOperation.empty()) return false;
        return true;
    }
};
