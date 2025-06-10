#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() : deck(), player(), dealer() {}

void Game::play() {
    cout << "21點遊戲開始!" << endl;

    // Initial draw
    player.drawCard(deck);
    dealer.drawCard(deck);
    player.drawCard(deck);
    dealer.drawCard(deck);

    cout << "玩家手牌: ";
    player.showHand();
    cout << "電腦手牌: ";
    dealer.showHand();

    char choice;
    while (true) {
        cout << "叫牌還是停牌(h/s) ";
        cin >> choice;
        if (choice == 'h') {
            player.drawCard(deck);
            cout << "玩家手牌: ";
            player.showHand();

            if (player.getHandValue() > 21) {
                cout << "玩家手牌爆了!電腦贏" << endl;
                return;
            }
        }
        else if (choice == 's') {
            break;
        }
        else {
            cout << "Invalid choice. Please enter 'h' to hit or 's' to stand." << endl;
        }
    }

    // Dealer's turn
    while (dealer.getHandValue() < 17) {
        dealer.drawCard(deck);
    }

    cout << "電腦手牌: ";
    dealer.showHand();

    // Determine winner
    int playerValue = player.getHandValue();
    int dealerValue = dealer.getHandValue();

    if (dealerValue > 21 || playerValue > dealerValue) {
        cout << "玩家贏!" << endl;
    }
    else if (playerValue == dealerValue) {
        cout << "平手!" << endl;
    }
    else {
        cout << "電腦贏." << endl;
    }
}
