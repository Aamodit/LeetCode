class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        
        for (int x : nums) {
            st.push_back(x);
            
            // keep merging as long as last two are non-coprime
            while (st.size() >= 2) {
                int a = st[st.size() - 2];
                int b = st[st.size() - 1];
                int g = gcd(a, b);
                
                if (g == 1) break; // coprime, stop merging
                
                // merge into lcm
                long long lcm = 1LL * a / g * b;
                st.pop_back();
                st.pop_back();
                st.push_back((int)lcm);
            }
        }
        
        return st;
    }
};