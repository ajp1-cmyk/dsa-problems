class MinStack {
     
   stack<pair<int,int>> min_stack;
   int min = INT_MAX;

public:

    MinStack(): min_stack() {
     
    }
    
    void push(int val) {
       if(val <min){
        min = val;
       }

        min_stack.push({val,min});

    }
    
    void pop() {
       min_stack.pop();

       if(min_stack.empty()){
            min = INT_MAX;
       }else{
        min = min_stack.top().second;
       }
        
    }
    
    int top() {
       return min_stack.top().first;
    }
    
    int getMin() {
        return min_stack.top().second;
    }
};
