
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2) {
        vector<int> a;

        // Add elements of nums1
        for (int x : nums1) {
            a.push_back(x);
        }

        // Add elements of nums2
        for (int x : nums2) {
            a.push_back(x);
        }

        // Sort the combined array
        sort(a.begin(), a.end());

        int n = a.size();

        // If the size is odd
        if (n % 2 == 1) {
            return a[n / 2];
        }

        // If the size is even
        return ((double)a[n / 2 - 1] + a[n / 2]) / 2.0;
    }
};