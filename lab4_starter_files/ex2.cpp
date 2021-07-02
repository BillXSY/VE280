//
// Created by 71401 on 2021/6/9.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <climits>

using namespace std;

int main(int argc, char const *argv[]) {
    ifstream iFile(argv[1]);
    string line, best, name;
    double performance = INT_MAX, price;
    int num_bullet;
    while (getline(iFile, line)) {
        istringstream iStream;
        iStream.str(line);
        iStream >> name >> price >> num_bullet;
        if (performance > (price / num_bullet)) {
            performance = (price / num_bullet);
            best = line;
        }
    }
    cout << best << endl;
    return 0;
}
