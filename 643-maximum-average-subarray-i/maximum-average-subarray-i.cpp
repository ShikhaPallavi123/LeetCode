class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       
        double windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        
        // Initialize maxSum with the sum of the first window
        double maxSum = windowSum;
        
        // Slide the window from the start to the end of the array
        for (int i = k; i < nums.size(); i++) {
            // Add the new element to the window and subtract the oldest element
            windowSum += nums[i] - nums[i - k];
            
            // Update maxSum if the current window sum is greater
            if (windowSum > maxSum) {
                maxSum = windowSum;
            }
        }
        
        // Return the maximum average
        return maxSum / k;
    }
};