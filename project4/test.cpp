//
// Created by 吴佳遥 on 2021/7/7.
//
#include <iostream>
#include "BinaryTree.h"
#include <vector>

using namespace std;

void treeCheck(const BinaryTree &tree) {
    cout << tree.height() << endl;
    cout << tree.sum() << endl;
    cout << tree.empty() << endl;
    tree.preOrder();
    tree.inOrder();
    tree.postOrder();
}

void nodePrint(Node *x) {
    if (x == nullptr)
        cout << "nullptr" << endl;
    else
        cout << x->getVal() << endl;
}

int main() {
    vector<nodeValue> source = {4, 2, 5, 7, 3, "$", "@", "hey", "xm", 8, 9};
    BinaryTree tree(source);
    BinaryTree waste = tree;
    treeCheck(tree);

    Node *x = tree.find(9);
    x->setLeft(100);
    cout << tree.findPath(100) << endl;

    treeCheck(tree);
    treeCheck(waste);

    x = tree.visitThroughPath("0110");
    nodePrint(x);

    x = tree.visitThroughPath("001");
    nodePrint(x);

    x = tree.find(7);
    x->setRight(101);

    x = tree.visitThroughPath("001");
    nodePrint(x);
    treeCheck(waste);

    vector<nodeValue> coveredVec = {4, 2};
    vector<nodeValue> uncoveredVec = {4, 3};
    vector<nodeValue> coveredTargetVec = {4, 2, 5, "", 3};
    BinaryTree covered(coveredVec);
    BinaryTree uncovered(uncoveredVec);
    BinaryTree coveredTarget(coveredTargetVec);
    cout << (covered < coveredTarget) << endl;
    cout << (uncovered < coveredTarget) << endl;

    vector<nodeValue> containedVec = {3, 6, 7};
    vector<nodeValue> notContainedVec = {4, 2, 5, "", 3, 7, 8};
    vector<nodeValue> containedTargetVec = {4, 2, 5, "", 3, "", 8, "", "", 6, 7};
    BinaryTree contained(containedVec);
    BinaryTree notContained(notContainedVec);
    BinaryTree containedTarget(containedTargetVec);
    cout << (contained << containedTarget) << endl;
    cout << (notContained << containedTarget) << endl;

    vector<nodeValue> sumGreaterVec = {4, 1, 5, 3, 6};
    BinaryTree sumGreater(sumGreaterVec);
    cout << sumGreater.allPathSumGreater(9) << endl;
    cout << sumGreater.allPathSumGreater(7) << endl;
}
