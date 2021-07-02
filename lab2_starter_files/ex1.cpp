#include <iostream>
#include <cstring>

using namespace std;

#define RANGE 100000

bool isPrime[RANGE + 1];

// MODIFIES: isPrime[]
// EFFECTS: fill in isPrime[], true for prime, false otherwise
void generateIsPrime() {
    // TODO: implement Eratosthenes Sieve Algorithm
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0]=false;
    isPrime[1]=false;
    for (int i = 2; i * i <= RANGE; i++) {
        if (isPrime[i]) {
            for (int j = 2; j * i <= RANGE; j++) {
                isPrime[j * i] = false;
            }
        }

    }

}

int main() {
    // TODO: generate lookup table
    generateIsPrime();

    // TODO: read input and check if each num is prime
    int size;
    cin >> size;
    int ints[20] = {};
    for (int i = 0; i < size; i++){
        cin >> ints[i];
    }
    for (int i = 0; i < size; i++){
        if (isPrime[ints[i]]){
            cout << ints[i] << " ";
        }
    }
    cout << endl;
    return 0;
}