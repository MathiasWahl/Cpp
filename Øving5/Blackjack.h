#ifndef BLACKJACK_H_
#define BLACKJACK_H_
using namespace std;

class CardDeck;
class Card;

class Blackjack {
private:
  CardDeck *deck;
  int playerHand, dealerHand;
  int playerCardsDrawn, dealerCardsDrawn;
  int getCardValue(Card *card);
  bool isAce(Card *card);
  int getPlayerCardValue(Card *card);
  int getDealerCardValue(Card *card, int currentScore);
  bool askPlayerDrawCard();
  void drawInitialCards();

public:
  void playGame();
};

#endif // BLACKJACK_H_
