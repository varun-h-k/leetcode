class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
         int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If the pivot is found, find the element to swap with
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            std::swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the elements after the pivot
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};