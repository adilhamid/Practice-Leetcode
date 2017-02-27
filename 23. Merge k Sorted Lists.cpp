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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        
        auto compare = [] (ListNode* &a, ListNode* &b) -> bool { return a->val > b->val; };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare) > myque(compare);
        
        for(auto val : lists){
            if(val) myque.push(val);
        }
        
        if(myque.empty()) return nullptr;
        
        ListNode* resultHead = myque.top();
        myque.pop();
        if(resultHead->next) myque.push(resultHead->next);
        
        ListNode* iter = resultHead;
        
        while(!myque.empty()){
            iter->next = myque.top();
            myque.pop();
            iter = iter->next;
            if(iter->next) myque.push(iter->next);
        }
        
        return resultHead;
        
    }
};