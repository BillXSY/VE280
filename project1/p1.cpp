#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

//request for input
void print_prompt() {
    std::cout << "Please enter the integer and the test number: ";
}

//Determine whether Armstrong number or not
bool is_Armstrong(int num){
    for (int i = 1; i < num; ++i) {
        int p = pow(i,num);
        if (p % num != i) {
            return false;
        }
    }
    return true;
}

//return total digits of a given number
int get_digit(int num){
    int count = 0;
    while (num) {
        num /= 10;
        count++;
    }
    return count;
}

//Determine whether Cyclone number or not
bool is_Cyclone(int x) {
    if (x < 0) {
        return false;
    }
    int digit = get_digit(x);

    while (x) {
        if (int(x/pow(10,digit-1)) != x%10) {
            return false;
        }
        x = x % int (pow(10,digit-1));
        x = x / 10;
        digit -= 2;
    }
    return true;
}

//Determine whether Black Premium number or not
bool is_Black_Premium(int x){
    double s = sqrt(24 * x + 1);
    const double EPS = 1e-6;
    return (s - (double)((int)s) < EPS) && (int)s % 6 == 5;
}

//Determine whether Auspicious number or not
bool is_Auspicious(int x){
    int sum = 0;
    for (int i = 1; i < x; ++i) {
        if (!(x % i)) sum += i;
    }
    if (sum > x) return true;
    return false;
}

int main() {
    int num = -1, test = -1;
    while (num <= 0 || num >= 10000000 || test <= 0 || test > 5) {
        print_prompt();
        std::cin >> num;
        std::cin >> test;
    }
    switch (test) {
        case 1:
            std::cout << is_Armstrong(num) << '\n';
            break;
        case 2:
            std::cout << is_Cyclone(num) << '\n';
            break;
        case 3:
            std::cout << is_Black_Premium(num) << '\n';
            break;
        case 4:
            std::cout << is_Auspicious(num) << '\n';
            break;
        default:
            std::cout << "lhrnb!"<< '\n';
    }
    return 0;
}