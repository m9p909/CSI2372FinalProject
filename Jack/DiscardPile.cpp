#include "globalHeader.h"
#include "./Cards/Cards.cpp"
#include "./CardFactory.cpp"
class DiscardPile: public vector<Card>{
    
    DiscardPile(istream&, const CardFactory*);
    DiscardPile& operator+=(Card*);
    Card* pickUp();
    Card* top();
    void  print(std::ostream&);
};