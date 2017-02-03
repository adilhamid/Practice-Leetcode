#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
	int maxDepthIter(TreeNode *root) {
		if (root == NULL) return 0;

		deque <TreeNode*> treeDeque;
		queue<TreeNode*> treeQueue;

		treeQueue.push(root);
		treeDeque.push_back(root);

		int height = 0;


		while (true) {
			int nodeCount = treeDeque.size();
			if (nodeCount == 0)
				return height;
			++height;
			while (nodeCount-- > 0) {
				TreeNode* node = treeDeque.front();
				treeDeque.pop_front();

				if (node->left != NULL)
					treeDeque.push_back(node->left);
				if (node->right != NULL)
					treeDeque.push_back(node->right);


			}
		}

	}

	int maxDepth(TreeNode *root) {
		if (root == NULL) return 0;

		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}

	int minDepth(TreeNode* root) {
		if (root == NULL) return 0;

		if (root->left == NULL) return 1 + minDepth(root->right);
		if (root->right == NULL) return 1 + minDepth(root->left);

		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}

	struct qItem {
		TreeNode * node;
		int depth;
	};

	int minDepthIter(TreeNode* root) {
		if (root == NULL) return 0;

		deque <qItem> treeDeque;

		treeDeque.push_back(qItem{ root,1 });

		while (!treeDeque.empty()) {

			TreeNode* node = treeDeque.front().node;
			int depth = treeDeque.front().depth;
			treeDeque.pop_front();

			if (node->left == NULL && node->right == NULL)
				return depth;

			if (node->left != NULL)
				treeDeque.push_back(qItem{ node->left,depth + 1 });
			if (node->right != NULL)
				treeDeque.push_back(qItem{ node->right, depth + 1 });
		}
		return 0;
	}

	vector<vector<int>> levelOrderIter(TreeNode* root) {

		if (root == NULL) return{};

		vector< vector<int> > result;

		deque<qItem> treeDeque;

		treeDeque.push_back({ root, 1 });

		int predepth = 1;
		vector<int> temp;

		while (!treeDeque.empty()) {

			TreeNode* node = treeDeque.front().node;
			int depth = treeDeque.front().depth;
			treeDeque.pop_front();

			if (depth == predepth) {
				temp.push_back(node->val);
			}
			else {
				if (!temp.empty()) {
					result.push_back(temp);
				}
				temp.clear();
				predepth = depth;
				temp.push_back(node->val);
			}


			if (node->left != NULL) {
				treeDeque.push_back({ node->left, depth + 1 });
			}
			if (node->right != NULL) {
				treeDeque.push_back({ node->right, depth + 1 });
			}

		}
		if (!temp.empty()) {
			result.push_back(temp);
		}
		return result;
	}

	vector<vector<int>> levelOrderShortIter(TreeNode* root) {
		if (root == NULL) return{};
		queue<TreeNode *> treeQueue;

		vector< vector<int> > result;
		vector<int> curr;

		treeQueue.push(root);
		treeQueue.push(NULL);

		while (!treeQueue.empty()) {
			TreeNode* node = treeQueue.front();
			treeQueue.pop();

			if (node == NULL) {
				result.push_back(curr);
				curr.resize(0);
				if (treeQueue.size() > 0)
					treeQueue.push(NULL);

			}
			else {
				curr.push_back(node->val);
				if (node->left != NULL) treeQueue.push(node->left);
				if (node->right != NULL) treeQueue.push(node->right);
			}
		}
		return result;

	}
	vector< vector<int>> result;
	void BuildVector(TreeNode * root, int depth) {

		if (root == NULL) return;
		if (result.size() == depth)
			result.push_back(vector<int>());

		result[depth].push_back(root->val);
		BuildVector(root->left, depth + 1);
		BuildVector(root->right, depth + 1);

	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		BuildVector(root, 0);
		return result;

	}

	TreeNode* invertTree_Recurse(TreeNode* root) {
		if (!root) return root;

		invertTree(root->left);
		invertTree(root->right);

		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;

		return root;

	}

	TreeNode* invertTree(TreeNode* root) {
		if (!root) return root;
		queue<TreeNode*> treequeue;

		treequeue.push(root);

		while (!treequeue.empty()) {
			TreeNode* node = treequeue.front();
			treequeue.pop();

			TreeNode *temp = node->left;
			node->left = node->right;
			node->right = temp;

			if (node->left) treequeue.push(node->left);
			if (node->right) treequeue.push(node->right);
		}
		return root;
	}

	//to get the tree path from root to leaf
	vector<string> binaryTreePaths(TreeNode* root) {

		if (!root) return{};

		vector<string> res;
		getLeafPathNodes(root, res, to_string(root->val));

		return res;
	}

	void getLeafPathNodes(TreeNode* root, vector<string> &res, string t) {

		if (root->left == NULL && root->right == NULL) {
			res.push_back(t);
			return;
		}

		if (root->left)  getLeafPathNodes(root->left, res, t + "->" + to_string(root->left->val));
		if (root->right) getLeafPathNodes(root->right, res, t + "->" + to_string(root->right->val));

		return;


	}

	// End

	//Valid BST 

	bool isValidBST(TreeNode* root) {
		if (!root) return true;

		TreeNode* pre = NULL;
		return isValidBSTUtil(root, pre);

	}

	//using the inorder traversal of the tree to check the BST validity
	bool isValidBSTUtil(TreeNode* root, TreeNode* &prev) {
		if (!root) return true;

		if (isValidBSTUtil(root->left, prev) == false) return false;

		if (prev && (root->val <= prev->val)) return false;

		prev = root;

		return isValidBSTUtil(root->right, prev);
	}
	//Valid BST
	//Inorder Iterative Traversal
	
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root) return{};

		vector<int> result;
		stack<TreeNode*> stack;

		while (true) {
			while (root) {
				stack.push(root);
				root = root->left;
			}
			if (stack.empty()) break;

			root = stack.top();
			stack.pop();
			result.push_back(root->val);
			root = root->right;

		}

		return result;


	}

	// Inorder Traversal Iterative

	// PreOrder Traversal
	vector<int> preorderTraversal(TreeNode* root) {

		if (!root) return{};

		vector<int> result;
		stack<TreeNode*> stack;

		while (true) {
			while (root) {
				result.push_back(root->val);
				stack.push(root);
				root = root->left;
			}

			if (stack.empty()) break;

			root = stack.top();
			stack.pop();
			root = root->right;
		}

		return result;

	}
	// End PreOrder Traversal

	// Post Order Traversal
	vector<int> postorderTraversal(TreeNode* root) {
		if (!root) return{};

		vector<int> res;

		stack<TreeNode*> st;

		while (true) {
			if (root) {
				st.push(root);
				if(root->left) root = root->left;
			}
			else {
				if (st.empty()) return res;

				else if (st.top()->right == NULL) {
					root = st.top();
					st.pop();
					res.push_back(root->val);
					if (root == st.top()->right)
					{
						res.push_back(st.top()->val);
						st.pop();
					}
				}
				if (!st.empty())
					if(st.top()->right) root = st.top()->right;
				else
					root = NULL;
			}
		}
		return res;
	}

	// End Post Order Traversal

	//Fast PostOrder Traversal
	vector<int> postorderTraversalFast(TreeNode* root) {
		stack<TreeNode*> nodeStack;
		vector<int> result;
		//base case
		if (root == NULL)
			return result;
		nodeStack.push(root);
		while (!nodeStack.empty())
		{
			TreeNode* node = nodeStack.top();
			result.push_back(node->val);
			nodeStack.pop();
			if (node->left)
				nodeStack.push(node->left);
			if (node->right)
				nodeStack.push(node->right);
		}
		reverse(result.begin(), result.end());
		return result;

	}

	// BST Iterator

	//
#include<map>

	


	//Length Of Longest Substring

	int lengthOfLongestSubstring(string s) {

		vector<int> DICT(256, -1);
		int maxLen = 0;
		int start = -1;
		int len = s.length();
		for (int i = 0; i<len; i++) {
			if (DICT[s[i]] > start)
				start = DICT[s[i]];
			DICT[s[i]] = i;
			maxLen = max(maxLen, i - start);
		}

		return maxLen;

	}
	//
};

int main() {
	Solution obj;
	cout << obj.lengthOfLongestSubstring("abcabcbb") << endl;
}