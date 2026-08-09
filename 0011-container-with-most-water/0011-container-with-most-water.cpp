class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            // Calculate width between the two pointers
            int width = right - left;
            
            // The water level is limited by the shorter line
            int current_height = std::min(height[left], height[right]);
            
            // Calculate area and update maximum water found so far
            int current_water = width * current_height;
            max_water = std::max(max_water, current_water);
            
            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};