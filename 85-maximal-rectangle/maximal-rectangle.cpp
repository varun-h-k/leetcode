class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
       if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;
        
        for (int r = 0; r < rows; ++r) {
            // Update the histogram heights for the current row
            for (int c = 0; c < cols; ++c) {
                if (matrix[r][c] == '1') {
                    heights[c] += 1;
                } else {
                    heights[c] = 0;
                }
            }
            // Calculate the max rectangle area for the current histogram
            maxArea = max(maxArea, largestRectangleInHistogram(heights));
        }
        
        return maxArea;
    }

private:
    int largestRectangleInHistogram(const vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        // Iterate up to n (inclusive) to flush out remaining bars in the stack
        for (int i = 0; i <= n; ++i) {
            int currentHeight = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                // If stack is empty, the bar extends all the way to index 0
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }
        
        return maxArea;  
    }
};