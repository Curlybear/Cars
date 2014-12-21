/*
 * Pile.h
 *
 *  Created on: Sep 29, 2014
 *      Author: curlybear
 */

#ifndef PILE_H_
#define PILE_H_

#include <iostream>
#include "ListeBase.h"
using namespace std;

template <class T>
class Pile : public ListeBase<T>{
private:

public:

	Pile();
	virtual ~Pile(){

	}

	void insere(const T&);
	T retire();
};

template<class T> Pile<T>::Pile(){

}

template<class T> void Pile<T>::insere(const T& elem){
	noeud<T>* parc = this->debut;

	this->debut = new noeud<T>;
	this->debut->elem = T(elem);
	this->debut->suivant = parc;
}

template<class T> T Pile<T>::retire(){
	T elemret = this->debut->elem;
	noeud<T>* parc = this->debut;

	this->debut = this->debut->suivant;
	delete parc;

	return elemret;
}

#endif /* PILE_H_ */
