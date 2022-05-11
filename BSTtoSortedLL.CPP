#include <iostream>
#include <queue>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
pair<Node<int>*, Node<int>*> constructLinkedListUtility(BinaryTreeNode<int>* root){

    if(root == NULL){

        pair<Node<int>*, Node<int>*> helper;
        helper.first = NULL;
        helper.second = NULL;
        return helper;
    }

    Node<int> *rootNode = new Node<int>(root -> data);
    pair<Node<int>*, Node<int>*> leftTree = constructLinkedListUtility(root -> left);
    pair<Node<int>*, Node<int>*> rightTree = constructLinkedListUtility(root -> right);
    pair<Node<int>*, Node<int>*> helper;
    if(leftTree.first != NULL && rightTree.first != NULL){

        leftTree.second -> next = rootNode;
        rootNode -> next = rightTree.first;
        helper.first = leftTree.first;
        helper.second = rightTree.second;
    }

    else if(leftTree.first == NULL && rightTree.first != NULL){

        rootNode -> next = rightTree.first;
        helper.first = rootNode;
        helper.second = rightTree.second;
    }

    else if(leftTree.first != NULL && rightTree.first == NULL){

        leftTree.second -> next = rootNode;
        helper.first = leftTree.first;
        helper.second = rootNode;
    }

    else{

        helper.first = rootNode;
        helper.second = rootNode;
    }
    return helper;
}

Node<int>*constructLinkedList(BinaryTreeNode<int>* root) {
	
    pair<Node<int>*, Node<int>*> helper = constructLinkedListUtility(root);
    return helper.first;
}


BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}