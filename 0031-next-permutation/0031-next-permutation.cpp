class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // 1. Find the first decreasing element from the back
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // 2. If the entire array is descending, reverse it to get the smallest order
        if (i >= 0) {
            int j = n - 1;
            // 3. Find the element just larger than nums[i] from the back
            while (nums[j] <= nums[i]) {
                j--;
            }
            // 4. Swap them
            std::swap(nums[i], nums[j]);
        }

        // 5. Reverse the sequence after the pivot position 'i'
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};