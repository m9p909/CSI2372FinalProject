#include "Card.cpp"


class Black : public Card {
  int getCardsPerCoin(int coins) {
    if (coins == 0) {
      return 0;
    } else if (coins == 1) {
      return 2;
    } else if (coins == 2) {
      return 4;
    } else if (coins == 3) {
      return 5;
    } else if (coins == 4) {
      return 6;
    }
   
      return -1;
   
  }
  string getName() { return "Black"; }

  void print(ostream &out) { out << "b"; }
};


class Blue : public Card {
  int getCardsPerCoin(int coins) {
    if (coins == 0) {
      return 0;
    } else {
      return 2 + 2 * coins;
    }
  }
  string getName() { return "Blue"; }

  void print(ostream &out) { out << "B"; }
};

class Chili : public Card {
  int getCardsPerCoin(int coins) {
    if (coins == 0) {
      return 0;
    } else if (coins == 1) {
      return 3;
    } else if (coins == 2) {
      return 6;
    } else if (coins == 3) {
      return 8;
    } else if (coins == 4) {
      return 9;
    }
    return -1;
  }
  string getName() { return "Chili"; }

  void print(ostream &out) { out << "C"; }
};

class Garden : public Card {
  int getCardsPerCoin(int coins) {
    if (coins == 0) {
      return 0;
    } else if (coins == 1) {
      return 0;
    } else if (coins == 2) {
      return 2;
    } else if (coins == 3) {
      return 3;
    } else if (coins == 4) {
      return 0;
    }
    return -1;
  }
  string getName() { return "Garden"; }

  void print(ostream &out) { out << "g"; }
};


class Green : public Card {
  int getCardsPerCoin(int coins) {
    if (coins == 0) {
      return 0;
    } else if (coins == 1) {
      return 3;
    } else if (coins == 2) {
      return 5;
    } else if (coins == 3) {
      return 6;
    } else if (coins == 4) {
      return 7;
    }
    return -1;
  }
  string getName() { return "Green"; }

  void print(ostream &out) { out << "G"; }
};


class Soy : public Card {
  int getCardsPerCoin(int coins) {
    if (coins == 0) {
      return 0;
    } else if (coins == 1) {
      return 2;
    } else if (coins == 2) {
      return 3;
    } else if (coins == 3) {
      return 4;
    } else if (coins == 4) {
      return 5;
    }
    return -1;
  }
  string getName() { return "Red"; }

  void print(ostream &out) { out << "R"; }
};


class Stink : public Card {
  int getCardsPerCoin(int coins) {
    if (coins == 0) {
      return 0;
    } else if (coins == 1) {
      return 3;
    } else if (coins == 2) {
      return 5;
    } else if (coins == 3) {
      return 7;
    } else if (coins == 4) {
      return 8;
    }
    return -1; 
  }
  string getName() { return "Stink"; }

  void print(ostream &out) { out << "S"; }
};