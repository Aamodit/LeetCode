class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // Mark broken letters
        vector<bool> broken(26, false);
        for (char c : brokenLetters) {
            broken[c - 'a'] = true;
        }

        int count = 0;
        bool valid = true;

        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {
                // End of word reached
                if (valid) count++;
                valid = true; // reset for next word
            } else {
                if (broken[text[i] - 'a']) {
                    valid = false; // word contains broken letter
                }
            }
        }

        return count;
    }
};
