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
    int sumOfLeftLeavesIter(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty()){
            TreeNode* node = queue.front();
            queue.pop();
            
            
            if(node->left){
                if( !node->left->left && !node->left->right)
                    res += node->left->val;
                else
                    queue.push(node->left);
            }
            
            if(node->right){
                if(node->right->left || node->right->right)
                    queue.push(node->right);
            }
            
       
        }
             return res;
    }
    
     int sumOfLeftLeaves(TreeNode* root) {
         if(!root) return 0;
         int ans = 0;
         if(root->left){
             if(!root->left->left && !root->left->right)
                ans += root->left->val;
            else
                ans += sumOfLeftLeaves(root->left);
         }
         
         if(root->right){
             if(root->right->left || root->right->right)
                ans+=sumOfLeftLeaves(root->right);
         }
         
        return ans;
         
     }
    
    
};