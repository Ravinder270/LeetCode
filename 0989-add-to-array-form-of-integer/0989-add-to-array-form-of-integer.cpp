class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int k) {
     vector<int>ans;
     int i=A.size()-1;
     int carry=0;
     while(i>=0 || k!=0 || carry!=0)
     {
         if(k!=0)
         {
             carry+=k%10;
             k=k/10;
         }
         if(i>=0)
         {
             carry+=A[i];
             i--;
         }
         ans.push_back(carry%10);
         carry=carry/10;
     }
       reverse(ans.begin(),ans.end());
      return ans;  
   
    }
};