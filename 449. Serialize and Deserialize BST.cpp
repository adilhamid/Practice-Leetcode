/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

   // Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		// preorder traversal
		string ret;
		if(!root) return ret;
		
		stack<TreeNode*> stk;
		stk.push(root);
		while(!stk.empty()){
			TreeNode *r = stk.top();
			stk.pop();
			ret += to_string(r->val) + ",";
			if(r->right) stk.push(r->right);
			if(r->left) stk.push(r->left);

		}
		return ret.substr(0, ret.size()-1);
	}

	// Decodes your encoded data to tre.
	TreeNode* deserialize(string data) {
	    if(data.size() == 0) return nullptr;
	    
		int id = 0;
		// take root at first
		int r = id;
		while(isdigit(data[r])) r++;
		int v = stoi(data.substr(id, r-id));
		id = r+1;

		TreeNode *root = new TreeNode(v);
		stack<TreeNode*> stk;
		stk.push(root);

		while(id < (int) data.size()) {
			int r = id;
			while(isdigit(data[r]))	r++;
			int v = stoi(data.substr(id, r - id));
			id = r + 1;

			TreeNode *node = nullptr;
			while(!stk.empty() && v > stk.top()->val) {
				node = stk.top();
				stk.pop();
			}
			if(node) {
				node->right = new TreeNode(v);
				stk.push(node->right);
			} else {
				stk.top()->left = new TreeNode(v);
				stk.push(stk.top()->left);
			}
		}

		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));