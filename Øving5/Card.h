#ifndef CARD_H_
#define CARD_H_

#include <string>
using namespace std;

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

enum Rank {
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING,
  ACE
};

string suitToString(Suit s);

string rankToString(Rank r);

struct CardStruct {
  Suit s;
  Rank r;
};

string toString(CardStruct card);

string toStringShort(CardStruct card);

class CardDeck;

class Card {

private:
  CardStruct info;
  bool valid;

public:
  void initialize(Suit s, Rank r);
  Suit getSuit();
  Rank getRank();
  string toString();
  string toStringShort();
  Card();
  Card(Suit suit, Rank rank);
};

#endif // CARD_H_
