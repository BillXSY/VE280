#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct {
    // TODO: complete struct
    char name[16];
    int Combat;
    int Initiative;
    int Wits;
    int sum;
} Soldier;

int compare(const void* p1, const void* p2) {
    // TODO: complete compare function for qsort()
    return (*(Soldier *) p1).sum < (*(Soldier *) p2).sum;
}

int main() {
    // TODO: read input
    int n;
    Soldier soldier[10];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> soldier[i].name >> soldier[i].Combat >> soldier[i].Initiative >> soldier[i].Wits;
        soldier[i].sum = soldier[i].Combat + soldier[i].Initiative + soldier[i].Wits;
    }
    // TODO: sort array with qsort()
    qsort(soldier, n, sizeof(*soldier), compare);
    std::sort(soldier.begin(), soldier.end())
    // TODO: print result
    for (int i = 0; i < n; i++){
        cout << soldier[i].name << " " << soldier[i].Combat << " " << soldier[i].Initiative << " " << soldier[i].Wits << endl;
    }
    return 0;
}