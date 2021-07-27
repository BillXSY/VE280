#include <iostream>
#include "Dlist.h"

using namespace std;

void DlistPrinter(Dlist<int> &l) {
    while (!l.isEmpty()) {
        cout << *l.removeFront() << ' ';
    }
    cout << endl;
}


int main(int argc, char *argv[]) {
    int result = 0;

    Dlist<int> ilist;
//    ilist.removeAll();

    int *ip1 = new int(3);
    ilist.insertBack(ip1);
    int *ip2 = new int(2);
    ilist.insertBack(ip2);
    int *ip3 = new int(1);
    ilist.insertBack(ip3);

    Dlist<int> ilist2(ilist);
//    std::cout << "\ncopy successfully\n";


    ilist2.removeFront();
    ilist2.removeBack();
    ilist2.removeBack();
    cout << (ilist2.isEmpty() ? "empty" : "not empty") << endl << endl;

    ilist.removeBack();
    ilist.removeFront();
    ilist.removeBack();
    cout << (ilist.isEmpty() ? "empty" : "not empty") << endl << endl;

    return result;

    int count = 0;
    while (!ilist.isEmpty()) {
        count++;
        ilist.removeBack();
    }
//    while (!ilist2.isEmpty()) {
//        count++;
//        ilist2.removeBack();
//    }
//    int *ip5 = new int(5);
//    ilist.insertFront(ip5);

//    cout << "size of ilist2: " << count;
    cout << ilist;
    cout << ilist2;

}
