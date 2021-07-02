#include <iostream>
#include <limits.h>
#include "ex2.h"

using namespace std;


int fold (int count, int arr[], int (*fn) (int, int), int initial) {
    // EFFECTS: returns the result of the fold function
    // TODO: implement this function recursively
    if (count == 0) {
    	return initial;//base case
    }
    else { 
		return fn( arr[count-1], fold (count-1, arr, fn, initial));
    	
    }
}


int fn_add (int a, int b) {
    // TODO: implement this function such that fold(count, arr, fn_add, 0)
    // returns the sum of all the elements in arr
    return a+b;
    
}

bool isOdd(int a){
	if (a%2) return true;
	return false;
}
int fn_count_odd (int a, int n) {
    // TODO: implement this function such that fold(n,arr,fn_count_odd, 0)
    // returns the numebr of odd numbers in the array
    if (isOdd(a)) return n+1;
    else return n;
}



