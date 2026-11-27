class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> result;
        vector<int> currentCombination;
        
        // Sorting allows us to prune branches early when candidates[i] > remaining target
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, currentCombination, result);
        return result;
    }

private:
    void backtrack(const vector<int>& candidates, int remaining, int startIndex, 
                   vector<int>& current, vector<vector<int>>& result) {
        // Base case: Valid combination found
        if (remaining == 0) {
            result.push_back(current);
            return;
        }

        for (int i = startIndex; i < candidates.size(); ++i) {
            // Pruning: Since the array is sorted, no subsequent numbers can fit
            if (candidates[i] > remaining) {
                break;
            }

            // Choose the current number
            current.push_back(candidates[i]);
            
            // Recurse with the SAME index 'i' because elements can be reused
            backtrack(candidates, remaining - candidates[i], i, current, result);
            
            // Undo the choice (backtrack) before trying the next candidate
            current.pop_back();
        }
        
    }
};