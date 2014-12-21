/*
 * Liste.h
 *
 *  Created on: Sep 29, 2014
 *      Author: curlybear
 */

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>
using namespace std;

#include "ListeBase.h"

template <class T>
class Liste : public ListeBase<T>{
private:

public:

	Liste();
	~Liste(){

	}

	void insere(const T&);
};

template<class T> Liste<T>::Liste() : ListeBase<T>(){
}

template<class T> void Liste<T>::insere(const T& elem){
	noeud<T>* parc = this->debut;
	if(parc == NULL){
		this->debut = new noeud<T>;
		this->debut->elem = T(elem);
	}
	else{
		while(parc->suivant != NULL){
			parc = parc-> suivant;
		}
		parc->suivant = new noeud<T>;
		parc->suivant->elem = T(elem);
	}
}

#endif /* LISTE_H_ */
