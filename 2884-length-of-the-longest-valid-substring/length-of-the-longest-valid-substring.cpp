class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {

        unordered_set<string> forbiddenSet(forbidden.begin(), forbidden.end());
        int n = word.length();
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < n; ++end) {
            // Check substrings ending at `end` and starting within the last 10 characters
            for (int i = end; i >= max(start, end - 9); --i) {
                string currentSubstring = word.substr(i, end - i + 1);
                if (forbiddenSet.find(currentSubstring) != forbiddenSet.end()) {
                    start = i + 1;  // Move `start` to right after the forbidden substring
                    break;
                }
            }
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};