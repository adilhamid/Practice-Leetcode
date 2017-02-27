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
    int getLengthList(ListNode*head){
        int len =0;
        while(head){
            head = head->next;
            len++;
        }
        
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA || !headB) return nullptr;
        
        int lenA = getLengthList(headA);
        int lenB = getLengthList(headB);
        
        ListNode* iterA= headA, *iterB = headB;
        int diff = abs(lenA- lenB);
        if(lenA > lenB){
            while(diff--){
                iterA = iterA->next;
            }
        }
        else{
            while(diff--){
                iterB = iterB->next;
            }
        }
        while(iterA && iterB){
            if(iterA->val == iterB->val){
                return iterA;
            }
            iterA = iterA->next;
            iterB = iterB->next;
        }
        return nullptr;
    }
};