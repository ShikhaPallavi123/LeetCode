#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seenNumbers;  
        while (n != 1) {
            if (seenNumbers.find(n) != seenNumbers.end()) {  
                return false;  
            }
            seenNumbers.insert(n); 
            
            int total = 0;
        
            while (n > 0) {
                int digit = n % 10; 
                total += digit * digit;
                n /= 10; 
            }
            n = total;  
        }
        return true; 
    }
};
