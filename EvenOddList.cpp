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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        
        ListNode* iterOdd = head, *iterEven, *evenHead;
        
        iterEven = head->next;
        evenHead = head->next;
        
        while(iterEven && iterEven->next){
            
            iterOdd->next = iterOdd->next->next;
            
            iterEven->next = iterEven->next->next;
            
            iterEven = iterEven->next;
            iterOdd = iterOdd->next;
            
        }
        
        iterOdd->next = evenHead;
        
        return head;
        
    }
};