# include <iostream>
# include <string>
using namespace std;

typedef struct Node {
    int data;
    struct Node *left, *right;
} TreeNode;

// 建树
TreeNode *create(int i, int n) {
    if (i <= n) {
        TreeNode *p = new TreeNode{i};
        p->left = create(i * 2, n);
        p->right = create(i * 2 + 1, n);
        return p;
    }
    return nullptr;
}

// 先序遍历
void preOrder(TreeNode *p) {
    if (p) {
        cout << p->data;
        preOrder(p->left);
        preOrder(p->right);
    }
}

// 中序遍历
void InOrder(TreeNode *p) {
    if (p) {
        InOrder(p->left);
        cout << p->data;
        InOrder(p->right);
    }
}

// 后序遍历
void postOrder(TreeNode *p) {
    if (p) {
        postOrder(p->left);
        postOrder(p->right);
        cout << p->data;
    }
}

int main() {
    TreeNode *p = create(1, 8);

    preOrder(p);
    cout << endl;

    InOrder(p);
    cout << endl;

    postOrder(p);
    cout << endl;

    return 0;
}
