/**
* Definition for a binary tree node.
*/
#include"import.h"

using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (!root) return "";
		string result = "";

		queue<TreeNode*> mytree;
		mytree.push(root);

		while (!mytree.empty()) {

			TreeNode * temp = mytree.front();
			mytree.pop();

			if (temp != NULL) {
				result += to_string(temp->val) + ",";
			}
			else {
				result += "n,";
			}

			mytree.push(temp->left);
			mytree.push(temp->right);

		}
		//result.pop_back();
		cout << result << endl;
		return result;

	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		return NULL;
		//     if(data.empty()) return NULL;
		//     TreeNode * root;
		//     TreeNode* temp;
		//     vector<string> nodes;

		//     while(!data.empty()){
		//         auto first = data.find_first_of(",");
		//         nodes.push_back(data.substr(0,first-0));
		//         data.erase(0,first+1);
		//     }
		//     cout << atoi(nodes[0].c_str());
		//   // cout << root->val <<endl;
		//     return root;
	}
};



// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));