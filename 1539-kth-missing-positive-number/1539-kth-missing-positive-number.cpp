class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    int cnt=0;//for k
        int curr=1;
        int i=0;// for array
      while(cnt<k && i<arr.size())  
      {
          if(curr==arr[i])
          {
            i++;
          }
          else 
          {
             cnt++;
          }
          if(cnt==k)return curr;
          curr++;
      }
        return arr.size()+k;
    }
};


