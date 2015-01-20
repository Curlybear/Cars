/*
 * Client.cxx
 *
 *  Created on: Sep 20, 2014
 *      Author: curlybear
 */

#include "Client.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sstream>

using namespace std;

Client::Client(){
    nom = NULL;
    prenom = NULL;
    numero = 0;
    adresse = NULL;

    setNom("DefaultNom");
    setPrenom("DefaultPrenom");
    setAdresse("DefaultAdresse");
}

Client::Client(const Client& pCli){
    nom = NULL;
    prenom = NULL;
    numero = 0;
    adresse = NULL;

    setNom(pCli.getNom());
    setPrenom(pCli.getPrenom());
    numero = pCli.getNumero();
    setAdresse(pCli.getAdresse());
}

Client::Client(const char* pNom, const char* pPrenom, const int pNumero, const char* pAdresse){
    nom = NULL;
    prenom = NULL;
    numero = 0;
    adresse = NULL;

    setNom(pNom);
    setPrenom(pPrenom);
    numero = pNumero;
    setAdresse(pAdresse);
}

Client::~Client(){
    if(adresse)
        delete[] adresse;
}

const char* Client::getAdresse() const{
    return adresse;
}
const int Client::getNumero() const{
    return numero;
}
void Client::setAdresse(const char* pAdresse){
    if(adresse)
    {
        delete adresse;
    }

    if(pAdresse)
    {
        this->adresse=new char[strlen(pAdresse)+1];
        strcpy(adresse,pAdresse);
    }
    else
        this->adresse=NULL;
}
void Client::setNumero(const int pNumero){
    numero = pNumero;
}

void Client::Affiche(){
    cout << "CLIENT" << endl;
    cout << "\tNom: " << getNom() << endl;
    cout << "\tPrenom: " << getPrenom() << endl;
    cout << "\tAdresse: " << getAdresse() << endl;
    cout << "\tNumero: " << getNumero() << endl;
}

void Client::AfficheLigne(){
    cout << numero << "\t" << nom << " " << prenom << " " << adresse << endl;
}

const char * Client::toString(){
    ostringstream oss;
    oss << "Personne:" << getNom() << "#" << getPrenom() << "#" << getAdresse() << "#" << getNumero();
    return oss.str().c_str();
}

Client& Client::operator=(const Client& pCli){
    this->setNom(pCli.nom);
    this->setPrenom(pCli.prenom);
    this->setAdresse(pCli.adresse);
    this->setNumero(pCli.numero);

    return *this;
}

bool Client::operator!=(const Client& pCli){
    return !(this->getNumero()==pCli.getNumero());
}

ostream& operator<<(ostream& flux, const Client& pCli){

    int size;

    size = strlen(pCli.getNom())+1;
    flux.write((char*)&size,sizeof(int));
    flux.write(pCli.getNom(),size);

    size = strlen(pCli.getPrenom())+1;
    flux.write((char*)&size,sizeof(int));
    flux.write(pCli.getPrenom(),size);

    size = strlen(pCli.getAdresse())+1;
    flux.write((char*)&size,sizeof(int));
    flux.write(pCli.getAdresse(),size);

    size = pCli.getNumero(); // NUMERO
    flux.write((char *)&size,sizeof(int));

    return flux;
}

istream& operator>> (istream& flux, Client& pCli){

    int size;
    int temp;
    char buff[250];

    flux.read((char*) &size, sizeof(int));
    flux.read(buff,size);
    pCli.setNom(buff);

    flux.read((char*) &size, sizeof(int));
    flux.read(buff,size);
    pCli.setPrenom(buff);

    flux.read((char*) &size, sizeof(int));
    flux.read(buff,size);
    pCli.setAdresse(buff);

    flux.read((char*) &temp,sizeof(int));
    pCli.setNumero(temp);


    return flux;
}

int Client::operator<(const Client& pCLi){
    if(this->numero<pCLi.getNumero()){
        return 1;
    }
    else{
        return 0;
    }
}
int Client::operator>(const Client& pCLi){
    if(this->numero>pCLi.getNumero()){
        return 1;
    }
    else{
        return 0;
    }
}
