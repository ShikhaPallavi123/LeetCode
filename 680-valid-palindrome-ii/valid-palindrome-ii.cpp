class Solution {
public:
    bool validPalindrome(string s) {

        int start = 0;
        int end = s.size()-1;
        int count = 0;

        if(s.size() < 2){
            return true;
        }

        while(start <= end){
            if(s[start] != s[end]){
               return ispalindrom(s, start+1, end)||ispalindrom(s, start,end-1);
            }
            start++;
            end--;
           
        }
         return true;
    }
    

private:
        //helper function

    bool ispalindrom(const string& s, int start, int end){
        while(start < end){
            if(s[start] != s[end]){
            return false;
            }
            start++;
            end--;
        }
    return true;
    }
};


