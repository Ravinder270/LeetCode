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
    bool findTarget(TreeNode* A, int B) {
         unordered_set<int> s;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        TreeNode *curr=q.front();
        if(s.find(B-curr->val)!=s.end())
        return true;
        s.insert(curr->val);
        q.pop();
        if(curr->left!=NULL)
        q.push(curr->left);
        if(curr->right!=NULL)
        q.push(curr->right);
       
    }
    return false;
    }
};