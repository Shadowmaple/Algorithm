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

// 根据中序遍历和后序遍历构造二叉树
class Solution {
public:
    vector<int> inorder, postorder;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        return build(0, inorder.size()-1, 0, postorder.size()-1);
    }

    TreeNode* build(int inLeft, int inRight, int postLeft, int postRight) {
        if (inLeft > inRight) return nullptr;
        int key = postorder[postRight];
        int idx = inLeft;
        while (idx < inRight && inorder[idx] != key) {
            idx++;
        }
        int len = idx - inLeft;
        auto root = new TreeNode(key);
        root->left = build(inLeft, idx-1, postLeft, postLeft+len-1);
        root->right = build(idx+1, inRight, postLeft+len, postRight-1);
        return root;
    }
};