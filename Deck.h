#ifndef DECK_H
#define DECK_H
using namespace std;

#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();
    void shuffleDeck();
    Card drawCard();

private:
    vector<Card> cards;
};

#endif // DECK_H
