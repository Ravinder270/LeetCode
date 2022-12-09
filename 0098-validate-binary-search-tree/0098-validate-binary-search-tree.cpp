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
   bool inorder(TreeNode* root,long long& last)
   {
       if(root==NULL)return true;
       
       if(inorder(root->left,last)==false)return false;
       
       if(root->val <=last)return false;
       
       last=root->val;
       
       if(inorder(root->right,last)==false)return false;
       
       return true;
       
   }
       
    
   bool isValidBST(TreeNode* root)
   {
       
       long long last=LLONG_MIN;
       return inorder(root,last);
   }
};