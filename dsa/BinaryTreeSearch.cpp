#include <iostream>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

node* makeNode(int a) {
    node* Node = new node;
    Node->val = a;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

node* Insert_Node(node* root, int a) {
    if (root == NULL) {
        root = makeNode(a);
    } else {
        if (root->val > a) {
            root->left = Insert_Node(root->left, a);
        } else if (root->val < a) {
            root->right = Insert_Node(root->right, a);
        }
    }
    return root;
}

bool Search(node* root, int x) {
    if (root == NULL) return false;
    if (root->val == x) {
        return true;
    } else if (x < root->val) {
        return Search(root->left, x);
    } else {
        return Search(root->right, x);
    }
}

node* minNode(node* root) {
    while (root != NULL && root->left != NULL) root = root->left;
    return root;
}

node* Delete(node* root, int key) {
    if (root == NULL) return root;
    if (key < root->val) {
        root->left = Delete(root->left, key);
    } else if (key > root->val) {
        root->right = Delete(root->right, key);
    } else {
        if (root->left == NULL) {
            node* tmp = root->right;
            delete root;
            return tmp;
        } else if (root->right == NULL) {
            node* tmp = root->left;
            delete root;
            return tmp;
        } else {
            node* tmp = minNode(root->right);
            root->val = tmp->val;
            root->right = Delete(root->right, tmp->val);
        }
    }
    return root;
}

void PreOrder(node* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(node* root) {
    if (root == NULL) return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}

void PostOrder(node* root) {
    if (root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->val << " ";
}

void deleteTree(node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    node* root = NULL;
    while (n--) {
        int m;
        cin >> m;
        root = Insert_Node(root, m);
    }
    Delete(root,2);
    cout << "PreOrder Traversal: ";
    PreOrder(root);
    cout << endl;

    cout << "InOrder Traversal: ";
    InOrder(root);
    cout << endl;

    cout << "PostOrder Traversal: ";
    PostOrder(root);
    cout << endl;

    // Giải phóng bộ nhớ
    deleteTree(root);

    return 0;
}