#include "../main.h"

class IllegalType : public exception {
  const char* what () const throw(){
    return "Illegal type excption";
  }
};
//very useful reference https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern
template <class T> Chain<T>::Chain(istream &, const CardFactory *) {
  // loads data
}




template <class T> Chain<T>::Chain() = default;

template <class T> Chain<T> &Chain<T>::operator+=(Card *card) {
  if (card_example->getName() == card->getName()) {
    chainV.push_back(static_cast<T*>(card));
    return *this;
  } else {
  
    throw new IllegalType;
  }
  
}

template <class T> int Chain<T>::getLength(){
  return chainV.size();
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
*/

template <class T> int Chain<T>::sell() {
  return (card_example->getCardsPerCoin(chainV.size()));
};

template<> int Chain<Card>::sell() {

  return (card_example->getCardsPerCoin(chainV.size()));
};




/*
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

template <class T> string Chain<T>::getName(){
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


//constructors;
template <> Chain<Blue>::Chain(){
  card_example = new Blue();
}
template <> Chain<Black>::Chain(){
  card_example = new Black();
}
template <> Chain<Chili>::Chain(){
  card_example = new Chili();
}
template <> Chain<Garden>::Chain(){
  card_example = new Garden();
}
template <> Chain<Green>::Chain(){
  card_example = new Green();
}

template <> Chain<Red>::Chain(){
  card_example = new Red();
}

template <> Chain<Soy>::Chain(){
  card_example = new Soy();
}

template <> Chain<Stink>::Chain(){
  card_example = new Stink();
}

template <>  void Chain<Blue>::print(ostream &out) const{
  out << card_example->getName() << "\t";
  for (int i = 0; i < chainV.size(); i++) {
    card_example->print(out);
  }
  
};

template <>  void Chain<Green>::print(ostream &out) const {
  out << card_example->getName() << "\t";
  for (int i = 0; i < chainV.size(); i++) {
    card_example->print(out);
  }
};
template <>  void Chain<Chili>::print(ostream &out)  const{
  out << card_example->getName() << "\t";
  for (int i = 0; i < chainV.size(); i++) {
    card_example->print(out);
  }
};
template <>  void Chain<Garden>::print(ostream &out) const {
  out << card_example->getName() << "\t";
  for (int i = 0; i < chainV.size(); i++) {
    card_example->print(out);
  }
};
template <> void Chain<Red>::print(ostream &out) const {
  out << card_example->getName() << "\t";
  for (int i = 0; i < chainV.size(); i++) {
    card_example->print(out);
  }
};
template <>  void Chain<Soy>::print(ostream &out) const {
  out << card_example->getName() << "\t";
  for (int i = 0; i < chainV.size(); i++) {
    card_example->print(out);
  }
};
template <> void Chain<Stink>::print(ostream &out) const {
  out << card_example->getName() << "\t";
  for (int i = 0; i < chainV.size(); i++) {
    card_example->print(out);
  }
};

ostream &operator<<(ostream &out, const Chain_Base &chain) { 
  chain.print(out);
   }

