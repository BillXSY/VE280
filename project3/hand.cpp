//
// Created by 71401 on 2021/7/3.
//

#include "hand.h"

// EFFECTS: establishes an empty blackjack hand.
Hand::Hand() {
    this->curValue.count = 0;
    this->curValue.soft = false;
}

// MODIFIES: this
// EFFECTS: discards any cards presently held, restoring the state
// of the hand to that of an empty blackjack hand.
void Hand::discardAll() {
    this->curValue.count = 0;
    this->curValue.soft = false;
}

// MODIFIES: this
// EFFECTS: adds the card "c" to those presently held.
void Hand::addCard(Card c) {
    if (c.spot < 9) {
        this->curValue.count += (c.spot + 2);
    } else if (c.spot >= 9 && c.spot <= 11) {
        this->curValue.count += 10;
    } else if (c.spot == 12) {
        this->curValue.count += 1;
        this->curValue.soft = true;
    }
}

// EFFECTS: returns the present value of the blackjack hand.
HandValue Hand::handValue() const {
    if (!curValue.soft) {
        return curValue;
    } else {
        HandValue AceValue;
        if (this->curValue.count < 12) {
            AceValue.count = curValue.count + 10;
            AceValue.soft = true;
        } else if (this->curValue.count >= 12) {
            AceValue.count = curValue.count;
            AceValue.soft = false;
        }
        return AceValue;
    }
}