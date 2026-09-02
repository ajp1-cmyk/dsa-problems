class Solution {
public:
    int characterReplacement(string s, int k) {
    
        int max_freq = 0;

        unordered_map<char,int> freq_mp;

        int windowStart =0;
        int windowEnd = 0;
        
        int max_size = 0;

        while(windowEnd < s.length()) {
            
            freq_mp[s[windowEnd]]++;

            if(max_freq < freq_mp[s[windowEnd]]){
                max_freq = freq_mp[s[windowEnd]];
                       
            }    

            int size = windowEnd - windowStart+1;
            int rem_size = size - max_freq;

            while(rem_size > k){
                freq_mp[s[windowStart]]--;
                windowStart++;
                rem_size = windowEnd - windowStart + 1 - max_freq;
            }
            max_size = max(max_size, windowEnd - windowStart + 1);
            
            windowEnd++;
        }
        return max_size;
    }
};
