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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> result;
        queue<TreeNode*> queue;
        
        queue.push(root);
        queue.push(NULL);
        vector<int> tempRes;
        
        while(!queue.empty()){
            TreeNode* temp = queue.front();
            queue.pop();
            
            if(!temp){
                result.push_back(tempRes);
                tempRes.clear();
                queue.push(NULL);
            }
            else{
                tempRes.push_back(temp->val);
                if(temp->left) queue.push(temp->left);
                if(temp->right) queue.push(temp->right);
            }
            if(!temp and !queue.front() ) break;
        }
        return result;
        
    }
};