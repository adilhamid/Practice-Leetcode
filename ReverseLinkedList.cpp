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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        
        ListNode* prev =nullptr, *ahead, *curr = head;
        
        while(curr){
            ahead = curr->next;
            
            curr->next = prev;
            prev = curr;
            
            curr = ahead;
        }
        return prev;
    }
};