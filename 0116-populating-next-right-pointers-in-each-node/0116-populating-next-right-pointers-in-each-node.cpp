/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty()){
            int level_size = q.size();
            
            Node* prev = nullptr;
            
            while(level_size-- > 0){
                Node* cur = q.front(); q.pop();
                
                if(prev) prev->next = cur;
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                
                prev = cur;
            }
        }
        
        return root;
    }
};