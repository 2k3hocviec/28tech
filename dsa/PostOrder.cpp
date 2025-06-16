#include <iostream>
using namespace std;

struct node{
    int val;
    node *left;
    node *right;
};

node* makeNode(int a){
    node* p = new node;
    p->val = a;
    p->left = NULL;
    p->right = NULL;
    return p;
}
 
void PostOrder(node *root){
    if (root != NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->val <<" ";
    }
}

int main(){
    node* root = NULL;
    root = makeNode (1);
    root->left = makeNode(2);
    root->right = makeNode(3);
    root->left->left = makeNode(4);
    root->left->right = makeNode(5);
    root->right->left = makeNode(7);
    root->right->right = makeNode(8);
    root->left->left->left = makeNode(9);
    root->left->left->right = makeNode(10);
    root->right->left->left = makeNode(11);
    root->right->right->left = makeNode(12);
    root->right->right->right = makeNode(13);
    PostOrder(root);
    return 0;
}