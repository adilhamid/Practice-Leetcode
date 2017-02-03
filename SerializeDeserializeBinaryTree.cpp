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
        if(!root) return "";
        
        string result="";
        
        queue<TreeNode*> mytree;
        mytree.push(root);
        TreeNode* temp; 
        while(!mytree.empty()){
            
            temp = mytree.front();
            mytree.pop();
            
            if(temp != NULL){
                result += to_string(temp->val) + ",";
            }
            else{
                 result += "n,";
            }
            
            if(temp){
                    mytree.push(temp->left);
                    mytree.push(temp->right);
            }
            
            
        }
        //result.pop_back();
        int startIndex =result.length();
        for(int i = result.length()-1; i>=0; i = i-2){
            if(result[i] == ',' && result[i-1] == 'n')
            {
                startIndex = i-1;
            }
            else{
                break;
            }
        }
        result = result.substr(0,startIndex);
        return result;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    
        if(data.empty()) return NULL;

        TreeNode * root;
        TreeNode* temp;
        vector<string> nodes;
       
        while(!data.empty()){
            auto first = data.find_first_of(",");
            nodes.push_back(data.substr(0,first-0));
            data.erase(0,first+1);
        }
        int cnt =0;
        int val = stoi(nodes[cnt++]);
        int LEN = nodes.size();
       
       // nodes.erase(nodes.begin());
        
        queue<TreeNode*> stk;
        root = new TreeNode(val);
        stk.push(root);
       TreeNode * Node;
        while(cnt < LEN){
           
             Node = stk.front();
            stk.pop();
        
            if(cnt < LEN){
                Node->left = nodes[cnt] == "n"?nullptr:new TreeNode(stoi(nodes[cnt]));
                cnt++;
                //nodes.erase(nodes.begin());
            }
            if(cnt < LEN){
                Node->right = nodes[cnt] == "n"? nullptr: new TreeNode(stoi(nodes[cnt]));
                cnt++;
                //nodes.erase(nodes.begin());
            }
            if(Node->left)
                stk.push(Node->left);
            if(Node->right)
                stk.push(Node->right);
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));