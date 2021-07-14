#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

#include "BinaryTree.h"
#include "NodeInfo.h"

using namespace std;

int main(int argc, char *argv[]) {
    string filename = argv[2];
    string mode = argv[1];
    ifstream iFile(filename);
    if (!iFile) {
        cout << "file cannot be opened\n";
    }
    string line;
    getline(iFile, line);
//    cout << line << endl;
    auto *BT = new BinaryTree(0);
    int NodeNum = 0;

    // Compression
    if (mode == "-x") {
        string w;
        for (char c : line) {
            if (BT->visitThroughPath(w + c)) {
                w += c;
            } else {
//                cout << endl << w << " + " << c;
                Node *n = BT->visitThroughPath(w);
                if (c == '1') {
                    n->setRight(++NodeNum);
                    NodeInfo ni(n->getVal(), c);
                    std::cout << ni;
                } else if (c == '0') {
                    n->setLeft(++NodeNum);
                    NodeInfo ni(n->getVal(), c);
                    std::cout << ni;
                }
                w = "";
            }
        }
        Node *n = BT->visitThroughPath(w);
        NodeInfo ni(n->getVal(), '3');
        std::cout << ni;
    }

    // Decompression
    if (mode == "-d") {
        NodeInfo ni;
        istringstream iStream(line);
        while (iStream >> ni) {
            Node *n = BT->find(ni.node_index);
            if (ni.c == '1') {
                n->setRight(++NodeNum);
                std::cout << BT->findPath(n->getRight()->getVal());
            } else if (ni.c == '0') {
                n->setLeft(++NodeNum);
                std::cout << BT->findPath(n->getLeft()->getVal());
            } else {
                std::cout << BT->findPath(n->getVal());
            }
        }
    }

    delete BT;
    return 0;
}