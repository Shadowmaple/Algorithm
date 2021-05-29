# include <iostream>
# include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 根据前序遍历和中序遍历构造二叉树
class Solution {
public:
    vector<int> preorder, inorder;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        return build(0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* build(int preLeft, int preRight, int inLeft, int inRight) {
        if (preLeft > preRight) return nullptr;
        int key = preorder[preLeft];
        int idx = inLeft;
        while (idx <= inRight && inorder[idx] != key) {
            idx++;
        }
        int len = idx - inLeft;
        auto root = new TreeNode(key);
        root->left = build(preLeft+1, preLeft+len, inLeft, idx-1);
        root->right = build(preLeft+len+1, preRight, idx+1, inRight);
        return root;
    }
};
