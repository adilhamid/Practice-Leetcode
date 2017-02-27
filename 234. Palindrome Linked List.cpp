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
    ListNode* reverseLinkedList( ListNode* iter){
        ListNode *prev = nullptr, *next;
        while(iter){
            next =iter->next;
            
            iter->next = prev;
            prev = iter;
            
            iter = next;
        }
        
        return prev;
    }
  
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        
        ListNode* slow, *fast;
        slow = fast = head;
        
        while(fast->next && fast->next->next){
            slow= slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverseLinkedList(slow->next);
        
        slow = slow->next;
        
        while(slow){
            if(slow->val != head->val) return false;
            head = head->next;
            slow = slow->next;
        }
        
        return true;
        
      
      
        
    }
};