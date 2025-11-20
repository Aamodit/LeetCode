class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        if (a[0] == b[0]) return a[1] > b[1]; // tie on start -> end DESC
            return a[0] < b[0];                  // start ASC
        }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), compare);

        vector<int> ans;
        int n = intervals.size();

            // initialize with last interval's leftmost two integers
        int last1 = intervals[n-1][0];
        int last2 = last1 + 1;
        ans.push_back(last1);
        ans.push_back(last2);

        for (int i = n - 2; i >= 0; --i) {
            int L = intervals[i][0];
            int R = intervals[i][1];

            // Case 1: both last1 and last2 inside -> nothing to do
            if (last1 >= L && last2 <= R) continue;

            // Case 2: exactly one inside -> add L
            if ((last1 >= L && last1 <= R) || (last2 >= L && last2 <= R)) {
                ans.push_back(L);
                last2 = last1;
                last1 = L;
            }
            // Case 3: none inside -> add L and L+1
            else {
                
                ans.push_back(L);
                ans.push_back(L + 1);
                last1 = L;
                last2 = L + 1;
            }
        }

        return (int)ans.size();
    }
};