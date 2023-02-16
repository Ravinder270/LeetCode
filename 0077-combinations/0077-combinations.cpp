class Solution {
public:
void task(int i,int n,int k, vector<int>&ds,vector<vector<int>>&ans){
if(i>n)
{
    if(ds.size()!=k)return;
    ans.push_back(ds);
    return;
}


    //picking the element
    ds.push_back(i);
    task(i+1,n,k,ds,ans);
    ds.pop_back();
    
    
    //Non-pick
    task(i+1,n,k,ds,ans);
}
    

vector<vector<int>> combine(int n, int k){
    vector<vector<int>>ans;
    vector<int>ds;
    task(1,n,k,ds,ans);
    return ans;
}
};