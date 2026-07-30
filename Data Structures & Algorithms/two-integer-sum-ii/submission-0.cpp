class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int left = 0;
        int right = numbers.size()-1;

        while(left < right){
            int rem = numbers[left] + numbers[right];

            if(rem > target){
                right--;
            }else if(rem < target){
                left++;
            }else if (rem==target){
                return {left+1,right+1};
            }
        }

        return {-1,-1};
    }
};
