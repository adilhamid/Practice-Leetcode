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
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* curr= head, *ahead, *prev=nullptr;
        
        while(curr){
            ahead = curr->next;
            curr->next = prev;
            prev = curr;
            
            curr = ahead;
        }
        
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        
        ListNode* curr = head;
        int count=0;
        
        while(curr){
            count++;
            curr = curr->next;
        }
        
        int leftEnd = count/2;
        int rightEnd = count%2 == 0 ? leftEnd: leftEnd+1;
        
        curr = head;
        int cnt=0;
        while(curr && cnt <rightEnd){
            cnt++;
            curr= curr->next;
        }
        ListNode* rightEndNode = reverseLinkedList(curr);
        
        curr = head;
        ListNode* curr2 = rightEndNode;
        
        while(curr2){
            if(curr->val != curr2->val) return false;
            curr = curr->next;
            curr2 = curr2->next;
        }
        return true;
    }
};