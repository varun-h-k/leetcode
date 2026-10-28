class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
           int n = points.size();
        if (n <= 2) return n;

        int max_points = 1;

        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int count = 2; // Line formed by points[i] and points[j]

                for (int k = j + 1; k < n; ++k) {
                    int x3 = points[k][0], y3 = points[k][1];
                    // Check if points[i], points[j], and points[k] are collinear
                    long long a = (long long)(y2 - y1) * (x3 - x1);
                    long long b = (long long)(y3 - y1) * (x2 - x1);
                    if (a == b) {
                        count++;
                    }
                }
                max_points = std::max(max_points, count);
            }
        }

        return max_points;
        
        
    }
};