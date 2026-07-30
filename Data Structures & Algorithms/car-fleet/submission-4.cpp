class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> car_details;
        int count = 0;
        
        // lets mash the details in one ds
        for(int i=0; i< position.size(); i++){

            car_details.push_back({position[i], speed[i]});
        }

        // ordering by position 
        sort(car_details.begin(), car_details.end());

        // algo
        stack<float> seen;
        for(int i=car_details.size()-1; i >=0; i--){
            
            float rem = (float)(target- car_details[i].first)/car_details[i].second;
            
            if(!seen.empty()){
                if(seen.top() >= rem){
                    seen.push(seen.top());
                }else{
                    seen.push(rem);
                    count++;
                }
            }else{
                seen.push(rem);
                count++;
            }
        }

        return count;
    }
};
