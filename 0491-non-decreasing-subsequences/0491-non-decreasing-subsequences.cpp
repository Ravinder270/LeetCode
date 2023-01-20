class Solution {
public:
    vector<vector<int>>ans;
   vector<vector<int>> findSubsequences(vector<int>& nums){
    vector<int> temp;
    dfs(nums,temp,0);
       return ans;
    }
    
   void dfs(vector<int>&nums,vector<int>&temp,int index)
   {
       if(temp.size()>1)ans.push_back(temp);
       
       unordered_set<int>s;
       for(int i=index;i<nums.size();i++)
       {
           if((temp.size()==0 || temp.back()<=nums[i]) && (s.find(nums[i])==s.end()))
           {
               temp.push_back(nums[i]);
               dfs(nums,temp,i+1);
               temp.pop_back();
               s.insert(nums[i]);
           }
       }
       
       
   }
    
};