class Solution {
public:
    bool isNumber(string s) {
          bool seenDigit = false;
        bool seenExponent = false;
        bool seenDot = false;

        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];

            if (std::isdigit(curr)) {
                seenDigit = true;
            } 
            else if (curr == '+' || curr == '-') {
                // Sign is only valid at the very beginning or right after 'e'/'E'
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } 
            else if (curr == 'e' || curr == 'E') {
                // Exponent cannot appear twice and must follow at least one digit
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                // Reset seenDigit because an integer must follow the exponent
                seenDigit = false; 
            } 
            else if (curr == '.') {
                // Dot cannot appear twice or after an exponent
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } 
            else {
                // Any other character (like 'a', 'b', etc.) is invalid
                return false;
            }
        }

        return seenDigit;
        
    }
};