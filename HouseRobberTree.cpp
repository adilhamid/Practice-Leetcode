class Solution {
public:
    int rob(TreeNode* root) 
    {
        auto ret = postOrder(root);
        return max(ret.first, ret.second);
    }
private:
    pair<int, int> postOrder(TreeNode *node)
    {
        if (!node) return {0,0};
        auto left = postOrder(node->left);
        auto right = postOrder(node->right);
        
        pair<int, int> ret;
        ret.first = max(left.first, left.second) + max(right.first, right.second);
        ret.second = node->val + left.first + right.first;
        
        return ret;
    }
};