#include "globalHeader.h"
#include "./Cards/Cards.cpp"
#include "CardFactory.cpp"

class IllegalType: public exception{

};


template <typename T> class Chain{
    Card card_example;
    vector<T*> chainV;
    Chain(istream&,  const  CardFactory*){

    }
    
    Chain<T>& operator+=(Card* card){
        if(typeid(card_example) == typeid(card)){
            chainV.push_back(card);
            
        }else{
            throw new IllegalType;
        }
    }

    int  sell(){
        return(card_example.getCardsPerCoin(chainV.size()));
    };

    friend ostream & operator << (ostream &out, const Chain &chain){
        T cardExample = new T();
        out << typeid(cardExample).name();
        for(int i =0; i < *chain.chainV.size(); i++){
            out <<" "<< cardExample;
        }
        
    }

};