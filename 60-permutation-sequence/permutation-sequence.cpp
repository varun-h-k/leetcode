class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> nums;

        // Store numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        // Calculate factorials
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }

        // Convert k to zero-based indexing
        k--;

        while (n > 0) {
            int index = k / fact[n - 1];

            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);

            k %= fact[n - 1];
            n--;
        }

        return ans;
        
    }
};