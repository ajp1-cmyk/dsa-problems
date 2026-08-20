class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int right = piles[piles.size()-1];
        int left = 1;
        int min_rate = INT_MAX;
        int mid = right;

        while(left<=right){
            int total = 0;
            for(const int x: piles){
                total  = total + x/mid;
                
                if(x%mid != 0){
                    total +=1;
                }
            }

            if(h >= total){
                min_rate = min(min_rate,mid);
                right = mid-1;
            }else{
                left = mid+1;
            }

            mid = left + (right-left)/2;
        }
        return min_rate;

    }
};
