class Solution {
public:

bool isFreqSame(int freq1[], int freq2[]){
    for(int i = 0; i < 26; i++){
        if(freq1[i] != freq2[i]){
            return false;
        }
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        int freqency[26] = {0};
        for(int i = 0; i < s1.size(); i++){
            int index = s1[i] - 'a';
            freqency[index]++;
        }

        //search s1 permutation in s2
        int windowSize = s1.length();
        
        for(int i = 0;  i < s2.size(); i++){
            int windowIndex = 0;
            int index1 = i;
            int windowFreq[26] = {0};

            while(windowIndex < windowSize && index1 < s2.size()){
                windowFreq[s2[index1] - 'a']++;
                windowIndex++;
                index1++;
            }

            if(isFreqSame(freqency,windowFreq) ){
                return true;
            }
        }

        return false;
    }
};