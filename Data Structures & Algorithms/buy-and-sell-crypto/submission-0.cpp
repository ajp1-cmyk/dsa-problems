class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int windowStart=0; 
        int windowEnd = 1;

        while(windowEnd < prices.size()){
            if(prices[windowEnd] > prices[windowStart]){
                max_profit = max(max_profit, prices[windowEnd] - prices[windowStart]);
            }else{
                windowStart = windowEnd;
            }
            windowEnd++;
        }

        return max_profit;
    }
};
