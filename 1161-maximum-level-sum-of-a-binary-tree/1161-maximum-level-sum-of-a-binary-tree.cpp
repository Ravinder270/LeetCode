/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>sum;
    
    void dfs(TreeNode* root, size_t level)
    {
        if(root!=nullptr)
        {
            sum.resize(max(sum.size(),level));
            sum[level-1]+=root->val;
            dfs(root->left,level+1);
            dfs(root->right,level+1);
        }
    }
    
    int maxLevelSum(TreeNode* root){
        dfs(root,1);
        return distance(sum.begin(),max_element(sum.begin(),sum.end()))+1;
        
    }
  
};