/*
序列化：给一颗树，将树的结点放入到字符串中，空结点为 null
如 "1,2,3,null,null,4,5"
反序列化：将 "1,2,3,null,null,4,5" 字符串转化成一棵树
*/

class Codec {

public:
    void preOrder(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "null,";
        }
        else {
            s += to_string(root->val) + ',';
            preOrder(root->left, s);
            preOrder(root->right, s);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        preOrder(root, data);
        return data;
    }

    TreeNode* preOrderDecode(list<string> &data) {
        if (data.front() == "null") {
            data.erase(data.begin());
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(data.front()));
        data.erase(data.begin());
        node->left = preOrderDecode(data);
        node->right = preOrderDecode(data);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> data_array;
        string str;
        for (auto& ch : data) {
            if (ch == ',') {
                data_array.push_back(str);
                str.clear();
            }
            else {
                str.push_back(ch);
            }
        }

        if (!str.empty()) {
            data_array.push_back(str);
        }
        
        return preOrderDecode(data_array);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));