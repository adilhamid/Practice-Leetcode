/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
private:
    ListNode* reverseLinkedList( ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* ahead;
        
        while(curr){
            ahead = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        return prev;
    }
    
    void printNodes(ListNode* head){
        ListNode* curr = head;
        while(curr){
            cout << curr->val<<" ";
            curr = curr->next;
        }
        cout <<endl;
        return;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        //Reversing both the Linked Lists so that the carry can be forwarded easily
        ListNode * rev1 = reverseLinkedList(l1);
        ListNode * rev2 = reverseLinkedList(l2);
        
        ListNode* newHead= nullptr, *iterNewHead=nullptr;
        ListNode* iterRev1 = rev1, *iterRev2 = rev2;
        int carry =0;
        
        while(iterRev1 && iterRev2){
            
            int newVal = iterRev1->val + iterRev2->val +carry;

            if(newVal >9){
                carry = newVal/10;
                newVal = newVal%10;
            }
            else{
                carry =0;
            }
            
            iterNewHead = new ListNode(newVal);
            iterNewHead->next = newHead;
            newHead = iterNewHead;
            
            iterRev1 = iterRev1->next;
            iterRev2 = iterRev2->next;
            
        }
        
        while(iterRev1){
            int newVal = iterRev1->val + carry;
          
            if(newVal >9){
                carry = newVal/10;
                newVal = newVal%10;
            }
            else{
                carry =0;
            }
            
            iterNewHead = new ListNode(newVal);
            iterNewHead->next = newHead;
            newHead = iterNewHead;
            
            iterRev1 = iterRev1->next;
        }
        
         while(iterRev2){
            int newVal = iterRev2->val + carry;
            if(newVal >9){
                carry = newVal/10;
                newVal = newVal%10;
            }
            else{
                carry =0;
            }
            iterNewHead = new ListNode(newVal);
            iterNewHead->next = newHead;
            newHead = iterNewHead;
            
            iterRev2 = iterRev2->next;
        }
        
        if(carry){
            iterNewHead = new ListNode(carry);
            iterNewHead->next = newHead;
            newHead = iterNewHead;
        }

        return newHead ;
        
    }
};