class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::vector<std::vector<int>> result;
    // 1. Sort the array to handle duplicates and start from the smallest permutation
    std::sort(nums.begin(), nums.end());
    
    do {
        result.push_back(nums);
    } while (std::next_permutation(nums.begin(), nums.end()));
    
    return result;
        
    }
};