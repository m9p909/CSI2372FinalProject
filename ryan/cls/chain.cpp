#include "../main.h"

/**
 * Contains the Chain base and template classes.
 */

Chain_Base::Chain_Base(istream &, const CardFactory *)
{
}

Chain_Base::Chain_Base()
{
}

Chain_Base::~Chain_Base()
{
}

template <typename T>
Chain_Base &Chain<T>::operator+=(Card *c)
{
  cout << "Comparing types..." << endl;
  if (typeid(*c) == typeid(T))
  {
    cout << "Comparing types..." << endl;
    //cards.push_back((T)c);
    return *this;
  }
  else
  {
    cout << "Was not given the correct type of card..." << endl;
    throw new IllegalType;
  }
}

template <typename T>
int Chain<T>::sell()
{
  return 0;
}

template <typename T>
void Chain<T>::print(ostream &out) {}