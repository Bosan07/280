#ifndef GAME_H
#define GAME_H
using namespace std;

#include "Deck.h"
#include "Player.h"

class Game {
public:
    Game();
    void play();

private:
    Deck deck;
    Player player;
    Player dealer;
};

#endif // GAME_H
