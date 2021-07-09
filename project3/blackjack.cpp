//
// Created by 71401 on 2021/7/4.
//

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>

#include "rand.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "card.h"

using namespace std;

const int SHUFFLE_TIME = 7;

void deck_init(Deck *deck) {
    cout << "Shuffling the deck" << endl;
    for (int i = 0; i < SHUFFLE_TIME; ++i) {
        int cut = get_cut();
        cout << "cut at " << cut << endl;
        deck->shuffle(cut);
    }
}

int main(int argc, char const *argv[]) {
    int bankroll = stoi(argv[1]);
    int hands = stoi(argv[2]);
    string player_type = argv[3];
    string dealerSide = argv[4];
    string simple = "simple";
    string counting = "counting";
    int ID[] = {1, 2, 3, 4, 5};

    // SOS Brigade
    Player *Suzumiya_Haruhi = get_Player(dealerSide, simple, ID[1]);
    Player *Nagato_Yuki = get_Player(dealerSide, counting, ID[2]);
    Player *Asahina_Mikuru = get_Player(dealerSide, counting, ID[3]);
    Player *Kyon = get_Player(dealerSide, simple, ID[4]);
    Player *Koizumi_Itzuki = get_Player(dealerSide, player_type, ID[5]);

    //Stardust Crusaders
    Player *JJ = get_Player(dealerSide, simple, ID[1]);
    Player *KJ = get_Player(dealerSide, counting, ID[2]);
    Player *JPP = get_Player(dealerSide, counting, ID[3]);
    Player *KN = get_Player(dealerSide, simple, ID[4]);
    Player *MA = get_Player(dealerSide, player_type, ID[5]);

    Deck *deck = new Deck;

    deck_init(deck);

    int thisHand = 0;
    int minBet = 5;


    return 0;
}