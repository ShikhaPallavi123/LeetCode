class Solution {
public:
    int strStr(string haystack, string needle) {
          int n = haystack.length();
    int m = needle.length();

    // Edge case: if needle is empty, return 0
    if (m == 0) {
        return 0;
    }

    // Edge case: if needle is longer than haystack, return -1
    if (n < m) {
        return -1;
    }

    // Sliding window approach
    for (int i = 0; i <= n ; i++) {
        // Check if the substring matches needle
        if (haystack.substr(i, m) == needle) {
            return i; // Return the index of the first occurrence
        }
    }

    // If no match is found, return -1
    return -1;
    }
};