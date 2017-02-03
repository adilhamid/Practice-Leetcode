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
private:
TreeNode* first = NULL;
TreeNode* second = NULL;
TreeNode* prev = new TreeNode(INT_MIN);

public:
    void recoverTree(TreeNode* root) {
        helperFunc(root);
        swap(first->val, second->val);
        return;
    }
    
    void helperFunc(TreeNode* root){
        if(!root) return;
        
        helperFunc(root->left);
        //
        if (first == NULL && prev->val >= root->val) {
            first = prev;
        }
    
        if (first != NULL && prev->val >= root->val) {
            second = root;
        }        
        prev = root;
        
        helperFunc(root->right);
    }
};