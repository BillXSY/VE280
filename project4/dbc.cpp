#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "BinaryTree.h"
#include "NodeInfo.h"

using namespace std;

int main(int argc, char *argv[]) {
    // TODO: implement your dbc program here!
    string filename = argv[2];
    cout << "filename: " << filename << endl;
    string mode = argv[1];
    if (mode == "-x") {
        cout << "loading file...\n";
        ifstream iFile("./" + filename);
        if (!iFile) {
            cout << "file cannot be opened\n";
        }
        string line;
        getline(iFile, line);
        cout << line;
    }
    BinaryTree *BT = new BinaryTree(0);

    return 0;
}