/*
 * This is an exercise of VE280 Lab 1, SU2020.
 * Written by Martin Ma.
 * Latest Update: 5/10/2020.
 * Copyright © 2020 Mars-tin. All rights reserved.
 */

#include <iostream>
#include <cstring>
using namespace std;


// EFFECTS: return true if the password is a valid one
bool isValidPassword(char password[]){
    bool is_alpahbetic = false;
    bool is_numerical = false;
    bool is_non_alpahbetic = false;
    if (strlen(password) > 50) {
      std::cout << "your password is too long" << '\n';
        return false;
    }
    for (int i = 0; i < strlen(password); ++i) {
       std::cout << password[i] << ' ';
        if ((password[i] >= 65 && password[i] <= 90) || (password[i] >= 97 && password[i] <= 122)) {
            is_alpahbetic = true;
           std::cout << "is_alpahbetic" << '\n';
        }
        else if (password[i] >= 48 && password[i] <= 57) {
            is_numerical = true;
           std::cout << "is_numerical" << '\n';
        }
        else {
            is_non_alpahbetic = true;
           std::cout << "is_non_alpahbetic" << '\n';
        }
    }
    return is_alpahbetic && is_non_alpahbetic & is_numerical;
}






int main(){
    char password[50] = {};

   cin >> password;
   cout << isValidPassword(password) << endl;
    // char m[] = "a\0";
    // cout << "size of m is " << sizeof(m) << endl;
}
