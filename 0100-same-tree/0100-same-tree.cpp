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
    bool isSameTree(TreeNode* p, TreeNode* q) {
      //Step 1
		queue<TreeNode*> qu;  

		//Step 2
		qu.push(p);
		qu.push(q);

		//step 3
		while(qu.size() != 0){
			TreeNode* n1 = qu.front();
			qu.pop();
			TreeNode* n2 = qu.front();
			qu.pop();

			//meet the question conditions
			if(n1 == NULL && n2 == NULL) continue;
			if(n1 == NULL || n2 == NULL) return false;
			if(n1->val != n2->val) return false;

			qu.push(n1->left);
			qu.push(n2->left);
			qu.push(n1->right);
			qu.push(n2->right);

		}
		
		//Step 4
		return true;
    }
};