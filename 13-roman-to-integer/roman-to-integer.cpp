#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // Map to store the values of individual Roman numerals
        unordered_map<char, int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int current_val = value[s[i]];

            // If the current value is less than the next value, subtract it
            if (i + 1 < n && current_val < value[s[i + 1]]) {
                ans -= current_val;
            } 
            // Otherwise, add it to the total
            else {
                ans += current_val;
            }
        }

        return ans;
    }
};