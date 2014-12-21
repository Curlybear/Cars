/*
 * Iterateur.h
 *
 *  Created on: Sep 30, 2014
 *      Author: curlybear
 */

#ifndef ITERATEUR_H_
#define ITERATEUR_H_

#include "ListeBase.h"

using namespace std;

template <class T>
class Iterateur {
private:
	ListeBase<T> & p;
	noeud<T> *pCur;
	noeud<T> *pPrec;
public:
	Iterateur(ListeBase<T>& s) : p(s),pCur(s.debut){pPrec=NULL;};

	bool end() const{
		if(pCur == NULL) return true;
		else return false;
	}

	void reset(){pCur = p.debut; pPrec=NULL;}

	T remove();

	bool operator++(){
		if(pCur){
			pPrec = pCur;
			pCur = pCur->suivant;
			return true;
		}
		else return false;
	}

	bool operator++(int){return operator++();}
	operator T() {return pCur->elem;}
	T& operator&(void){return pCur->elem;}

	virtual ~Iterateur(){};
};


template<class T> T Iterateur<T>::remove(){
	T temp;

	if(pCur){
		if(pPrec){
			pPrec->suivant = pCur->suivant;
			temp = pCur->elem;
			delete pCur;
			pCur=pPrec->suivant;
		}
		else{
			p.debut = pCur->suivant;
			temp = pCur->elem;
			delete pCur;
			pCur=p.debut;
		}
	}
	return temp;
}

#endif /* ITERATEUR_H_ */
