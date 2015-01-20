/*
 * Personne.cxx
 *
 *  Created on: Sep 20, 2014
 *      Author: curlybear
 */

#include "Personne.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sstream>
using namespace std;

Personne::Personne(){
    nom=NULL;
    prenom=NULL;
    setNom("DefaultNom");
    setPrenom("DefaultPrenom");
}

Personne::Personne(const char * pNom, const char * pPrenom){
    nom = NULL;
    prenom = NULL;
    setNom(pNom);
    setPrenom(pPrenom);
}

Personne::Personne(const Personne& pPers){
    nom = NULL;
    prenom = NULL;
    setNom(pPers.getNom());
    setPrenom(pPers.getPrenom());
}

Personne::~Personne(){
    if(nom)
        delete[] nom;
    if(prenom)
        delete[] prenom;
}

const char* Personne::getNom() const{
    return nom;
}
const char* Personne::getPrenom() const{
    return prenom;
}
void Personne::setNom(const char* pNom){
    if(nom)
    {
        delete nom;
    }

    if(pNom)
    {
        this->nom=new char[strlen(pNom)+1];
        strcpy(nom,pNom);
    }
    else
        this->nom=NULL;
}
void Personne::setPrenom(const char* pPrenom){
    if(prenom)
    {
        delete prenom;
    }

    if(pPrenom)
    {
        this->prenom=new char[strlen(pPrenom)+1];
        strcpy(prenom,pPrenom);
    }
    else
        this->prenom=NULL;
}

Personne& Personne::operator=(const Personne& pPers){
    this->setNom(pPers.nom);
    this->setPrenom(pPers.prenom);

    return *this;
}

int Personne::comparaison(const char* pChaine1, const char*pChaine2){
    return strcmp(pChaine1,pChaine2);
}

int Personne::operator<(const Personne& pPers){
    if(comparaison(this->nom, pPers.nom)==-1){
        return 1;
    }
    else{
        if(comparaison(this->nom, pPers.nom)==1){
            return 0;
        }
        else{
            if(comparaison(this->prenom, pPers.prenom)==-1){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
}
int Personne::operator>(const Personne& pPers){
    if(comparaison(this->nom, pPers.nom)==1){
        return 1;
    }
    else{
        if(comparaison(this->nom, pPers.nom)==-1){
            return 0;
        }
        else{
            if(comparaison(this->prenom, pPers.prenom)==1){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
}

void Personne::Affiche(){
    cout << "PERSONNE" << endl;
    cout << "Nom: " << getNom() << endl;
    cout << "Prenom: " << getPrenom() << endl;
}

const char * Personne::toString(){
    ostringstream oss;
    oss << "Personne:" << getNom() << "#" << getPrenom();
    return oss.str().c_str();
}

ostream& operator<<( ostream& flux, const Personne& pPers){
    flux << pPers.getNom() << endl << pPers.getPrenom();
    return flux;
}

istream& operator>> (istream& flux, Personne& pPers){

    flux >> pPers.nom;
    flux >> pPers.prenom;

    cin.clear();
    cin.ignore();

    return flux;
}

