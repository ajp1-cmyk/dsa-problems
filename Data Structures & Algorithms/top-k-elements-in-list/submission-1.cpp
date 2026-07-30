class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> result;
        for(auto x: nums){
            if(!mp.contains(x)){
                mp[x] = 1;
            }else{
                mp[x]++;
            }
        }

        vector<pair<int,int>> vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(), [](const auto& a,const auto& b ){
            return a.second > b.second;
        });

       for(int i=0; i<k; i++){
            result.push_back(vec[i].first);
       } 
      return result;
    }
};
