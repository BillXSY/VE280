//
// Created by 71401 on 2021/7/12.
//

#include <iostream>
#include <string>
#include <climits>

#include "node.h"

// REQUIRES: n of the child node is the same with n of this
// EFFECTS: add the node child to the children array
//          throw an exception tooManyChildren when child_num exceed n
void Node::addChild(Node *child) {
    // no space for new child
    if (child_num >= n) {
        delete child;
        throw tooManyChildren{};
    } else {
        children[child_num++] = child;
        child->parent = this;
    }
}

// EFFECTS: return true if the tree rooted at 'this' and the tree rooted at 'sub'
//          have the same shape and value.
bool Node::equal(Node *sub) {
    if (this->value != sub->value || this->child_num != sub->child_num) {
        return false;
    }
    for (int i = 0; i < child_num; ++i) {
        if (!this->children[i]->equal(sub->children[i])) return false;
    }
    return true;
}

// EFFECTS: create a root node with value and n
Node::Node(int _value, int _n) {
    this->value = _value;
    this->child_num = 0;
    this->n = _n;
    this->parent = NULL;
    this->children = new Node *[_n];
    this->height = 0;
}

// EFFECTS: destroy the whole tree rooted at sub
Node::~Node() {
    for (int i = 0; i < child_num; i++) {
        delete children[i];
    }
    delete[] children;
}

// EFFECTS: create a child node with value and add it to the children array
//          throw an exception tooManyChildren when child_num exceed n
void Node::addChild(int _value) {
    if (this->child_num >= this->n) {
        throw tooManyChildren{};
    }
    Node *child = new Node(_value, this->n);
    addChild(child);
}

// EFFECTS: insert the value of the nodes into traverseValue using a pre- order traversal,
void Node::traverse(vector<int> &traverseValue) {
    traverseValue.push_back(this->value);
    for (int i = 0; i < this->child_num; ++i) {
        this->children[i]->traverse(traverseValue);
    }
}

// EFFECTS: return whether the tree rooted at sub is a subtree of this
bool Node::contain(Node *sub) {
    if (this->getHeight() < sub->getHeight()) {
        return false;
    }
    if (this->getHeight() == sub->getHeight()) {
        return this->equal(sub);
    }
    for (int i = 0; i < this->child_num; ++i) {
        if (this->children[i]->contain(sub)) return true;
    }
    return false;
}

// EFFECTS: return height of this
int Node::getHeight() {
    if (!this->child_num) {
        return 0;
    }
    int max = -999;
    for (int i = 0; i < this->child_num; ++i) {
        int h = this->children[i]->getHeight();
        max = (max > h) ? max : h;
    }
    this->height = max + 1;
    return this->height;
}

// EFFECTS: return a reference of (i+1) th child node of this
Node &Node::operator[](int i) {
    if (i < 0 || i >= child_num) {
        throw invalidIndex{};
    } else {
        return *children[i];
    }
}