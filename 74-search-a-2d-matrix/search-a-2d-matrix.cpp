class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        for(int i=0;i<m.size();i++)
        {
            for(int j=0;j<m[i].size();j++)
            {
                if(m[i][j]==t)
                {
                    return true;
                }
            }
        }
        return false;
    }
};