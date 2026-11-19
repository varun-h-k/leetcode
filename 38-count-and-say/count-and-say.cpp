class Solution {
public:
    string countAndSay(int n) {
          string current = "1";
        
        // Generate terms from 2 up to n
        for (int step = 1; step < n; ++step) {
            string next_term = "";
            int len = current.length();
            
            for (int i = 0; i < len; ) {
                int j = i;
                // Count consecutive identical characters
                while (j < len && current[j] == current[i]) {
                    j++;
                }
                
                int count = j - i;
                next_term += to_string(count) + current[i];
                
                // Move pointer to the start of the next distinct character group
                i = j;
            }
            
            current = next_term;
        }
        
        return current;
        
    }
};