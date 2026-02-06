class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int n = s2.size();

        if(k > n) return false;

        vector<int> f1(26,0), f2(26,0);

        // build first window
        for(int i=0;i<k;i++){
            f1[s1[i]-'a']++;
            f2[s2[i]-'a']++;
        }

        if(f1 == f2) return true;

        // slide
        for(int i=k;i<n;i++){
            f2[s2[i]-'a']++;        // add new
            f2[s2[i-k]-'a']--;      // remove old

            if(f1 == f2) return true;
        }

        return false;
    }
};
