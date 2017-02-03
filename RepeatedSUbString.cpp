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
    int numRootToLeaf(TreeNode* root, int currSum){
        if(!root) return 0;
        if(!root->left && !root->right) return currSum*10+root->val;
        return numRootToLeaf(root->left , currSum*10 + root->val) + numRootToLeaf(root->right , currSum*10 + root->val)  ;
    }
    
    int suumNumbers(TreeNode* root) {
        if(!root) return 0;
       return numRootToLeaf(root, 0);
        
    }
    
    //Using STACk AND DFS
    
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int maxSum =0;
        
        stack<pair<TreeNode*, int>> S;
        S.push(make_pair(root, root->val));
        int res=0;
        
        while(!S.empty()){
            TreeNode* node = S.top().first;
            int sum = S.top().second;
            S.pop();
            
           
            
            if(!node->left && !node->right) {
                res +=sum;
                continue;
            }
            
            if(node->right)
                S.push(make_pair(node->right, sum*10 + node->right->val));
            if(node->left)
                S.push(make_pair(node->left, sum*10 + node->left->val));
            
        }
        
        return res;
    }
    
};