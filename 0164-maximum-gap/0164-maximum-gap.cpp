class Solution {
public:
    int maximumGap(vector<int>& A) {
     
    if(A.size()<2)return 0;
    
    sort(A.begin(),A.end());
    
    int maxm=INT_MIN;
    for(int i=1;i<A.size();i++)
    {
        maxm=max(maxm,A[i]-A[i-1]);
    }
    return maxm;
    }
};