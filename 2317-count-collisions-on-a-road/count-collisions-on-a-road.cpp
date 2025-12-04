class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int left = 0, right = n - 1;

        // Skip leading L's (they escape left)
        while (left < n && directions[left] == 'L')
            left++;

        // Skip trailing R's (they escape right)
        while (right >= 0 && directions[right] == 'R')
            right--;

        int collisions = 0;

        // Count all non-S inside the remaining segment
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S')
                collisions++;
        }

        return collisions;
    }
};
