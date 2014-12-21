/*
 * Modele.cxx
 *
 *  Created on: Sep 16, 2014
 *      Author: curlybear
 */

#include <iostream>
#include <fstream>
#include <string.h>
#include "Modele.h"
#include "StreamUtils.h"

using namespace std;

Modele::Modele(){
	nom = NULL;
	setNom("defaultModele");
	puissance = 0;
	diesel = false;
	prixDeBase = 0;
}

Modele::Modele(const Modele& pMod){
	nom = NULL;
	this->setNom(pMod.getNom());
	puissance = pMod.getPuissance();
	diesel = pMod.isDiesel();
	prixDeBase = pMod.getPrixDeBase();
}

Modele::Modele(const char*pNom, const int pPuissance, const bool pDiesel, const float pPrixDeBase){
	nom = NULL;
	setNom(pNom);
	puissance = pPuissance;
	diesel = pDiesel;
	prixDeBase = pPrixDeBase;
}

Modele::~Modele(){
	if(this->nom){
		delete[] this->nom;
	}
}

const void Modele::Affiche() const{
	cout << "Modele" << endl;
	cout << "\tNom:" << getNom() << endl;
	cout << "\tPuissance:" << getPuissance() << " ch"<< endl;
	cout << "\tCarburant:";
	if(isDiesel()){
		cout << "Diesel" << endl;
	}
	else{
		cout << "Essence" << endl;
	}
	cout << "\tPrix de base:" << getPrixDeBase() << " euros" << endl;
}

void Modele::setNom(const char* pNom){
	if(this->nom)
	{
		delete this->nom;
	}

	if(pNom)
	{
		this->nom=new char[strlen(pNom)+1];
		strcpy(this->nom,pNom);
	}
	else
		this->nom=NULL;
}
void Modele::setPuissance(const int pPuissance){
	puissance = pPuissance;
}
void Modele::setDiesel(const bool pDiesel){
	diesel = pDiesel;
}
void Modele::setPrixDeBase(const float pPrixDeBase){
	prixDeBase = pPrixDeBase;
}

const char * Modele::getNom() const{
	return nom;
}
int Modele::getPuissance() const{
	return puissance;
}
bool Modele::isDiesel() const{
	return diesel;
}
float Modele::getPrixDeBase() const{
	return prixDeBase;
}

Modele& Modele::operator=(const Modele& pMod){
	this->setNom(pMod.nom);
	this->setPuissance(pMod.getPuissance());
	this->setDiesel(pMod.isDiesel());
	this->setPrixDeBase(pMod.getPrixDeBase());

	return *this;
}

void Modele::Save(ofstream& flux) const{
	int size;
	bool tempBool;
	float tempFloat;

	size = strlen(this->getNom());
	flux.write((char*)&size,sizeof(int));
	flux.write(this->getNom(),size);

	size = this->getPuissance(); // Puissance
	flux.write((char *)&size,sizeof(int));

	tempBool = this->isDiesel(); // Diesel
	flux.write((char *)&tempBool,sizeof(bool));

	tempFloat = this->getPrixDeBase(); // prixDeBase
	flux.write((char *)&tempFloat,sizeof(float));
}
void Modele::Load(ifstream& flux){

	int size;
	int temp;
	bool tempBool;
	float tempFloat;
	char buff[50];


	flux.read((char*) &size, sizeof(int));
	flux.read(buff,size);
	this->setNom(buff);

	flux.read((char*) &temp,sizeof(int));
	this->setPuissance(temp);

	flux.read((char*) &tempBool,sizeof(bool));
	this->setDiesel(tempBool);

	flux.read((char*) &tempFloat,sizeof(float));
	this->setPrixDeBase(tempFloat);
}

ostream& operator<<( ostream& flux, const Modele& pMod){
	flux <<	pMod.nom << endl
	<< pMod.puissance << endl
	<< pMod.diesel << endl
	<< pMod.prixDeBase;
	return flux;
}

istream& operator>> (istream& flux, Modele& pMod){

	char buffer[50];

	flux >> buffer;
	pMod.setNom(buffer);
	flux >> pMod.puissance;
	flux >> pMod.diesel;
	flux >> pMod.prixDeBase;
	flux.clear();
	flux.ignore();

	return flux;
}

bool Modele::operator<(const Modele& pModele){
	return this->getPrixDeBase() < pModele.getPrixDeBase();
}

bool Modele::operator>(const Modele& pModele){
	return this->getPrixDeBase() > pModele.getPrixDeBase();
}
