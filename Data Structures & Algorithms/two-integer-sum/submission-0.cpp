class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int rem;

        for (int i=0; i< nums.size();i++){
             
             if(mp.contains(nums[i])){
                return {mp[nums[i]], i};
             }else{
                rem = target - nums[i];
                mp[rem] = i;
             }
        }
        return {-1,-1};
    }
};
