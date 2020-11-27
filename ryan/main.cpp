#include "main.h"


int main()
{
  copyrightMessage();
  gameStartMessage();
  Stink x = Stink();
  cout << x.getCardsPerCoin(3) << endl;
  return 0;
}
