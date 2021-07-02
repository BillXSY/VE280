//
// Created by 71401 on 2021/6/9.
//

#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int main() {
    istringstream iStream;
    string in, out;
    int count = 0;
    getline(cin, in);
    for (size_t i = 0; i < in.length(); i++){
        if (in[i] == ','){
            in[i] = ' ';
        }
    }
    iStream.str(in);
    while (iStream >> out) {
        cout << out << endl;
        count++;
    }
    cout << count << endl;
    return 0;
}
