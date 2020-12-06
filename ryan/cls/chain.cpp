#include "../main.h"

/**
 * Contains the Chain base and template classes.
 */

Chain_Base::Chain_Base(istream &, const CardFactory *)
{
}

template <typename T>
Chain_Base &Chain<T>::operator+=(Card *c)
{
  if (typeid(*c) == typeid(T))
  {
    cards.push_back(dynamic_cast<T *>(c));
    return *this;
  }
  else
    throw IllegalType();
}

template <typename T>
int Chain<T>::sell()
{
  unsigned int size = cards.size();
  if (size > 0)
  {
    unsigned int coins = 4; // Max number of coins is one.
    unsigned int min_cards = 0;

    // Check chain-length values from one to four coins.
    while (coins >= 1)
    {
      try
      {
        // Check the minimum number of cards required to get <this> number of coins.
        min_cards = cards[0]->getCardsPerCoin(coins);

        // If the chain size is large enough, return the coin value.
        if (size >= min_cards)
          return coins;
      }
      // If this exception is thrown, it's fine, we can just continue.
      catch (CoinValueNotFound &e)
      {
      };

      coins--;
    }
  }
  return 0;
}

template <typename T>
void Chain<T>::print(ostream &out) {}