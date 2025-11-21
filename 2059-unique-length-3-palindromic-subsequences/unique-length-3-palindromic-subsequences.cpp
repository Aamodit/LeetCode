class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        // Record first and last occurrence of each character
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1)
                first[c] = i;
            last[c] = i;
        }

        int answer = 0;

        // For each character as the outer letter
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1 || last[c] == first[c])
                continue; // need at least two occurrences
            
            unordered_set<char> middle;

            // Count distinct middle chars between first and last
            for (int i = first[c] + 1; i < last[c]; i++) {
                middle.insert(s[i]);
            }

            answer += middle.size();
        }

        return answer;
    }
};
