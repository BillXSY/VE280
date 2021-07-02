#include <iostream>
#include <limits.h>
#include "ex1.h"

using namespace std;
// const int MAXSIZE = 10;

int fold (int count, int arr[], int (*fn) (int, int), int initial) {
    // EFFECTS: returns the result of the fold function
    // TODO: implement this function recursively
    if (count == 0) {
    	return initial;//base case
    }
    int temp = initial;
    for (int i = 0; i < count; ++i) {
        temp = fn(arr[i], temp);
    }
    return temp;
}

int fn_add (int a, int b) {
    // TODO: implement this function such that fold(count, arr, fn_add, 0)
    // returns the sum of all the elements in arr
    return a + b;
}

int fn_count_odd (int a, int n) {
    // TODO: implement this function such that fold(n,arr,fn_count_odd, 0)
    // returns the number of odd numbers in the array
    return (bool(a % 2) + n);
}


//int main() {
//    int count;
//    cin >> count;
//
//    int arr[MAXSIZE];
//    for (int i = 0; i < count; ++i) {
//        cin >> arr[i];
//    }
//
//    cout << fold(count, arr, fn_add, 0) << endl;
//    cout << fold(count, arr, fn_count_odd, 0) << endl;
//
//    return 0;
//}
