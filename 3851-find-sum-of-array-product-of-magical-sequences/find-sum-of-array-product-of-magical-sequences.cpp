using int64 = long long;
const int64 MOD = 1000000007;

int64 modpow(int64 a, int64 e){
    int64 r = 1 % MOD;
    a %= MOD;
    while(e){
        if(e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int64 inv(int64 x){ return modpow((x%MOD+MOD)%MOD, MOD-2); }

class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = (int)nums.size();
        // number of bit positions to process (indices + room for carries)
        int maxPos = n + 31; // safe because m <= 30

        // factorials and inverse factorials up to m
        vector<int64> fact(m+1,0), invFact(m+1,0);
        fact[0] = 1;
        for(int i=1;i<=m;++i) fact[i] = fact[i-1] * i % MOD;
        invFact[m] = inv(fact[m]);
        for(int i=m-1;i>=0;--i) invFact[i] = invFact[i+1] * (i+1) % MOD;

        // powNums[i][c] = nums[i]^c % MOD for c=0..m
        vector<vector<int64>> powNums(n, vector<int64>(m+1, 1));
        for(int i=0;i<n;++i){
            int64 base = nums[i] % MOD;
            for(int c=1;c<=m;++c) powNums[i][c] = powNums[i][c-1] * base % MOD;
        }

        int D = m + 1;
        // Flattened 3D arrays: carry (0..m), ones (0..m), used (0..m)
        int layerSize = D * D * D;
        vector<int64> cur(layerSize, 0), nxt(layerSize, 0);

        auto idx = [&](int carry, int ones, int used){
            return (carry * D + ones) * D + used;
        };

        cur[idx(0,0,0)] = 1;

        for(int pos = 0; pos < maxPos; ++pos){
            fill(nxt.begin(), nxt.end(), 0);
            bool hasIndex = (pos < n);

            for(int carry = 0; carry <= m; ++carry){
                for(int ones = 0; ones <= m; ++ones){
                    for(int used = 0; used <= m; ++used){
                        int64 val = cur[idx(carry, ones, used)];
                        if(val == 0) continue;
                        if(hasIndex){
                            // choose c copies of index=pos, but cannot exceed remaining (m - used)
                            int maxC = m - used;
                            for(int c = 0; c <= maxC; ++c){
                                int tot = carry + c;
                                int bit = tot & 1;
                                int newOnes = ones + bit;
                                if(newOnes > m) continue;
                                int newCarry = tot >> 1;
                                if(newCarry > m) continue;
                                int newUsed = used + c;
                                // multiply by nums[pos]^c and divide by c! (accumulate invFact[c])
                                int64 mult = powNums[pos][c] * invFact[c] % MOD;
                                int64 add = val * mult % MOD;
                                int id = idx(newCarry, newOnes, newUsed);
                                nxt[id] += add;
                                if(nxt[id] >= MOD) nxt[id] -= MOD;
                            }
                        } else {
                            // no index here; must pick c = 0
                            int tot = carry;
                            int bit = tot & 1;
                            int newOnes = ones + bit;
                            if(newOnes > m) continue;
                            int newCarry = tot >> 1;
                            if(newCarry > m) continue;
                            int newUsed = used;
                            int id = idx(newCarry, newOnes, newUsed);
                            nxt[id] += val;
                            if(nxt[id] >= MOD) nxt[id] -= MOD;
                        }
                    }
                }
            }
            cur.swap(nxt);
        }

        int64 ans = cur[idx(0, k, m)]; // need carry==0, ones==k, used==m
        // multiply by m! to account for permutations (we accumulated 1/prod cnt! factors)
        ans = ans * fact[m] % MOD;
        return (int)ans;
    }
};