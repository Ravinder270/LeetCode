class Solution {
public:
    int maxScore(vector<int>& A, int B) {
        int n=A.size();
 int suff[n+1];
 suff[n]=0;
 suff[n-1]=A[n-1];
 for(int fill=n-2;fill>=0;fill--)
 {
     suff[fill]=A[fill]+suff[fill+1];
 }
 
 int prefix=0;
 int ans=suff[n-B];
 for(int i=0;i<B;i++)
 {
     prefix+=A[i];
     int suffsum=suff[n-B+i+1];
     ans=max(ans,prefix+suffsum);
 }
  return ans;
    }
};