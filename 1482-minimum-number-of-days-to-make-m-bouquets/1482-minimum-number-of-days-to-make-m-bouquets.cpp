class Solution {
public:
     int check(vector<int>& arr, int m, int k,int maxDay){
        int toPick = m;
        int i=0,j = 0,cnt=0;
        while(j < arr.size()){
            int window = j - i + 1;
            if(arr[j] <= maxDay){
                cnt++;
            }
            
            if(window == k){
                if(cnt == k){
                    toPick--;
                    cnt = 0;
                    i = j + 1;
                }else{
                    if(arr[i] <= maxDay){
                        cnt--;
                    }
                    i++;
                }
            }
            j++;
        }
        return toPick <= 0;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int lo = INT_MAX, hi = INT_MIN;
        for(int i : arr){
            lo = min(i,lo);
            hi = max(i,hi);
        }
        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(check(arr,m,k,mid)){
                hi = mid - 1;
                ans = mid;
            }else{
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};