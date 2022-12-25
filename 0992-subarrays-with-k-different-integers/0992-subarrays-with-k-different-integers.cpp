class Solution {
public:
    int at_most(vector<int> A,int k){
    int n = A.size(),s = 0,ans = 0,j = 0,i = 0;
    unordered_map<int,int> mp;
    while(j < n){
        mp[A[j]]++;
        while(mp.size() > k){
            mp[A[i]]--;
            if(mp[A[i]] == 0) mp.erase(A[i]);
            i++;
        }
        ans += (j-i+1);
        j++;
    }
    return ans;
}
    int subarraysWithKDistinct(vector<int>&A, int B) {
         return at_most(A,B)-at_most(A,B-1);
    }
    
};