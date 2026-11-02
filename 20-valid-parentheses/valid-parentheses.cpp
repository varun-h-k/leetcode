class Solution {
public:
    bool isValid(string s) {
        
          stack<char> st;
        for (char c : s) {
            // If it's an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                // If it's a closing bracket, check if the stack is empty
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                // Check if the top matches the corresponding opening bracket
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
                st.pop(); // Remove the matched opening bracket
            }
        }
        // If stack is empty, all opening brackets were matched
        return st.empty();
    }
};