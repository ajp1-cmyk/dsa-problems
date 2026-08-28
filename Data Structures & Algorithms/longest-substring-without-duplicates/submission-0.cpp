class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int windowStart = 0;
        int windowEnd = 0;
        int maxLen = 0;
        
        unordered_set<int> seen;

        while (windowEnd < s.length()){
            
            while(seen.contains(s[windowEnd])){
                seen.erase(s[windowStart]);
                windowStart++;
            }

            seen.insert(s[windowEnd]);
            windowEnd++;
            
            maxLen = max(maxLen,static_cast<int> (seen.size()));
        }

        return maxLen;
    }
};
