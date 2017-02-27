/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        myqueue.push(NULL);
        vector<int> result;
        
        int prevVal;
        
        while(!myqueue.empty()){
            TreeNode* temp  = myqueue.front();
            myqueue.pop();
            if(myqueue.empty() || !temp){
                result.push_back(prevVal);
                if(myqueue.size()>0)
                    myqueue.push(NULL);
            }
            else{
                prevVal = temp->val;
                if(temp->left) myqueue.push(temp->left);
                if(temp->right) myqueue.push(temp->right);
            }
                
        }
        
        return result;
        
    }
};