class Solution {
public:

 int romanNumerals(char a){
            switch(a){
                case 'I' : return 1;
                case 'V' : return 5;
                case 'X' : return 10;
                case 'L' : return 50;
                case 'C' : return 100;
                case 'D' : return 500;
                case 'M' : return 1000;
                default  : return 0;
                
            }
        }
    int romanToInt(string s) {
        int result = 0;
        for(int i = 0; i< s.size(); i++){
            if(i+1 < s.size() && romanNumerals(s[i]) < romanNumerals(s[i+1]) ){
                result -= romanNumerals(s[i]);
            }else{
                result += romanNumerals(s[i]);
            }
        }
        return result;
    }
};