//
// Created by 71401 on 2021/7/3.
//

#include "deck.h"
#include <iostream>

using namespace std;

Deck::Deck() {
    next = 0;
    for (int i = 0; i < DeckSize; ++i) {
        this->deck[i].spot = Spot(i % 13);
        this->deck[i].suit = Suit(i / 13 % 4);
    }
//    for (int i = 0; i < DeckSize; ++i) {
//        std::cout << SuitNames[this->deck[i].suit] << ' ' << SpotNames[this->deck[i].spot] << std::endl;
//    }
//    cout << "\n\n\n";
}

void Deck::reset() {
    next = 0;
    for (int i = 0; i < DeckSize; ++i) {
        this->deck[i].spot = Spot(i % 13);
        this->deck[i].suit = Suit(i / 13 % 4);
    }
}

void Deck::shuffle(int n) {
    int left = 0, right = n;
    Card rslt[DeckSize];
    int index = 0;
    while (left < n && right < 52) {
        rslt[index++] = this->deck[right++];
        rslt[index++] = this->deck[left++];
    }
    if (left == n) {
        while (right < 52) {
            rslt[index++] = this->deck[right++];
        }
    }
    if (right == 52) {
        while (left < n) {
            rslt[index++] = this->deck[left++];
        }
    }
    for (int i = 0; i < DeckSize; ++i) {
        this->deck[i] = rslt[i];
    }
    next = 0;
}

Card Deck::deal() {
    if (DeckSize - next == 0) {
        throw DeckEmpty{};
    }
    return deck[next++];
}

int Deck::cardsLeft() {
    return DeckSize - next;
}