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
   bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        TreeNode* pre =NULL;
        return isValidBSTUtil(root, pre);
        
    }
    
   bool isValidBSTUtil(TreeNode* root, TreeNode* &prev){
       if(!root) return true;
       
       if(!isValidBSTUtil(root->left, prev)) return false;
       
       if(prev && (root->val <= prev->val)) return false;
       
       prev = root;
       
       return isValidBSTUtil(root->right, prev);
   }
};