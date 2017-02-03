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

 bool isSymmetric(TreeNode* root) {
        
        if(!root) return true;
        
        queue<TreeNode*> queue;
        
        queue.push(root->left);
        queue.push(root->right);
        
        while(!queue.empty()){
            if(queue.size() % 2 != 0 ) return false;
         
            TreeNode* topLeft = queue.front();
            queue.pop();
            TreeNode* topRight = queue.front();
            queue.pop();
            
            if(!topLeft && !topRight)
                continue;
            
            if(!topLeft || !topRight)
                return false;
            
            if(topLeft->val != topRight->val) return false;
            
            
            queue.push(topLeft->left);
            queue.push(topRight->right);
            queue.push(topLeft->right);
            queue.push(topRight->left);
           
            
        }
        return true;
        
    }
    
    bool isSymmetricREC(TreeNode* root) {
        return !root || isSymm(root->left, root->right);
    }
    
    bool isSymm(TreeNode* left, TreeNode* right){
        if(!left && !right)
            return true;
        
        if(!left || !right)
            return false;
        
        return left->val == right->val && ( isSymm(left->left, right->right) && isSymm(left->right, right->left));
        
    }
    
    
};