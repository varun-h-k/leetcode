class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int max_sum = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            // Either extend the previous subarray or start a new one at nums[i]
            current_sum = max(nums[i], current_sum + nums[i]);
            // Update the global maximum found so far
            max_sum = max(max_sum, current_sum);
        }
        
        return max_sum;
        
    }
};