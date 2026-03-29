class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int rs = 0, re = mat.size() - 1;
        int cs = 0, ce = mat[0].size() - 1;
        vector<int> ans;
        while (rs <= re && cs <= ce) {
            for (int i = cs; i <= ce; i++) {
                ans.push_back(mat[rs][i]);
            }
            rs++;
            for (int i = rs; i <= re; i++) {
                ans.push_back(mat[i][ce]);
            }
            ce--;
            if (rs <= re) {
                for (int i = ce; i >= cs; i--) {
                    ans.push_back(mat[re][i]);
                }
            }
            re--;
            if (cs <= ce) {
                for (int i = re; i >= rs; i--) {
                    ans.push_back(mat[i][cs]);
                }
            }
            cs++;
        }
        return ans;
    }
};