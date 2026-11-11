class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        std::string result = "";
        while (columnNumber > 0) {
            --columnNumber; // Adjust to 0-indexed (0 to 25)
            result.push_back('A' + (columnNumber % 26));
            columnNumber /= 26;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};