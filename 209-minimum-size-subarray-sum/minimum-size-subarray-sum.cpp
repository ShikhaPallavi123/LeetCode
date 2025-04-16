class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n =nums.size();
        int minSize = INT_MAX;
        int sum = 0;
        int count = 0;
        bool found = false;

        for(int i = 0 ; i < n ; i++){
           sum += nums[i];

            while(sum >= target){
                int currentLength = i - count +1;
            minSize = min(minSize, currentLength);
            found = true;

            sum -= nums[count];
            count++;
            }
            

        }

        if(found){
            return minSize;
        }else{
            return 0;
        }
    }
};