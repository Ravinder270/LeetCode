class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int curr=1;
       int cnt=0;
       int i=0;
        
       while(i<arr.size() && cnt<=k)
        {
           if(curr!=arr[i] && i<arr.size())
           {
               cnt++;
               
           }
           else
           {
               i++;
                
           }
           
           if(cnt==k)
           return curr;
           curr++;
        }
        return arr.size()+k;
    }
};


