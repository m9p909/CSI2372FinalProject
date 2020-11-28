#include "../globalHeader.h"

class Card {
public:
  virtual int getCardsPerCoin(int coins);
  virtual string getName();
  virtual void print(ostream &out) const;
  friend ostream& operator << (ostream& o, const Card& b){
      b.print(o);
      return o;
  }
};

