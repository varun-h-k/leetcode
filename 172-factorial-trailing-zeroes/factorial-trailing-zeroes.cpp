class Solution {
public:
    int trailingZeroes(int n) {
             int count = 0;
        
        // Divide n by powers of 5 (5, 25, 125, ...) and add to the count
        while (n > 0) {
            n /= 5;
            count += n;
        }
        
        return count;
        
    }
};