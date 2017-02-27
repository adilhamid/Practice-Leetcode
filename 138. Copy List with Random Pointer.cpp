/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return nullptr;
        
        RandomListNode* iter = head, *next;
        
         //Copying the whole List based on the next pointers
        while(iter){
            next = iter->next;
            RandomListNode* copy = new RandomListNode(iter->label);
            iter->next = copy;
            copy->next = next;
            iter = next;
        }
        
        //Copying the random pointers
        iter = head;
        while(iter){
            if(iter->random != NULL){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        
        //Detaching the list to get the new list
        RandomListNode* psuedoHead = new RandomListNode(0);
        RandomListNode* copyiter = psuedoHead;
        iter = head;
        
        while(iter){
            next = iter->next->next;
            
            // Restore copied List
            copyiter->next = iter->next;
            copyiter = copyiter->next;
            
            //Restore Original List
            iter->next = next;
            
            iter = next;
        }
        
        return psuedoHead->next;
        
    }
};