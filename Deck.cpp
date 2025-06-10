#include "Deck.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
using namespace std;

Deck::Deck() {
    for (int i = 1; i <= 13; ++i) {
        for (int j = 0; j < 4; ++j) {
            cards.push_back(Card(i));
        }
    }
    shuffleDeck();
}

void Deck::shuffleDeck() {
    srand(time(0));
    random_shuffle(cards.begin(), cards.end());
}

Card Deck::drawCard() {
    if (cards.empty()) {
        throw out_of_range("No more cards in the deck.");
    }
    Card drawn = cards.back();
    cards.pop_back();
    return drawn;
}
