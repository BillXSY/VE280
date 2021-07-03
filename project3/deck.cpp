//
// Created by 71401 on 2021/7/3.
//

#include "deck.h"
#include <iostream>

Deck::Deck() {
    next = 0;
    for (int i = 0; i < DeckSize; ++i) {
        this->deck[i].spot = Spot(i % 13);
        this->deck[i].suit = Suit(i / 13 % 4);
    }
//    for (int i = 0; i < DeckSize; ++i) {
//        std::cout << SuitNames[this->deck[i].suit] << ' ' << SpotNames[this->deck[i].spot] << std::endl;
//    }
}

void Deck::reset() {
    next = 0;
    for (int i = 0; i < DeckSize; ++i) {
        this->deck[i].spot = Spot(i % 13);
        this->deck[i].suit = Suit(i / 13 % 4);
    }
//    for (int i = 0; i < DeckSize; ++i) {
//        std::cout << SuitNames[this->deck[i].suit] << ' ' << SpotNames[this->deck[i].spot] << std::endl;
//    }
}

void Deck::shuffle(int n) {
    int left = 0, right = n;
    Card rslt[DeckSize];
    int index = 0;
    while (left < n && right < 52) {
        rslt[index++] = this->deck[right++];
        rslt[index++] = this->deck[left++];
    }
    if (left == n - 1) {
        while (right < 52) {
            rslt[index++] = this->deck[right++];
        }
    }
    if (right == 51) {
        while (left < n) {
            rslt[index++] = this->deck[left++];
        }
    }

    for (int i = 0; i < DeckSize; ++i) {
        this->deck[i] = rslt[i];
    }

//    for (auto & i : this->deck) {
//        std::cout << SuitNames[i.suit] << ' ' << SpotNames[i.spot] << std::endl;
//    }
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