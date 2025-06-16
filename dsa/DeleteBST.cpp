#include <iostream>

using namespace std;

string res = "root";
bool check = false;
struct node{
    int val;
    node *left;
    node *right;
};

node* makeNode(int a){
    node *Node = new node;
    Node->val = a;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

node* Insert_Node(node* root, int a){
    if (root == NULL){
        root = makeNode(a);
    }
    else {
        if (root->val > a) {
            root->left = Insert_Node(root->left, a);
        }
        else if (root->val < a){
            root->right = Insert_Node(root->right, a);
        }
    }
    return root;
}

node* minNode(node* root){
    while(root != NULL){
        root = root->left;
    }
    return root;
}

int main(){
    freopen("x.txt", "r", stdin);
    freopen("y.txt", "w", stdout);
    int n; 
    cin >> n;
    node *root = NULL;
    while(n--){
        int m; 
        cin >>m;
        root = Insert_Node(root, m);
    }
    return 0;
}