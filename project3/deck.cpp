//
// Created by 71401 on 2021/7/3.
//

#include "deck.h"
#include <iostream>

using namespace std;

// EFFECTS: constructs a "newly opened" deck of cards.  first the
// spades from 2-A, then the hearts, then the clubs, then the
// diamonds.  The first card dealt should be the 2 of Spades.
Deck::Deck() {
    next = 0;
    for (int i = 0; i < DeckSize; ++i) {
        this->deck[i].spot = Spot(i % 13);
        this->deck[i].suit = Suit(i / 13 % 4);
    }
}

// EFFECTS: resets the deck to the state of a "newly opened" deck
// of cards:
void Deck::reset() {
    next = 0;
    for (int i = 0; i < DeckSize; ++i) {
        this->deck[i].spot = Spot(i % 13);
        this->deck[i].suit = Suit(i / 13 % 4);
    }
}

// REQUIRES: n is between 0 and 52, inclusive.
// MODIFIES: this
// EFFECTS: cut the deck into two segments:
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

// MODIFIES: this
// EFFECTS: returns the next card to be dealt.  If no cards remain, throws an instance of DeckEmpty.
Card Deck::deal() {
    if (DeckSize - next == 0) {
        throw DeckEmpty{};
    }
    return deck[next++];
}

// EFFECTS: returns the number of cards in the deck that have not been dealt since the last reset/shuffle.
int Deck::cardsLeft() {
    return DeckSize - next;
}