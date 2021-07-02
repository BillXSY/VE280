#include "ex1.h"

int dot(list_t v1, list_t v2) {
    // TODO: implement dot function
    int rslt = 0;
    while (!list_isEmpty(v1) && !list_isEmpty(v2)) {
        rslt += list_first(v1) * list_first(v2);
        v1 = list_rest(v1);
        v2 = list_rest(v2);
    }
    return rslt;
}


list_t filter_odd(list_t list) {
    // TODO: implement filter_odd function
    list_t temp = list_make();
    while (!list_isEmpty(list)) {
        int num = list_first(list);
        if (num % 2 != 0) {
            temp = list_make(num, temp);
        }
        list = list_rest(list);
    }
    list_t rslt = list_make();
    while (!list_isEmpty(temp)) {
        int num = list_first(temp);
        rslt = list_make(num, rslt);
        temp = list_rest(temp);
    }
    return rslt;
}

list_t filter(list_t list, bool (*fn)(int)) {
    // TODO: implement filter function
    list_t temp = list_make();
    while (!list_isEmpty(list)) {
        int num = list_first(list);
        if (fn(num)) {
            temp = list_make(num, temp);
        }
        list = list_rest(list);
    }
    list_t rslt = list_make();
    while (!list_isEmpty(temp)) {
        int num = list_first(temp);
        rslt = list_make(num, rslt);
        temp = list_rest(temp);
    }
    return rslt;
}

