/*
 * ListeBase.h
 *
 *  Created on: Sep 29, 2014
 *      Author: curlybear
 */

#ifndef LISTEBASE_H_
#define LISTEBASE_H_

#include <iostream>
using namespace std;

template <class T>
class ListeBase;

template <class E> struct noeud{
    E elem;
    noeud<E>* suivant;

    noeud(){
        suivant = NULL;
    }
};

#include "Iterateur.h"

template <class T>
class ListeBase{
    friend class Iterateur<T>;
protected:

    noeud<T> *debut;
public:

    ListeBase();
    ListeBase(const ListeBase&);
    virtual ~ListeBase();

    virtual void insere(const T&)=0;
    void Affiche();
    bool vide(){return this->debut==NULL;};
    int getNombreElements();
};

template<class T> ListeBase<T>::ListeBase(){
    this->debut = NULL;
}

template<class T> ListeBase<T>::ListeBase(const ListeBase& pListe){
    Iterateur<T> it(pListe);

    this->debut = NULL;

    while(!it.end()){
        this->insere(it);
        it++;
    }
}

template<class T> ListeBase<T>::~ListeBase(){
    noeud<T> *parc,*prec;
    if(!vide()){
        parc = this->debut;
        do{
            prec = parc;
            parc = parc->suivant;
            this->debut = parc;
            delete prec;
        }while(!vide());
    }
}

template<class T> void ListeBase<T>::Affiche(){
    noeud<T> * parc;
    if(!vide()){
        parc = this->debut;
        do{
            parc->elem.Affiche();
            parc = parc->suivant;
        }while(parc!=NULL);
    }
    else{
        cout << "Liste vide" << endl;
    }
}

template<class T> int ListeBase<T>::getNombreElements(){
    int nb=0;

    noeud<T> * parc;
    if(!vide()){
        parc = this->debut;
        do{
            nb++;
            parc = parc->suivant;
        }while(parc!=NULL);
    }

    return nb;
}


#endif /* LISTEBASE_H_ */
