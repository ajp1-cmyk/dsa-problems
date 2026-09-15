class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0;
        stack<pair<int,int>> st;

        st.push({heights[0],0});
        for(int i=1; i<heights.size(); i++){
            int back=i;
            while(!st.empty() && st.top().first > heights[i]){
                int area =  (i - st.top().second)*st.top().first;
                maxArea = max(maxArea,area);
                back = st.top().second;
                st.pop();
            }
            st.push({heights[i],back});
        }
        while(!st.empty()){
            pair<int,int> pt = st.top();
            int area = pt.first * (heights.size() - pt.second);
            maxArea = max(maxArea,area);
            st.pop();
        }
        return maxArea;
    }
};
