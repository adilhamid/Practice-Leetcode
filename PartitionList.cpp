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
    ListNode* partition(ListNode* head, int x) {
    if(!head) return head;
        
    ListNode node1(0), node2(0);
    ListNode *left = &node1, *right = &node2;
    ListNode *iter = head;
    while (iter) {
        if (iter->val < x)
            left = left->next = iter;
        else
            right = right->next = iter;
        iter = iter->next;
    }
    right->next = NULL;
    left->next = node2.next;
    return node1.next;

        
    }
};