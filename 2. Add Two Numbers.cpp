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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(!l1) return l2;
        if(!l2) return !l1?nullptr:l1;
        
        ListNode* Sum= new ListNode(0);
        ListNode* iter = Sum;
        int carry =0;
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            carry = sum/10;
        
                iter->next = new ListNode(sum%10);
                iter = iter->next;
                
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1){
            int sum = l1->val + carry;
            carry = sum/10;
            
                iter->next = new ListNode(sum%10);
                iter = iter->next;
            l1 = l1->next;
        }
        
       while(l2){
            int sum = l2->val + carry;
            carry = sum/10;
            
                iter->next = new ListNode(sum%10);
                iter = iter->next;
            l2 = l2->next;
        }
        if(carry>0){
            iter->next = new ListNode(carry);
            iter = iter->next;
        }
        
        return Sum->next;
    }
};