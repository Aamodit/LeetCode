class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> N;
    int n;
    void s(int i, int t) {
        if (t == 0) {
            ans.push_back(path);
            return;
        }
        if (t < 0 || i >= n) {
            return;
        }
        path.push_back(N[i]);
        s(i, t - N[i]);
        path.pop_back();
        s(i + 1, t);
    }
    vector<vector<int>> combinationSum(vector<int>& Nums, int t) {
        N = Nums;
        n = Nums.size();
        s(0, t);
        return ans;
    }
};