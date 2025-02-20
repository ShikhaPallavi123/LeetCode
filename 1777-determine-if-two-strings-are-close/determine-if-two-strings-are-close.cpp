class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int count1[26] = {0};
        int count2[26] = {0};

        if(word1.size() != word2.size()){
            return false;
        }

        for(int i = 0; i < word1.size(); i++){
            int index1 = word1[i] -'a';
            count1[index1]++;
        }
        for(int i = 0; i < word2.size(); i++){
            int index2 = word2[i] -'a';
            count2[index2]++;
        }

        for(int i = 0; i < 26; i++) {
            if((count1[i] != 0 && count2[i] == 0 ) || (count1[i] == 0 && count2[i] != 0 )){
                return false;

            }
            
        }


        sort(count1, count1+26);
        sort(count2, count2+26);

        for(int i = 0; i < 26; i++){
            if(count1[i] != count2[i]){
                return false;
            }
        }
        return true;
    }
};