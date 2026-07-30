class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      
     vector<int> results;
     
     for(int i=0; i<temperatures.size()-1; i++){
        for(int j=i+1; j < temperatures.size(); j++){
            if(temperatures[i] < temperatures[j]){
                results.push_back(j-i);
                break;
            }
            else if(j==temperatures.size()-1){    
                results.push_back(0);
            }
        }
      }   
      results.push_back(0);

     return results;

    }
};
