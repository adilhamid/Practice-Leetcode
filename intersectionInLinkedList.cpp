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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA || !headB) return NULL;
        
         int lenA =0;
         int lenB =0;
         
         ListNode* currA = headA, *currB = headB;
         
         while(currA || currB){
             if(currA){
                 lenA++;
                 currA = currA->next;
             }
             
             if(currB){
                 lenB++;
                 currB = currB->next;
             }
         }
         currA= headA; currB = headB;
         
         if(lenA > lenB){
            int cnt = lenA-lenB;
            while(cnt>0){
                currA = currA->next;
                cnt--;
            }
         }
         else{
             int cnt = lenB-lenA;
             while(cnt>0){
                 currB = currB->next;
                 cnt--;
             }
         }
         
         while(currA && currB){
             if(currA->val == currB->val){
                 return currA;
             }
             currA = currA->next;
             currB = currB->next;
         }
         
         return NULL;
        
    }
};