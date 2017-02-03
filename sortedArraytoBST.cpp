

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if(!len) return NULL;
        return toBST(nums,0, len);
    }
    
    TreeNode* toBST(vector<int>& nums, int start, int end){
        if(start == end) return NULL;
        int mid = (start +end )/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = toBST(nums,start, mid);
        root->right = toBST(nums,mid+1, end);
        return root; 
    }
};