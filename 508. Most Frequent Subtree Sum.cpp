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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> countSum;
        int maxSumFreq = 0;
        
        getfrequencySum(root, countSum, maxSumFreq);
        
        vector<int> result;
        
        for(auto &it: countSum){
            if(it.second == maxSumFreq) result.push_back(it.first);
        }
        
        return result;
        
        
        
    }
    int getfrequencySum(TreeNode* root,unordered_map<int, int>& countSum,int & maxSumFreq ){
        if(!root) return 0;
        
        int sum = root->val;
        
        sum +=  getfrequencySum(root->left,countSum,maxSumFreq );
        sum +=  getfrequencySum(root->right,countSum,maxSumFreq );
        
        countSum[sum]++;
        
        maxSumFreq = max(maxSumFreq , countSum[sum]);
        
        return sum;
        
    }
};