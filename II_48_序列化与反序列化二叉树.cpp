#include<string>
#include<list>
#include<iostream>
using namespace std;
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
/*
这道题的主要难点有两个：
1. 读懂题：什么叫序列化一棵树，以及反序列化
    + 序列化一颗树的意思是将一颗树的值转成字符串形式存储
    + 反序列化的意思是根据你序列化的字符串再转换成一棵树
    + 其中序列化成字符串的结构-也就是你如何将树结点的数据和他的子树结合起来由你自己决定
2. 如何进行序列化
    + 两个难点：
        1. 一个如何保存树节点的值-树中的值是int型，然后将树的所有值组合成string型
        2. 如何去记录树和他的孩子节点对应的关系
            1. 也就是发序列化的时候，你怎么知道它是否有子树，以及如果有子树，子树的值怎么的出来
*/

class Codec {
public:
    void rSerialize(TreeNode* root, string& str) {
        if (nullptr == root) {
            str += "Null,";
            return;
        }
        str += to_string(root->val) + ",";
        rSerialize(root->left, str);
        rSerialize(root->right, str);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string res;
       rSerialize(root, res);
       return res;
    }

    TreeNode* rDeserialize(list<string>& listData) {
        if (listData.front() == "Null") {
            listData.pop_front();
            return nullptr;   
        }
        
        TreeNode* root = new TreeNode(stoi(listData.front()));
        listData.pop_front();
        root->left = rDeserialize(listData);
        root->right = rDeserialize(listData);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> listString;
        string str;
        for (auto& ch : data) {
            
            if (ch == ',') {
                listString.push_back(str);
                str.clear(); 
            }
            else {
                str.push_back(ch);
            }
        }
        if (false == str.empty()) {
            listString.push_back(str);
        }
        return rDeserialize(listString); 
    }
}; 
class Codec_1 {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preOrder(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return preOrderCreateTree(data, index);
    }
private:
    TreeNode* preOrderCreateTree(string& s, int& index) {
        if (index > s.size()) {
            return nullptr;
        }

        char c = s[index];
        if (c == 'a') {
            return nullptr;
        }
        TreeNode* root = new TreeNode(c-'0');
        index++;
        root->left = preOrderCreateTree(s, index);
        index++;
        root->right = preOrderCreateTree(s, index);
        return root;
    }

    void preOrder(TreeNode* root, string &s) {
        if (root == NULL) {
            s.push_back(('a'));
            return;
        }

        char c = root->val + '0';
        s.push_back(c);

        preOrder(root->left, s);
        preOrder(root->right, s);
    }
};
// 1 2 a a 3 4 a a 5 a a
// 
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec c;
    string s = c.serialize(root);
    TreeNode* res = c.deserialize(s);
    return 0;
}