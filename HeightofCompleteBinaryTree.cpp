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
    int countNodes312(TreeNode* root) {
        if(!root) return 0;
        
        int hr=0; int hl=0;
        
        TreeNode* left = root, *right = root;
        
        
        while(left){
            left = left->left;
            hl++;
        }
        
        while(right){
            right = right->right;
            hr++;
        }
        
        if( hl == hr) return pow(2,hl)-1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
    
  
    int countNodesRec(TreeNode* root) {
        if(!root) return 0;
        
        int hr=0; int hl=0;
        
        hl = getLeftHeight(root->left);
        hr = getLeftHeight(root->right);
        
        if(hl == hr) return pow(2,hl) + countNodes(root->right);
        
        return pow(2,hr)+countNodes(root->left);
        
        
    }
    
    int getLeftHeight(TreeNode* root){
        if(!root) return 0;
        
        int height=0;
        
        while(root){
            root =root->left;
            height++;
        }
        return height;
    }
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int num=1;
        TreeNode *curR(root->left), *curL(root->left);
        while(curR) // curR is the rightmost edge, which has a height equal to or less than the leftmost edge
        {
            curL = curL->left;
            curR = curR->right;
            num = num<<1;
        }
        return  num + ( (!curL)?countNodes(root->right):countNodes(root->left) );
    }
    
};