class Solution {
public:
  bool isValid(vector<int> nums, int m,int k)
  {
      int c=1,p=0;
      for(int i=1;i<nums.size();i++)
      {
          if((nums[i]-nums[p])>=m)
          {
              p=i;
              c++;
          }
      }
      if(c>=k)
      {
          return  true;
      }
      return false;
  }
    int maxDistance(vector<int>& stalls, int k) {
         int l=1,r,m,ans=-1;
        sort(stalls.begin(), stalls.end());
        r=stalls[stalls.size()-1]-stalls[0];
        while(l<=r)
        {
            m=l+(r-l)/2;
            if(isValid(stalls,m,k))
            {
                ans=m;
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return ans;
    }
};