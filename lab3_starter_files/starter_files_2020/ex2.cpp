#include <iostream>
#include <vector>

using namespace std;

const int MAXSIZE = 10;

bool canWin_helper(vector<int> &is_Visited, int position, vector<int> arr){
//    if this position to visit is visited, or it's beyond the arr
//    return false
    int size = arr.size();
    if (is_Visited[position] || position < 0 || position > size) return false;
//    else mark it as visited
    is_Visited[position] = 1;
    // std::cout << "position #" << position << " is visited " << '\n';

    if (arr[position] == 280) {
        // cout << "280 is found at position #" << position << '\n';
        return true;
    }
    bool r_posi = canWin_helper(is_Visited, position + arr[position], arr);
    if (r_posi) {return true;}
    bool l_posi = canWin_helper(is_Visited, position - arr[position], arr);
    if (l_posi) {return true;}

    return false;
}

bool canWin(int count, vector<int> arr, int position) {
    // EFFECTS: return whether the player can win given the start position
    // and the card sequence

    // TODO: implement this function
    vector<int> is_Visited(MAXSIZE);
    return canWin_helper(is_Visited, position, arr);
}

int main() {
    int count;
    cin >> count;

//    int arr[MAXSIZE];
    vector<int> arr(MAXSIZE);
    for (int i = 0; i < count; ++i) {
        cin >> arr[i];
    }

    int position;
    cin >> position;

    cout << canWin(count, arr, position);
}
