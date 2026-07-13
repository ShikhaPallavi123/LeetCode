class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;
        int ans = 0;
        int left = 0;
        
        while (left < n - 1 && height[left] <= height[left + 1]) {
            left++;
        }
        
        int peak_index = left;
        
        while (left < n) {
            int right = left + 1;
            int terrain_inside = 0; 
            
            while (right < n && height[right] < height[left]) {
                terrain_inside += height[right];
                right++;
            }
            
            if (right < n) {
                int distance = right - left - 1;
                int min_height = min(height[left], height[right]);
                int bounding_box_area = distance * min_height;
                
                ans += (bounding_box_area - terrain_inside);
                
                left = right; 
                peak_index = right;
            } else {
                break; 
            }
        }
        
        int right = n - 1;
        
        while (right > peak_index && height[right] <= height[right - 1]) {
            right--;
        }
        
        while (right > peak_index) {
            int left_ptr = right - 1;
            int terrain_inside = 0;
        
            while (left_ptr >= peak_index && height[left_ptr] < height[right]) {
                terrain_inside += height[left_ptr];
                left_ptr--;
            }
            
            if (left_ptr >= peak_index) {
                int distance = right - left_ptr - 1;
                int min_height = min(height[right], height[left_ptr]);
                int bounding_box_area = distance * min_height;
                
                ans += (bounding_box_area - terrain_inside);
                
                right = left_ptr;
            } else {
                break; 
            }
        }
        
        return ans;        
    }
};
