class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        // Edge case: if needle is empty, return 0
        if (m == 0) {
            return 0;
        }

        // Edge case: if needle is longer than haystack, return -1
        if (n < m) {
            return -1;
        }

        // Outer loop: iterate through haystack
        for (int i = 0; i <= n - m; i++) {
            // Inner loop: check if needle matches starting at index i
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break; // No match, break out of the inner loop
                }
            }
            // If match is found, return the starting index i
            if (match) {
                return i;
            }
        }

        // If no match is found, return -1
        return -1;
    }
};