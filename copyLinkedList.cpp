/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
private: 
unordered_map<RandomListNode*, RandomListNode*> myHash;

public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        if(!head) return NULL;
        
        RandomListNode *curr = head, *ahead, *newHead ;
        
        //Changed A->B to A->A'->B->B'
       
        while(curr){
            ahead = curr->next;
            
            RandomListNode *copy = new RandomListNode(curr->label);
            copy->next = curr->next;
            curr->next = copy;
            
            curr = ahead;
        }
        
        
        // Now have to copy the random pointers of all the original nodes
        curr = head;
       
        newHead = head->next;
        
        
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        //Detaching the list from new list
        
        curr = head;
        
         while(curr){
              
              ahead = curr->next;
              curr->next = ahead->next;
              if (ahead->next != NULL) ahead->next = ahead->next->next;
              
              curr = curr->next;
              
         }
        
        return newHead;
        
        
    }

};