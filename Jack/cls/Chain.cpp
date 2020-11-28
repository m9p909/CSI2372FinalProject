#include "../main.h"

class IllegalType : public exception {};

template <class T> Chain<T>::Chain(istream &, const CardFactory *) {}

template <class T> Chain<T> &Chain<T>::operator+=(Card *card) {
  if (typeid(card_example) == typeid(card)) {
    chainV.push_back(card);

  } else {
    throw new IllegalType;
  }
}

template <class T> int Chain<T>::sell() {
  return (card_example < -getCardsPerCoint(chainV.size()));
};


template <class T>
ostream& operator<<(ostream &out, const Chain<T> &chain) {
  T cardExample = new T();
  out << typeid(cardExample).name();
  for (int i = 0; i < *chain.chainV.size(); i++) {
    out << " " << cardExample;
  }
}
