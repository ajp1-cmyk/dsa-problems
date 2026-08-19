class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> flattened;

        for(auto row: matrix){
            for(auto x: row){
                flattened.push_back(x);
            }
        }

        int left = 0;
        int right = flattened.size()-1;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(flattened[mid] == target) return true;
            else if(flattened[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return false;
    }
};
