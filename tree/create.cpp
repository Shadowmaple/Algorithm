# include <iostream>
# include <string>
using namespace std;

typedef struct Node {
    char data;
    struct Node *left, *right;
} TreeNode;

// TreeNode *create(string s, int i) {
//     if (s.length() <= i || s.at(i) == '#')
//         return nullptr;
//     else {
//         TreeNode *p = new TreeNode{s[i]};
//         p->left = create(s, i*2);
//         p->right = create(s, i*2+1);
//     }
// }

TreeNode *create() {
    char c;
    cin >> c;
    if (c == '#')
        return nullptr;
    else {
        TreeNode *p = new TreeNode{c};
        p->left = create();
        p->right = create();
    }
}

// 先序遍历
void preOrder(TreeNode *p) {
    if (!p)
        cout << '#';
    else {
        cout << p->data;
        preOrder(p->left);
        preOrder(p->right);
    }
}

int main() {
    // char s[] = "ABC##DE#G##F###";
    // TreeNode *p = create(s, 0);
    TreeNode *p = create();

    preOrder(p);
    cout << endl;

    return 0;
}