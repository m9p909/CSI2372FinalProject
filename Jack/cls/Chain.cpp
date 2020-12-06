#include "../main.h"

class IllegalType : public exception {};

template <class T> Chain<T>::Chain(istream &, const CardFactory *) {
  // loads data
}

template <class T> Chain<T> &Chain<T>::operator+=(Card *card) {
  if (typeid(card_example) == typeid(card)) {
    chainV.push_back(card);

  } else {
    throw new IllegalType;
  }
}
/*
template <> Chain<Card> &Chain<Card>::operator+=(Card *card) {
  if (typeid(card_example) == typeid(card)) {
    chainV.push_back(card);

  } else {
    throw new IllegalType;
  }
  return *this;
}


template <class T> int Chain<T>::sell() {
  return (card_example < -getCardsPerCoint(chainV.size()));
};

template<> int Chain<Card>::sell() {

  return (card_example->getCardsPerCoin(chainV.size()));
};





ostream& operator<<(ostream &out, const Chain<Card> &chain) {
  out << chain.chainV.front()->getName();
  for(int i = 0; i < chain.chainV.size(); i++){
    out << chain.chainV[i] << " ";
  }


}
*/
template <class T>  void Chain<T>::print(ostream &out) const{
  out << "Something has gone wrong";
}

template <class T>  string Chain<T>::getName(){
    return "Name";
}
template <> string Chain<Blue>::getName(){
  return "Blue";
}
template <> string Chain<Black>::getName(){
  return "Black";
}
template <> string Chain<Chili>::getName(){
  return "Chili";
}
template <> string Chain<Garden>::getName(){
  return "Garden";
}
template <> string Chain<Green>::getName(){
  return "Green";
}
template <> string Chain<Red>::getName(){
  return "Red";
}
template <> string Chain<Soy>::getName(){
  return "Soy";
}
template <> string Chain<Stink>::getName(){
  return "Stink";
}
template <>  void Chain<Blue>::print(ostream &out) const{
  out << card_example->getName() << "\t";
  for (int i = 0; i < chainV.size(); i++) {
    out << card_example;
  }
  
};

template <>  void Chain<Green>::print(ostream &out) const {
  out << card_example->getName() << "\t";
  for (int i = 0; i < chainV.size(); i++) {
    out << card_example;
  }
};
template <>  void Chain<Chili>::print(ostream &out)  const{
  out << card_example->getName() << "\t";
  for (int i = 0; i < chainV.size(); i++) {
    out << card_example;
  }
};
template <>  void Chain<Garden>::print(ostream &out) const {
  out << card_example->getName() << "\t";
  for (int i = 0; i < chainV.size(); i++) {
    out << card_example;
  }
};
template <> void Chain<Red>::print(ostream &out) const {
  out << card_example->getName() << "\t";
  for (int i = 0; i < chainV.size(); i++) {
    out << card_example;
  }
};
template <>  void Chain<Soy>::print(ostream &out) const {
  out << card_example->getName() << "\t";
  for (int i = 0; i < chainV.size(); i++) {
    out << card_example;
  }
};
template <> void Chain<Stink>::print(ostream &out) const {
  out << card_example->getName() << "\t";
  for (int i = 0; i < chainV.size(); i++) {
    out << card_example;
  }
};

ostream &operator<<(ostream &out, const Chain_Base &chain) { 
  chain.print(out);
   }

