class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
          if (intervals.empty()) return {};

        // 1. Sort intervals by their start time
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> merged;
        for (const auto& interval : intervals) {
            // If the list of merged intervals is empty or current interval 
            // does not overlap with the previous, append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // Otherwise, there is an overlap, so merge with the previous interval
                merged.back()[1] = std::max(merged.back()[1], interval[1]);
            }
        }

        return merged;
        
    }
};