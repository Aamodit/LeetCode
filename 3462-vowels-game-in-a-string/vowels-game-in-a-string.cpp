class Solution {
public:
    bool doesAliceWin(string s) {
        string vowels = "aeiou";
        for (char c : s) {
            if (vowels.find(c) != string::npos) {
                return true; // Alice has at least one valid move
            }
        }
        return false; // No vowels → Alice loses
    }
};