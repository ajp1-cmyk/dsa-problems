class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;

        for(string str: tokens){

          try{
            operands.push(stoi(str));
          }
            catch(...){

                int op2 = operands.top();
                operands.pop();
                int op1 = operands.top();
                operands.pop();

                switch (str.front()) {
                    case '+':
                      operands.push(op1+op2);
                      break;
                    case '-':
                      operands.push(op1-op2);
                      break;
                    case '/':
                      operands.push(op1/op2);
                      break;
                    case '*':
                      operands.push(op1*op2);
                      break;
                    default: break;
                }
            }

        }
     return operands.top();
    }
};
