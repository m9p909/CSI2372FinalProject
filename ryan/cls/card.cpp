#include "../main.h"

/**
 * Helper method for card objects.
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
  throw CoinValueNotFound();
}

/**
 * Blue - Card Function Implementations
 */

int Blue::getCardsPerCoin(int coins)
{
  valuePair values[] = {{1, 4}, {2, 6}, {3, 8}, {4, 10}};
  return calculateChainValue(coins, values, 4);
};

string Blue::getName()
{
  return "Blue";
};

void Blue::print(ostream &out)
{
  out << "B";
};

/**
 * Chili - Card Function Implementations
 */

int Chili::getCardsPerCoin(int coins)
{
  valuePair values[] = {{1, 3}, {2, 6}, {3, 8}, {4, 9}};
  return calculateChainValue(coins, values, 4);
};

string Chili::getName()
{
  return "Chili";
};

void Chili::print(ostream &out)
{
  out << "C";
};

/**
 * Stink - Card Function Implementations
 */

int Stink::getCardsPerCoin(int coins)
{
  valuePair values[] = {{1, 3}, {2, 5}, {3, 7}, {4, 8}};
  return calculateChainValue(coins, values, 4);
};

string Stink::getName()
{
  return "Stink";
};

void Stink::print(ostream &out)
{
  out << "S";
};

/**
 * Green - Card Function Implementations
 */

int Green::getCardsPerCoin(int coins)
{
  valuePair values[] = {{1, 3}, {2, 5}, {3, 6}, {4, 7}};
  return calculateChainValue(coins, values, 4);
};

string Green::getName()
{
  return "Green";
};

void Green::print(ostream &out)
{
  out << "G";
};

/**
 * soy - Card Function Implementations
 */

int Soy::getCardsPerCoin(int coins)
{
  valuePair values[] = {{1, 2}, {2, 4}, {3, 6}, {4, 7}};
  return calculateChainValue(coins, values, 4);
};

string Soy::getName()
{
  return "Soy";
};

void Soy::print(ostream &out)
{
  out << "s";
};

/**
 * black - Card Function Implementations
 */

int Black::getCardsPerCoin(int coins)
{
  valuePair values[] = {{1, 2}, {2, 4}, {3, 5}, {4, 6}};
  return calculateChainValue(coins, values, 4);
};

string Black::getName()
{
  return "Black";
};

void Black::print(ostream &out)
{
  out << "b";
};

/**
 * Red - Card Function Implementations
 */

int Red::getCardsPerCoin(int coins)
{
  valuePair values[] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  return calculateChainValue(coins, values, 4);
};

string Red::getName()
{
  return "Red";
};

void Red::print(ostream &out)
{
  out << "R";
};

/**
 * garden - Card Function Implementations
 */

int Garden::getCardsPerCoin(int coins)
{
  valuePair values[] = {{2, 2}, {3, 3}};
  return calculateChainValue(coins, values, 4);
};

string Garden::getName()
{
  return "Garden";
};

void Garden::print(ostream &out)
{
  out << "g";
};

ostream &operator<<(ostream &out, Card &card)
{
  // Call the virtual print function in the children.
  card.print(out);
  return out;
}