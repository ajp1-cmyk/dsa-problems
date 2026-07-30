class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      
     vector<int> results(temperatures.size(),0);
     stack<int> latest_days;

    for(int i=0; i<temperatures.size(); i++){
            
            while(!latest_days.empty() && temperatures[latest_days.top()] < temperatures[i]){
                results[latest_days.top()] = i - latest_days.top();
                latest_days.pop();
            }

            latest_days.push(i);
    }
     
    
     return results;

    }
};
