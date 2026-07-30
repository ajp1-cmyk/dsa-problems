
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;
        vector<vector<string>> result;

        for(const auto& word: strs){
            string key= word;
            sort(key.begin(),key.end());
            groups[key].push_back(word);

        }

        for(auto& [_,words]: groups ){
            result.push_back(words);
        }
        return result;
    }
};
