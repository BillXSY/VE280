/*

 * VE280 Lab 3, SU2020.

 * Written by Guoxin Yin

 */



#include <iostream>

using namespace std;

const int MAXSIZE = 10;

bool canWin_help(int count, int arr[], int position, int visited[]){
	if(arr[position]==280)
      return 1;
    if(visited[position]==1|| visited[position+arr[position]]==1||visited[position-arr[position]]==1||position+arr[position]>count||0>position-arr[position]){
      return 0;
      }
      visited[position]=1;
        bool plus = canWin_help(count, arr, position+arr[position],visited);
        bool minus = canWin_help(count, arr, position-arr[position],visited);
      return plus||minus; 
}

bool canWin(int count, int arr[], int position) {
    // EFFECTS: return whether the player can win given the start position
    // and the card sequence
    // TODO: implement this function

    int visited[MAXSIZE]={0};
    return canWin_help(count, arr, position,visited);
    
    
}



int main() {

    int count;

    cin >> count;

    int arr[MAXSIZE];

    for (int i = 0; i < count; ++i) {

        cin >> arr[i];

    }

    int position;

    cin >> position;

    cout << canWin(count, arr, position);

}

