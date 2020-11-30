#include "../main.h"

/**
 * The abstract definition of Card is in main.h
 */

/**
 * Given an array of structs with coins and values, return the value.
 */
int calculateChainValue(int coins, valuePair *values, int numValues)
{
  for (int i = 0; i < numValues; i++)
  {
    if (coins == values[i].coins)
      return values[i].chainValue;
  }

  // If the value is not in the given pairs, raise an exception.
  throw "Value not found for this card.";
}

/**
 * Stink - Card Function Implementations
 */

int Stink::getCardsPerCoin(int coins)
{
  valuePair values[] = {{1, 7}, {2, 8}, {3, 9}};
  return calculateChainValue(coins, values, 3);
};

string Stink::getName()
{
  return "Stink";
};

void Stink::print(ostream &out)
{
  out << "S";
};
