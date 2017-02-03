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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
   
        if(inorder.empty() || postorder.empty()) return NULL;
        
        TreeNode* root;
        stack<TreeNode*> Tree;
        
        root= new TreeNode(postorder.back());
        Tree.push(root);
        postorder.pop_back();
        TreeNode * temp;
        
        while(!postorder.empty()){
            
            if(inorder.back() == Tree.top()->val){
                temp = Tree.top();
                Tree.pop();
                inorder.pop_back();
                if(inorder.empty()) break;
                
                if(!Tree.empty() && inorder.back() == Tree.top()->val)
                    continue;
                    
                temp->left = new TreeNode(postorder.back());
                postorder.pop_back();
                Tree.push(temp->left);
            }
            else{
                temp = new TreeNode(postorder.back());
                postorder.pop_back();
                Tree.top()->right = temp;
                Tree.push(temp);
            }
                
        }
        return root;
        
    }
};