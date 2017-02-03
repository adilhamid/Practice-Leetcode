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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head) return head;
        
        ListNode* resultHead = new ListNode(0);
        resultHead->next = head;
        ListNode *iter = head;
        ListNode* prev = resultHead;

        while(iter){
            
             while(iter->next!=NULL && iter->val==iter->next->val){
                iter=iter->next;
            }

           if(prev->next==iter){
                prev=prev->next;
            }
            else{
                prev->next=iter->next;
            }
            iter=iter->next;
        }
        
        return resultHead->next;
        
    }
};