class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
           vector<string> result;
        int n = static_cast<int>(words.size());
        int i = 0;

        while (i < n) {
            int j = i + 1;
            int lineChars = static_cast<int>(words[i].size());

            // Greedily pack as many words as possible with at least one space between words
            while (j < n && lineChars + static_cast<int>(words[j].size()) + (j - i) <= maxWidth) {
                lineChars += static_cast<int>(words[j].size());
                j++;
            }

            int numWords = j - i;
            int totalSpaces = maxWidth - lineChars;
            string line;

            // Last line or single-word line: left-justified
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += ' ';
                    }
                }
                line.append(maxWidth - static_cast<int>(line.size()), ' ');
            } else {
                // Full justification: distribute extra spaces evenly, bias left on remainder
                int gaps = numWords - 1;
                int evenSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spacesToAdd = evenSpaces + (k - i < extraSpaces ? 1 : 0);
                        line.append(spacesToAdd, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};