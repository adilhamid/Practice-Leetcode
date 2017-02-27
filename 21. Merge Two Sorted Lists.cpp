/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* newHead = new ListNode(0);
        ListNode* iter = newHead;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                iter->next = l1;
                l1 = l1->next;
            }
            else{
                iter->next = l2;
                l2 = l2->next;
            }
            iter = iter->next;
        }
        
        if(l1) iter->next = l1;
        if(l2) iter->next = l2;
        
        iter = newHead;
        newHead = newHead->next;
        delete iter;
        return newHead;
    }
};