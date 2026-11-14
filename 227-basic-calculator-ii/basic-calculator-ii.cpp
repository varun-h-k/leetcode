class Solution {
public:
    int calculate(string s) {
        long long currentNumber = 0;
        long long lastNumber = 0;
        long long result = 0;
        char sign = '+';

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            }

            // If it's an operator or the end of the string
            if (!isspace(c) && !isdigit(c) || i == s.length() - 1) {
                if (sign == '+') {
                    result += lastNumber;
                    lastNumber = currentNumber;
                } else if (sign == '-') {
                    result += lastNumber;
                    lastNumber = -currentNumber;
                } else if (sign == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (sign == '/') {
                    lastNumber = lastNumber / currentNumber; // C++ truncates toward zero for integer division
                }
                
                sign = c;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;
        
    }
};