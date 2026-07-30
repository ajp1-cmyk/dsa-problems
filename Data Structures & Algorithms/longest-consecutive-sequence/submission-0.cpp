class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int max_size = 0;

        auto it = unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());

        while (right < nums.size()){

                while(right-left + 1 > 1 && nums[right] - nums[right-1] > 1){
                    left++;
                }
                max_size = max(right-left+1, max_size);
            right++;
        }
        return max_size;
    }
};
