class Solution {
    public int trap(int[] height) {
        //find leftMax
        int left_Max[] = new int[height.length];
        left_Max[0] = height[0];
        for(int i = 1; i < height.length; i++){
            left_Max[i] = Math.max(left_Max[i-1], height[i]);
         }
        //find rightMax
        int right_Max[] = new int[height.length];
        right_Max[height.length-1] = height[height.length-1];
        for(int i = height.length-2; i >= 0; i--){
            right_Max[i] = Math.max(right_Max[i+1], height[i]);
        }

        // water_Trapped
        int water_Trapped = 0;
        for(int i = 0; i < height.length; i++){
            int water_Level = Math.min(left_Max[i], right_Max[i]);
            water_Trapped = water_Trapped+(water_Level - height[i]);
        }
        

       return water_Trapped;
        
        
    }
}