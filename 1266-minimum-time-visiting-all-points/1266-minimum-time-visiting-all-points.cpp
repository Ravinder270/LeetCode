class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& A) {
     
         int n=A.size();
 //       int m=A[0].size();
 int res=0;
 
for(int i=1;i<n;i++)
{
    
        res+=max(abs(A[i][0]-A[i-1][0]),abs(A[i][1]-A[i-1][1]));
}
 return res;
        
             
    }
};