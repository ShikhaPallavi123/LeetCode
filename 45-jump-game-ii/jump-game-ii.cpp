class Solution {
public:
    int jump(vector<int>& nums) {
        

        for(int i = 1; i < nums.size(); i++){
            nums[i] = max(i+nums[i], nums[i-1]);
        }

        int index = 0;
        int minJump = 0;

        while(index < nums.size()-1){
            minJump++;
            index = nums[index];
        }
        return minJump;
    }
};