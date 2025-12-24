class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total_apples = 0, count = 0;
        int cap_sum = 0;
        int m = capacity.size();
        for (auto val : apple) {
            total_apples += val;
        }
        sort(capacity.begin(), capacity.end());
        for (int i = m - 1; i >= 0; i--) {
            cap_sum += capacity[i];
            count++;
            if (cap_sum >= total_apples) {
                return count;
            }
        }
        cout << total_apples;
        return 0;
    }
};