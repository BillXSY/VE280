#include <iostream>
#include "Dlist.h"
using namespace std;

void DlistPrinter(Dlist<int> &l) {
    while (!l.isEmpty()) {
        cout << *l.removeFront() << ' ';
    }
    cout << endl;
}



int main(int argc, char *argv[])
{
    int result = 0;

    Dlist<int> ilist;
    ilist.removeAll();

    int *ip1 = new int(1);
    ilist.insertBack(ip1);
    int *ip2 = new int(2);
    ilist.insertBack(ip2);
    int *ip3 = new int(3);
    ilist.insertBack(ip3);

    int *ip4 = new int(4);
    ilist.insertBack(ip4);

//    ilist.removeAll();
    Dlist<int> ilist2(ilist);
//    int *ip5 = new int(5);
//    ilist2.insertBack(ip5);

    DlistPrinter(ilist);
    DlistPrinter(ilist2);


    return result;
}
