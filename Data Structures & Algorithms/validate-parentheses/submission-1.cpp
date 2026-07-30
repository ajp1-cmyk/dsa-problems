class Solution {
public:
    bool isValid(string s) {
        
        stack<char> leftOperation;

        for (char ch: s){
            if(ch == '(' || ch=='{' || ch=='['){
                leftOperation.push(ch);
            }
            else{
                if(leftOperation.empty()) return false;
                
                if(ch == ')' && leftOperation.top() == '('){
                    leftOperation.pop();
                }
                else if(ch == ']' && leftOperation.top()=='['){
                    leftOperation.pop();
                }
               else if(ch=='}' && leftOperation.top()=='{'){
                    leftOperation.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(!leftOperation.empty()) return false;
        return true;
    }
};
