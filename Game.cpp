#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() : deck(), player(), dealer() {}

void Game::play() {
    cout << "Welcome to 21point!" << endl;

    // Initial draw
    player.drawCard(deck);
    dealer.drawCard(deck);
    player.drawCard(deck);
    dealer.drawCard(deck);

    cout << "Your hand: ";
    player.showHand();
    cout << "Computer's hand: ";
    dealer.showHand();

    char choice;
    while (true) {
        cout << "Do you want to hit or stand? (h/s): ";
        cin >> choice;
        if (choice == 'h') {
            player.drawCard(deck);
            cout << "Your hand: ";
            player.showHand();

            if (player.getHandValue() > 21) {
                cout << "You busted! Computer wins." << endl;
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

    cout << "Computer hand: ";
    dealer.showHand();

    // Determine winner
    int playerValue = player.getHandValue();
    int dealerValue = dealer.getHandValue();

    if (dealerValue > 21 || playerValue > dealerValue) {
        cout << "You win!" << endl;
    }
    else if (playerValue == dealerValue) {
        cout << " tie!" << endl;
    }
    else {
        cout << "Computer wins." << endl;
    }
}
