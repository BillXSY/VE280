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

BinaryTree::BinaryTree(Node *node) {
    this->root = node;
}

// TODO
BinaryTree::BinaryTree(const BinaryTree &tree) {
    this->root = new Node(tree.root->getVal(), tree.root->getLeft(), tree.root->getRight());


}

//TODO
BinaryTree::BinaryTree(std::vector<nodeValue> &source) {
    Node *n = new Node(0);
    this->root = n;
}

Node *BinaryTree::createFromVariant(const vector <nodeValue> &source, const int &rootIndex) {
    if (rootIndex >= source.size())
        return nullptr;
    auto rootValue = get_if<int>(&source[rootIndex]);
    if (!rootValue)
        return nullptr;
    int rightIndex = 2 * (rootIndex + 1);
    int leftIndex = rightIndex - 1;
    return new Node(*rootValue, createFromVariant(source, leftIndex), createFromVariant(source, rightIndex));
}