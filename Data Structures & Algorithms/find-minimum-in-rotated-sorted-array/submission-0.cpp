class Solution {
public:
    int findMin(vector<int> &nums) {
        int min = nums[0];

        for(int x: nums){
            if(min > x){
                min = x;
            }
        }
        return min;
    }
};
