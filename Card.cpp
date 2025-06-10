#include "Card.h" 
using namespace std;


Card::Card(int value) : value(value > 10 ? 10 : value) {}


int Card::getValue() const {
    return value;
}
