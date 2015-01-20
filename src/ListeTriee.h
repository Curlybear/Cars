/*
 * ListeTriee.h
 *
 *  Created on: Sep 29, 2014
 *      Author: curlybear
 */

#ifndef LISTETRIEE_H_
#define LISTETRIEE_H_

#include <iostream>
#include "ListeBase.h"
#include "InvalidRequestException.h"
using namespace std;

template <class T>
class ListeTriee : public ListeBase<T>{
private:

public:

    ListeTriee();
    ListeTriee(const ListeTriee&);
    virtual ~ListeTriee(){

    }

    void insere(const T&);
    void write(ostream&);
    void read(istream&);
    T delElem(const T&);
    T getElem(const T&);
    T* getElemPtr(const T&);
};

template<class T> ListeTriee<T>::ListeTriee(){

}

template<class T> ListeTriee<T>::ListeTriee(const ListeTriee& pListe){
    Iterateur<T> it(pListe);

    this->debut = NULL;

    while(!it.end()){
        this->insere(it);
        it++;
    }
}

template<class T> void ListeTriee<T>::insere(const T& elem){
    noeud<T>* parc = this->debut;
    noeud<T>* prec = NULL;
    noeud<T>* temp = NULL;

    if(parc == NULL ){ // Liste vide
        this->debut = new noeud<T>;
        this->debut->elem = T(elem);
        this->debut->suivant = NULL;
    }
    else{
        while(parc != NULL && parc->elem<elem){
            prec = parc;
            parc = parc->suivant;
        }

        if(prec == NULL){ // Pas de passage dans la boucle => début de liste (1 element présent)
            temp = this->debut;
            this->debut = new noeud<T>;
            this->debut->elem = T(elem);
            this->debut->suivant = temp;
        }
        else{
            prec->suivant = new noeud<T>;
            prec->suivant->elem = T(elem);
            prec->suivant->suivant = parc;
        }
    }
}

template<class T> void ListeTriee<T>::write(ostream& flux){
    noeud<T>* parc = this->debut;
    int temp = this->getNombreElements();

    flux.write((char*)&temp,sizeof(int));
    while(parc!=NULL){
        flux << parc->elem;
        parc = parc->suivant;
    }
}

template<class T> void ListeTriee<T>::read(istream& flux){
    noeud<T>* parc = this->debut;
    T tempVar;
    int temp;
    flux.read((char*)&temp,sizeof(int));
    for(int i=0;i<temp;i++){
        flux >> tempVar;
        tempVar.Affiche();
        this->insere(tempVar);
    }
}

template<class T> T ListeTriee<T>::delElem(const T& recherche){
    Iterateur<T> it(*this);
    bool found=false;
    T ret;
    while(!it.end()){
        if(&it != recherche){
            it++;
        }
        else {
            ret = it.remove();
            found=true;
            break;
        }
    }

    if(!found){
        throw InvalidRequestException("L'élément demandé n'est pas dans la liste.");
    }

    return ret;
}

template<class T> T ListeTriee<T>::getElem(const T& recherche){
    Iterateur<T> it(*this);
    bool found=false;
    T ret;
    while(!it.end()){
        if(&it != recherche){
            it++;
        }
        else {
            ret = &it;
            found=true;
            break;
        }
    }

    if(!found){
        throw InvalidRequestException("L'élément demandé n'est pas dans la liste.");
    }

    return ret;
}

template<class T> T* ListeTriee<T>::getElemPtr(const T& recherche){
    noeud<T>* parc;
    T* ret=NULL;
    if(this->debut != NULL){
        parc = this->debut;

        while(parc != NULL && parc->elem!=recherche){
            parc = parc->suivant;
        }

        if(parc!=NULL){
            if(!(parc->elem!=recherche)){
                ret = &(parc->elem);
            }
        }
        else{
            ret = NULL;
        }
    }
    return ret;
}


#endif /* LISTETRIEE_H_ */
