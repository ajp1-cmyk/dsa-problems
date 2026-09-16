class Solution {
public:

bool sum(vector<int> counts){
    int sum = 0;
    for(int i=0; i<26; i++){
        if(counts[i]!=0) return false;
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp;
        vector<int> counts(26,0);

        for(char ch: s1){
            counts[ch-'a'] += 1;
        }
        
        int k = s1.length();

        int right=0,left=0;
        
        while(right < s2.length()){
            counts[s2[right]-'a'] -=1;

            if(right>=k-1){
                if(sum(counts)) return true;
                counts[s2[left]-'a'] +=1;
                left++;
            }
            right++; 
        }      
        return false;
    }
};