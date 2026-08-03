class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftHeights;
        vector<int> rightHeights(height.size(),0);

        int maxht = 0;

        for(int i=0; i<height.size(); i++){
            leftHeights.push_back(maxht);
            if(maxht < height[i]){
                maxht = height[i];
            }
        }

        maxht = 0;

        for(int i=height.size()-1; i>=0; i--){
            rightHeights[i] = maxht;
            if(height[i] > maxht) {
                maxht = height[i];
            }
        }

        int result = 0;
        for(int i=0; i<height.size(); i++){
            int areaOver = min(leftHeights[i], rightHeights[i]) - height[i];
            if(areaOver > 0) result += areaOver;
        }

        return result;
    }
};
