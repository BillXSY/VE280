//
// Created by Bill on 12/7/2021.
//

#include "constant.h"
#include "node.h"

#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;

int main() {
    vector<int> traverseValue;
    Node root(0);
    root.addChild(1);
    root.addChild(3);
    root[0].addChild(2);
    root[1].addChild(4);
    root[1][0].addChild(5);
    root[1][0].addChild(7);
    root[1][0][0].addChild(6);
    root[1][0][1].addChild(8);
    root[1][0][1].addChild(9);
    root[1][0][1][1].addChild(10);

    root.traverse(traverseValue);

    for (int i : traverseValue) {
        cout << storyProcess[i] << endl;
    }

    return 0;
}
