/*
    大体思路：二叉树后续遍历，是左-右-根，左边的树结点值小于根结点，根结点值小于右结点
    从向右遍历，一部分数据小于最后一个结点，而另一部分数据大于最后一个结点
    在两部分数据的交汇处，就是子树的根结点
    两个子树的区域：（left,sub_tree_root-1）（sub_tree_root, root）
*/
class Solution {
public:
    bool recurTrave(vector<int>& postorder, int left, int root) {
        if (left >= root) {
            return true;
        }

        int cur_node = left;
        while (postorder[cur_node] < postorder[root]) {
            cur_node++;
        }

        int sub_tree_root = cur_node;
        while (postorder[cur_node] > postorder[root]) {
            cur_node++;
        }

        return cur_node == root && recurTrave(postorder, left, sub_tree_root-1)
            && recurTrave(postorder, sub_tree_root, root-1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        return recurTrave(postorder, 0, postorder.size() - 1);
    }
};