//
// Created by 71401 on 2021/7/3.
//
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "rand.h"

#include <iostream>

int main() {
    Deck dk;
//    dk.reset();
    Card cd = dk.deal();
    cout << SpotNames[cd.spot] << ' ' << SuitNames[cd.suit] << endl;
    cout << dk.cardsLeft() << endl << endl;

    dk.shuffle(26);

//    SimplePlayer p1;

    return 0;

}