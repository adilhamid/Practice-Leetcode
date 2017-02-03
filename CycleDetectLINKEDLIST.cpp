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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        
        ListNode* slwPtr= head;

        ListNode* fastPtr= head;
        
       // ListNode* entry = head;
        
        while(fastPtr){
           
            slwPtr = slwPtr->next;
            if(!fastPtr->next) return NULL;
            fastPtr = fastPtr->next->next;
           
            if(slwPtr == fastPtr){
                slwPtr = head;
                while(slwPtr!=fastPtr){
                     slwPtr = slwPtr->next;
                     fastPtr= fastPtr->next;
            
                    }
                return fastPtr;
            }
        }
        
        return NULL;
        
    }
};