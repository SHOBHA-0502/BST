#include<bits/stdc++.h>
using namespace std;

// struct node* search(struct node * root , int key){
//     if(root == NULL || root->key == key){
//         return key ;
//     }
//     if(root->key > key){
//         return search(root->right ,  key);
//     }
//     if(root->key < key){
//         return search(root->left,  key)
//     }
// }
class bst {
    int data;
    bst *left, *right;
    public:
    bst();
    bst(int);
    bst*insert(bst*,int);
    void inorder(bst*);

};
bst*insert(bst*root ,int data){
    if(root == NULL){
        return new bst(data);
    }
    if(data>root->data){
        root->right = insert(root->right ,data);
    }
    else{
         root->left = insert(root->right ,data);
    }
    return root;
}

void inorder(bst*root){
    if(root == NULL){
        return NULL;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}