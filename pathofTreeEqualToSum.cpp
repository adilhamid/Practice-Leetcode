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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        
        return helperFunc(root,0,sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
        
    }
    int count =0;
    
    int helperFunc(TreeNode* root,int pre, int& sum){
        if(!root) return 0;
        
        int newSum = pre + root->val;
        return (newSum == sum) + helperFunc(root->left ,  newSum, sum ) + helperFunc(root->right, newSum ,sum );
        
    }
};