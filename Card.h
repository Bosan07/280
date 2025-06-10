#ifndef CARD_H
#define CARD_H
using namespace std;

class Card {
public:
    Card(int value);
    int getValue() const;

private:
    int value;
};

#endif // CARD_H
