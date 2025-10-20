class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (string op : operations) {
            if (op.find('+') != string::npos)
                X++;
            else
                X--;
        }
        return X;
    }
};
