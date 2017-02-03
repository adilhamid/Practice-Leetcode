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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        if(!k) return head;
        
        int cnt=1;
        
        ListNode* curr = head;
        
        while(curr->next){
            cnt++;
            curr = curr->next;
        }
        curr->next = head;
        
        if(k %= cnt){
            for(int i=0; i<cnt-k; i++) curr = curr->next;
        }
        ListNode* newHead = curr->next;
        curr->next = NULL; 
        return newHead;
        
    }
};