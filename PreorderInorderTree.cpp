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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return NULL;
        
        stack<TreeNode*> Tree;
        TreeNode* root, *temp;
        
        root = new TreeNode(preorder.front());
        preorder.erase(preorder.begin());
        Tree.push(root);
        
        while(!preorder.empty()){
            
            if(inorder.front() == Tree.top()->val){
                
                temp = Tree.top();
                Tree.pop();
                inorder.erase(inorder.begin());
                
                if(inorder.empty()) break;
                
                if(!Tree.empty() && inorder.front() == Tree.top()->val)
                    continue;
                
                temp->right = new TreeNode(preorder.front());
                 preorder.erase(preorder.begin());
                Tree.push(temp->right);
                
            }
            
            else{
                temp = new TreeNode(preorder.front());
                preorder.erase(preorder.begin());
                Tree.top()->left = temp;
                Tree.push(temp);
                
            }
            
           
        }
         return root;
        
    }
};