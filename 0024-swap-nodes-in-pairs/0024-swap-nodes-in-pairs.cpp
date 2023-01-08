/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* A) {
      ListNode* head=A;
    
    for(auto i=head;i!=NULL && i->next!=NULL;i=i->next->next)
    {
        swap(i->val,i->next->val);
    }
    
    return head;
      
    }
};