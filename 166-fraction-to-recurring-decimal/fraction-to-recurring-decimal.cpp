
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string ans = "";

        // Check whether the result is negative
        if ((numerator < 0) != (denominator < 0)) {
            ans += "-";
        }

        // Convert to long long to avoid integer overflow
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // Integer part
        ans += to_string(n / d);

        long long rem = n % d;

        // If there is no fractional part
        if (rem == 0) return ans;

        ans += ".";

        // Store each remainder and its position
        unordered_map<long long, int> seen;

        while (rem != 0) {
            // If remainder repeats, the decimal repeats
            if (seen.find(rem) != seen.end()) {
                ans.insert(seen[rem], "(");
                ans += ")";
                break;
            }

            seen[rem] = ans.size();

            rem *= 10;
            ans += to_string(rem / d);
            rem %= d;
        }

        return ans;
    }
};
