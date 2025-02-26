class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.empty()){
            return "";
        }

        sort(strs.begin(), strs.end());

      
        int minLength = INT_MAX;
          int count=0;
        for(int i = 0; i < strs.size(); i++){
           int length = strs[i].size();
           minLength = min( minLength, length);

        }

        for(int i = 0; i <  minLength; i++){
            if(strs[0][i] == strs[strs.size()-1][i] ){
                count++;
            }else{
                break;
            }
        }
        if(count == 0){
            return "";
        }else{
            return strs[0].substr(0, count);
        }
    }
};