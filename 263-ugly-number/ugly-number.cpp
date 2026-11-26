class Solution {
public:
    bool isUgly(int n) {
        
                if (n <= 0) {
            return false;
        }
        
        int factors[] = {2, 3, 5};
        for (int p : factors) {
            while (n % p == 0) {
                n /= p;
            }
        }
        
        return n == 1;
    }
};