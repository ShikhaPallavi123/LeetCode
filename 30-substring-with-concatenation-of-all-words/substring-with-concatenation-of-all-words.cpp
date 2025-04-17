class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
       
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;

        // Early return if totalLen is longer than string
        if (s.length() < totalLen) return result;

        // Step 1: Frequency map of words in the list (traditional loop)
        unordered_map<string, int> wordFreq;
        for (int i = 0; i < words.size(); i++) {
            wordFreq[words[i]]++;
        }

        // Step 2: Sliding window to check for concatenation of all words
        for (int i = 0; i < wordLen; i++) {  // Check every possible offset (wordLen possibilities)
            int left = i;  // Left pointer of the sliding window
            int right = i;  // Right pointer of the sliding window
            int count = 0;  // Number of valid words matched
            unordered_map<string, int> seen;  // Frequency map for words in the current window

            // Slide the window over the string
            while (right + wordLen <= s.length()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordFreq.find(word) != wordFreq.end()) {
                    seen[word]++;
                    count++;

                    // If a word appears more times than allowed, move left pointer
                    while (seen[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // If we have matched all words, add the starting index to result
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    // If the word is not in the list of words, reset the window
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }

   
};