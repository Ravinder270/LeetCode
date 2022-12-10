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
   TreeNode* solve(vector<int>&nums,int s,int e){
        //base case :- 
        if(s>=e)return NULL;
        
        // as middle of the array will be the root node
        int middle = s+(e-s)/2;
        TreeNode * root = new TreeNode(nums[middle]);
        
        //left part from middle will be left subtree
        root->left = solve(nums,s,middle);
        
        //right part of array will be right subtree
        root->right = solve(nums,middle+1,e);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return solve(nums,0,nums.size());
    }
};