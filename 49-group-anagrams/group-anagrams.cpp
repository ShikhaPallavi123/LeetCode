class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            anagrams[sorted_s].push_back(s);
        }

        vector<vector<string>> result;
        for (unordered_map<string, vector<string>>::iterator it = anagrams.begin(); it != anagrams.end(); it++) {
            result.push_back(it->second);
        }

    return result;
    }
};