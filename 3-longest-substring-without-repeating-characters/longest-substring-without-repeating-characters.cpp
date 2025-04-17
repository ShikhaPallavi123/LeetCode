class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> seen;
        int left = 0; 
        int right = 0;
        int maxLen = 0;

        while(right < n ){
            if(seen.find(s[right]) == seen.end()){
                seen.insert(s[right]);
                maxLen = max(maxLen, right-left+1);
                right++;

            }else{
                seen.erase(s[left]);
                left++;
            }
        }

        return maxLen;
    }
};