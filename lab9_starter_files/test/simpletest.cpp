//
// Created by cyx on 20-6-12.
//

#include <iostream>
#include "mylist.h"

int main() {

    try{
        List<int> la, lb;
        la.insertBack(5);
        la.insertBack(4);
        la.insertBack(1);
        la.insertBack(3); // a = 3145

        lb.insertBack(2);
        lb.insertBack(4);
        lb.insertBack(1);
        lb.insertBack(3);
        lb.removeFront(); // b = 314

        std::cout << isLarger(la, lb) << '\n';

        List<int> ab_sum(la);
        ab_sum.print();
        ab_sum = add(la, lb);
        ab_sum.print();

        List<bool> lc;
        lc.insertBack(true);
        lc.insertBack(false);
        lc.insertBack(true);

        List<bool> ld(lc);
        ld.removeFront();
        ld.print();
    }
    catch(emptyList){
        std::cout << "Remove from empty list!\n";
    }

    return 0;
}

