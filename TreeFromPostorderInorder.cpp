#pragma once
#include "import.h"

using namespace std;



 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

		reverse(postorder.begin(), postorder.end());
		stack<TreeNode*> Tree;
		int lenPost = postorder.size();

		for (int i = 0; i< lenPost; i++) {
			TreeNode newNode = TreeNode(postorder[i]);
			TreeNode *root = &newNode;
			Tree.push(root);
			break;
		}
		return Tree.top();

	}
};

int main()
{
	return 0;
}