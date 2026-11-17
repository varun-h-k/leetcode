class Solution {
public:
    int jump(vector<int>& nums) {
             int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        // We iterate up to n - 2 because we don't need to jump from the last index
        for (int i = 0; i < n - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]);

            // If we have reached the end of the current jump range
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;

                // Early exit if the current jump range already reaches or exceeds the last index
                if (currentEnd >= n - 1) {
                    break;
                }
            }
        }

        return jumps;
        
    }
};