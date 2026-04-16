class Solution {
public:
    bool judgeCircle(string moves) {
        if (moves.length() & 1)
            return false;

        int x = 0, y = 0;

        unordered_map<char, pair<int, int>> dir = {
            {'U', {0, 1}},
            {'D', {0, -1}},
            {'L', {-1, 0}},
            {'R', {1, 0}},
        };

        for (char c : moves) {
            auto [dx, dy] = dir[c];
            x += dx;
            y += dy;
        }

        return x == 0 && y == 0;
    }
};