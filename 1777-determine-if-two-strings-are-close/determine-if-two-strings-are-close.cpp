class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // Arrays to store frequency of each character
        int count1[26] = {0};
        int count2[26] = {0};

        // Check if lengths are different
        if (word1.size() != word2.size()) {
            return false;
        }

        // Count frequency of characters in word1
        for (char c : word1) {
            count1[c - 'a']++;
        }

        // Count frequency of characters in word2
        for (char c : word2) {
            count2[c - 'a']++;
        }

        // Check if both strings have the same set of characters
        for (int i = 0; i < 26; i++) {
            if ((count1[i] == 0 && count2[i] != 0) || (count1[i] != 0 && count2[i] == 0)) {
                return false;
            }
        }

        // Sort frequency counts and compare
        sort(count1, count1 + 26);
        sort(count2, count2 + 26);

        for (int i = 0; i < 26; i++) {
            if (count1[i] != count2[i]) {
                return false;
            }
        }

        return true;
    }
};