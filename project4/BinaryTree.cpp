#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <algorithm>

#include "BinaryTree.h"

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
    if (this->left) {
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
    if (this->right) {
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
    if (!srcNode) return;
    tarNode->setVal(srcNode->getVal());
    if (srcNode->getLeft()) {
        tarNode->setLeft(srcNode->getLeft()->getVal());
        NodeDeepCopy(srcNode->getLeft(), tarNode->getLeft());
    }
    if (srcNode->getRight()) {
        tarNode->setRight(srcNode->getRight()->getVal());
        NodeDeepCopy(srcNode->getRight(), tarNode->getRight());
    }
}

BinaryTree::BinaryTree(const BinaryTree &tree) {
    this->root = new Node(1);
    NodeDeepCopy(tree.root, this->root);
}

BinaryTree::BinaryTree(std::vector<nodeValue> &source) {
    this->root = this->createFromVariant(source, 0);
}

void destructor_helper(Node *root) {
    if (!root) return;
    destructor_helper(root->getLeft());
    destructor_helper(root->getRight());
    delete root;
}

BinaryTree::~BinaryTree() {
    destructor_helper(this->root);
}

bool BinaryTree::empty() const {
    return !this->root;
}

Node *find_helper(Node *node, const int &key) {
    if (!node) return nullptr;
    if (node->getVal() == key) return node;
    Node *left = find_helper(node->getLeft(), key);
    if (left) return left;
    Node *right = find_helper(node->getRight(), key);
    if (right) return right;
    return nullptr;
}

Node *BinaryTree::find(const int &key) const {
    return find_helper(this->root, key);
}

string findPath_helper(Node *root, const int &value) {
    if (!root) return "-1";
    if (root->getVal() == value) return "";
    string left = findPath_helper(root->getLeft(), value);
    if (left != "-1") return "0" + left;
    string right = findPath_helper(root->getRight(), value);
    if (right != "-1") return "1" + right;
    return "-1";
}

std::string BinaryTree::findPath(const int &value) const {
    return findPath_helper(this->root, value);
}

Node *BinaryTree::visitThroughPath(const std::string &path) const {
    Node *currNode = this->root;
    for (char c : path) {
        if (c == '0' && currNode->getLeft()) {
            currNode = currNode->getLeft();
        } else if (c == '1' && currNode->getRight()) {
            currNode = currNode->getRight();
        } else return nullptr;
    }
    return currNode;
}

int sum_helper(Node *root) {
    if (!root) {
        return 0;
    } else {
        return root->getVal() + sum_helper(root->getLeft()) + sum_helper(root->getRight());
    }
}

int BinaryTree::sum() const {
    return sum_helper(root);
}

int height_helper(Node *root) {
    if (!root) {
        return 0;
    }
    int height = height_helper(root->getLeft());
    int temp = height_helper(root->getRight());
    height = (height > temp) ? height : temp;
    return height + 1;
}

int BinaryTree::height() const {
    return height_helper(this->root);
}

void preorder_helper(Node *root) {
    if (!root) {
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
    if (!root) {
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

void postorder_helper(Node *root) {
    if (!root) {
        return;
    } else {
        postorder_helper(root->getLeft());
        postorder_helper(root->getRight());
        cout << root->getVal() << " ";
    }
}

void BinaryTree::postOrder() const {
    postorder_helper(root);
    cout << endl;
}

int allPathSum(Node *node) {
    if (!node) return 0;
    int answer;
    if (!node->getLeft() && !node->getRight()) {
        answer = 0;
    } else if (node->getLeft() && !node->getRight()) {
        answer = allPathSum(node->getLeft());
    } else if (!node->getLeft() && node->getRight()) {
        answer = allPathSum(node->getRight());
    } else {
        answer = min(allPathSum(node->getLeft()), allPathSum(node->getRight()));
    }
    return node->getVal() + answer;
}

bool BinaryTree::allPathSumGreater(const int &sum) const {
    int smallestsum = allPathSum(root);
    return (smallestsum > sum);
}

bool covered_by_helper(Node *smallTree, Node *largeTree) {
    if (!smallTree) return true;
    if (largeTree && smallTree->getVal() == largeTree->getVal() &&
        covered_by_helper(smallTree->getLeft(), largeTree->getLeft()) &&
        covered_by_helper(smallTree->getRight(), largeTree->getRight())) {
        return true;
    }
    return false;
}

// EFFECTS: Return true if this is covered by {tree}
bool BinaryTree::operator<(const BinaryTree &tree) const {
    return covered_by_helper(this->root, tree.root);
}

bool contained_by_helper(Node *smallTree, Node *largeTree) {
    if (!smallTree) {
        return true;
    }
    if (largeTree) {
        return covered_by_helper(smallTree, largeTree) || contained_by_helper(smallTree, largeTree->getLeft()) ||
               contained_by_helper(smallTree, largeTree->getRight());
    }
    return false;
}

// EFFECTS: Return true if this is contained by {tree}
bool BinaryTree::operator<<(const BinaryTree &tree) const {
    return contained_by_helper(this->root, tree.root);
}

// EFFECTS: "=" overloading
BinaryTree &BinaryTree::operator=(const BinaryTree &tree) {
    NodeDeepCopy(tree.root, this->root);
    return *this;
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