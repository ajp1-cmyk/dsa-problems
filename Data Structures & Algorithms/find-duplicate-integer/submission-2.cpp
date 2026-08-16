class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // unordered_set<int> seen;

        // for(int x: nums){
        //     if(seen.contains(x)){
        //         return x;
        //     }else{
        //         seen.insert(x);
        //     }
        // }

        int slow = 0;
        int fast = 0;

        while(fast < nums.size()+1){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(fast == slow) break;
        }

        int slow2 = 0;
        while(slow2!=slow){
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
};
