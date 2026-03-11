class Solution {
public:
    int rev(int n) {
        int ans = 0;
        while (n > 0) {
            if (ans >= INT_MAX / 10 || ans <= INT_MIN / 10)
                return 0;
            ans = (ans * 10) + (n % 10);
            n = n / 10;
        }
        return ans;
    }

    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (rev(x) == x) {
            return true;
        }
        return false;
    }
};