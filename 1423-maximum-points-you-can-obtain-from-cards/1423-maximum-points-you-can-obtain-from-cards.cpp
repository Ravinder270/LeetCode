class Solution {
public:
    int maxScore(vector<int>& A, int k) {
       int n=A.size();
       int suff[n+1];
        suff[n]=0;
        suff[n-1]=A[n-1];
        //filling suffix array obviously from right
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=suff[i+1]+A[i];
        }
        
        int ans=suff[n-k];
        int prefix=0;
        for(int i=0;i<k;i++)
        {
            prefix=prefix + A[i];
            ans=max(ans,prefix+suff[n-k+(i+1)]);            
        }
        return ans;
    }
};