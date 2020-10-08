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
        if (!root) return "#,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q = convert(data); 
        return util(q);
    }
    
    TreeNode* util(queue<string>& q)
    {
        if (q.front() == "#") {
            q.pop();
            return NULL;
        } else {
            
            string cur = q.front();
            q.pop();
            
            TreeNode* root = new TreeNode(stoi(cur));
            
            root->left = util(q);
            root->right = util(q);
            
            return root;
        }
        
        
    }
    
    queue<string> convert(string& data)
    {
        queue<string> q;
        string cur = "";
        for (int i=0;i<data.size();i++)
        {
            if (data[i] == ','){
                q.push(cur);
                cur = "";
            } else {
                cur.push_back(data[i]);
            }
        }
        
        return q;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
