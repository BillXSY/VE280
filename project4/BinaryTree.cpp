#include "BinaryTree.h"
#include <iostream>
#include <vector>

using namespace std;

/* ================================== Node =================================== */
Node::Node(const int &val, Node *left, Node *right) {
    this->val = val;
    this->left = left;
    this->right = right;
}

int Node::getVal() const {
    return this->val;
}

void Node::setVal(const int &newVal) {
    this->val = newVal;
}

Node *Node::getLeft() const {
    return this->left;
}

void Node::setLeft(const int &newVal) {
    if (!this->left) {
        this->left->val = newVal;
        return;
    }
    Node *n = new Node(newVal);
    this->left = n;
}

Node *Node::getRight() const {
    return this->right;
}

void Node::setRight(const int &newVal) {
    if (!this->right) {
        this->right->val = newVal;
        return;
    }
    Node *n = new Node(newVal);
    this->right = n;
}


/* =============================== Binary Tree =============================== */
BinaryTree::BinaryTree(const int &rootValue) {
    Node *n = new Node(rootValue);
    this->root = n;
}

BinaryTree::BinaryTree(Node *_node) {
    this->root = _node;
}

void NodeDeepCopy(Node *srcNode, Node *tarNode) {
    if (!srcNode) {
        return;
    }
    tarNode->setVal(srcNode->getVal());
    if (!srcNode->getLeft()) {
        tarNode->setLeft(srcNode->getLeft()->getVal());
        NodeDeepCopy(srcNode->getLeft(), tarNode->getLeft());
    }
    if (!srcNode->getRight()) {
        tarNode->setRight(srcNode->getRight()->getVal());
        NodeDeepCopy(srcNode->getRight(), tarNode->getRight());
    }
}

BinaryTree::BinaryTree(const BinaryTree &tree) {
    this->root = new Node(1);
    NodeDeepCopy(tree.root, this->root);
}

//TODO
BinaryTree::BinaryTree(std::vector<nodeValue> &source) {
    Node *n = new Node(0);
    this->root = n;
}

void destructor_helper(Node *root) {
    if (root == nullptr) {
        return;
    }
    destructor_helper(root->getLeft());
    destructor_helper(root->getRight());
    delete root;
}

BinaryTree::~BinaryTree() {
    destructor_helper(this->root);
}

bool BinaryTree::empty() const {
    return this->root;
}

Node *BinaryTree::find(const int &key) const {
    return root;
}

std::string BinaryTree::findPath(const int &value) const {
    return "asdf";
}

Node *BinaryTree::visitThroughPath(const std::string &path) const {
    return root;
}

int sum_helper(Node *root) {
    if (root == nullptr) {
        return 0;
    } else {
        return root->getVal() + sum_helper(root->getLeft()) + sum_helper(root->getRight());
    }
}

int BinaryTree::sum() const {
    return sum_helper(root);
}

int BinaryTree::height() const {
    return -999;
}

void preorder_helper(Node *root) {
    if (root == nullptr) {
        return;
    } else {
        cout << root->getVal() << " ";
        preorder_helper(root->getLeft());
        preorder_helper(root->getRight());
    }
}

void BinaryTree::preOrder() const {
    preorder_helper(root);
    cout << endl;
}

void inorder_helper(Node *root) {
    // EFFECTS: the helper function of inorder_str
    if (root == nullptr) {
        return;
    } else {
        inorder_helper(root->getLeft());
        cout << root->getVal() << " ";
        inorder_helper(root->getRight());
    }
}

void BinaryTree::inOrder() const {
    inorder_helper(root);
    cout << endl;
}

void postorder_helper(Node* root) {
    if (root == nullptr) {
        return;
    }
    else {
        postorder_helper(root->getLeft());
        postorder_helper(root->getRight());
        cout << root->getVal() << " ";
    }
}
void BinaryTree::postOrder() const {
    postorder_helper(root);
    cout << endl;
}

int allPathSumGreater_helper(Node* root) {
    // EFFECTS: the helper function of allPathSumGreat, return the smallest sum
    if (root == nullptr) {
        return 0;
    }
    int answer;
    if (root->getLeft() == nullptr && root->getRight() == nullptr) {
        answer = 0;
    }
    else if (root->getLeft() != nullptr && root->getRight() == nullptr) {
        answer = allPathSumGreater_helper(root->getLeft());
    }
    else if (root->getLeft() == nullptr && root->getRight() != nullptr) {
        answer = allPathSumGreater_helper(root->getRight());
    }
    else {
        answer = min(allPathSumGreater_helper(root->getLeft()), allPathSumGreater_helper(root->getRight()));
    }
    return root->getVal() + answer;
}

bool BinaryTree::allPathSumGreater(const int &sum) const {
    int smallestsum = allPathSumGreater_helper(root);
    if (smallestsum > sum) {
        return true;
    }
    else {
        return false;
    }
}

bool BinaryTree::operator<(const BinaryTree &tree) const {
    return false;
}

bool BinaryTree::operator<<(const BinaryTree &tree) const {
    return false;
}

BinaryTree &BinaryTree::operator=(const BinaryTree &tree) {
    this->root = new Node(1);
    NodeDeepCopy(tree.root, this->root);
}


Node *BinaryTree::createFromVariant(const vector<nodeValue> &source, const int &rootIndex) {
    if (rootIndex >= source.size())
        return nullptr;
    auto rootValue = get_if<int>(&source[rootIndex]);
    if (!rootValue)
        return nullptr;
    int rightIndex = 2 * (rootIndex + 1);
    int leftIndex = rightIndex - 1;
    return new Node(*rootValue, createFromVariant(source, leftIndex), createFromVariant(source, rightIndex));
}