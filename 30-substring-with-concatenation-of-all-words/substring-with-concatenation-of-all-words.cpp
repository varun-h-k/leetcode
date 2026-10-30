class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
           std::vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;

        if (s.length() < totalLen) return result;

        // Count frequency of each word in the words array
        std::unordered_map<std::string, int> wordMap;
        for (const std::string& word : words) {
            wordMap[word]++;
        }

        // Iterate through each possible offset from 0 to wordLen - 1
        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i;
            std::unordered_map<std::string, int> seenMap;
            int count = 0;

            while (right + wordLen <= s.length()) {
                std::string subWord = s.substr(right, wordLen);
                right += wordLen;

                // Check if the word is in our target map
                if (wordMap.find(subWord) != wordMap.end()) {
                    seenMap[subWord]++;
                    count++;

                    // If we have more instances of subWord than required, shrink from left
                    while (seenMap[subWord] > wordMap[subWord]) {
                        std::string leftWord = s.substr(left, wordLen);
                        seenMap[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // If valid count matches total words needed, record the start index
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    // Not a valid word, reset the window
                    seenMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
        
    }
};