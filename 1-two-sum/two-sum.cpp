class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            // Removed quotes and the trailing semicolon
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j}; // Returns the indices when found
                }
            }
        }
        return {}; // Return an empty vector if no pair is found
    }
};