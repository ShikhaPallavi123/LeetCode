class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> hash(27,0);

        for(auto i:licensePlate)
        {
            int ch;
            if(i>='a' && i<='z'){
                ch = i -'a';
                hash[ch]++;
            }

            if(i>='A' && i<='Z'){
                ch = tolower(i)-'a';
                hash[ch]++;
            }
        }

        string ans="",temp="";
        bool flag = false;

        for(auto i:words)
        {
            vector<int> words_hash(27,0);

            for(int j=0; j<i.size(); j++)
                words_hash[i[j] - 'a']++;


            for(int i=0; i<27; i++)
            {
                if(hash[i] != 0)
                {
                    if(words_hash[i] >= hash[i])
                        flag = true;

                    else{
                        flag = false;
                        break;
                    }
                }
            }

            if(flag == true){
                if(ans == "")
                    ans = i;

                else{
                    temp = i;
                    if(temp.size() < ans.size())
                        ans = temp;
                }
            }
        }


        return ans;
    }
};