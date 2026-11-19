class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;          // Pointer in s
        int j = 0;          // Pointer in p
        int starIdx = -1;   // Last '*' position in p
        int matchIdx = 0;   // Position in s corresponding to starIdx

        while (i < static_cast<int>(s.size())) {
            // Direct character match or '?' wildcard
            if (j < static_cast<int>(p.size()) && (p[j] == '?' || p[j] == s[i])) {
                ++i;
                ++j;
            }
            // Record '*' position and try matching 0 characters first
            else if (j < static_cast<int>(p.size()) && p[j] == '*') {
                starIdx = j;
                matchIdx = i;
                ++j;
            }
            // Mismatch occurred: backtrack to the last '*' and match one more char in s
            else if (starIdx != -1) {
                j = starIdx + 1;
                ++matchIdx;
                i = matchIdx;
            }
            // No match and no '*' to fall back on
            else {
                return false;
            }
        }

        // Consume any trailing '*' characters in p
        while (j < static_cast<int>(p.size()) && p[j] == '*') {
            ++j;
        }

        return j == static_cast<int>(p.size());
    }
};
