/*
 * Voiture.cxx
 *
 *  Created on: Sep 16, 2014
 *      Author: curlybear
 */
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "Modele.h"
#include "Voiture.h"
#include "StreamUtils.h"

using namespace std;

Voiture::Voiture(){
	nom = NULL;
	setNom("defaultVoiture");
	setModele(Modele());
	for(int i=0;i<10;i++){options[i]=NULL;}
}
Voiture::Voiture(const Voiture& pVoiture){
	nom = NULL;
	setNom(pVoiture.getNom());
	setModele(pVoiture.getModele());
	for(int i=0;i<10;i++){
		if(pVoiture.getOption(i)!=NULL){
			options[i] = new Option(*pVoiture.getOption(i));
		}
		else{
			options[i]=NULL;
		}
	}
}
Voiture::Voiture(const char* pNom, const Modele pModele){
	nom = NULL;
	setNom(pNom);
	setModele(pModele);
	for(int i=0;i<10;i++){options[i]=NULL;}
}
Voiture::~Voiture(){
	if(this->nom){
		delete[] this->nom;
	}

	for(int i=0;i<10;i++){
		if(options[i]!=NULL){
			delete options[i];
		}
	}
}

const void Voiture::Affiche() const{
	cout << "Voiture" << endl;
	cout << "\tNom:" << getNom() << endl;
	getModele().Affiche();
	for(int i=0; i<10 ; i++){
		if(options[i]!=NULL){
			options[i]->Affiche();
		}
	}
}

void Voiture::AjouteOption(const Option pOpt){
	int i;

	for(i=0 ; i<10 && options[i]!=NULL;i++);

	if(i<10 && options[i]==NULL){
		options[i] = new Option(pOpt);
	}
}

void Voiture::RetireOption(const char * pNomOption){
	int i;

	for(i=0 ; i<10 ; i++){
		if(options[i]!=NULL){
			if(strcmp(options[i]->getCode(), pNomOption)==0){
				delete options[i];
				options[i] = NULL;
				i=10;
			}
		}
	}
}

void Voiture::setNom(const char* pNom){
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
void Voiture::setModele(const Modele pModele){
	modele.setNom(pModele.getNom());
	modele.setPuissance(pModele.getPuissance());
	modele.setDiesel(pModele.isDiesel());
	modele.setPrixDeBase(pModele.getPrixDeBase());
}

const char * Voiture::getNom() const{
	return nom;
}
const Modele Voiture::getModele() const{
	return modele;
}

const float Voiture::getPrix() const{
	float prixTotal;

	prixTotal = modele.getPrixDeBase();

	for(int i=0 ; i<10 ; i++){
		if(options[i]!=NULL){
			prixTotal +=options[i]->getPrix();
		}
	}

	return prixTotal;
}

const Option* Voiture::getOption(int i) const{
	if(options[i]!=NULL){
		return options[i];
	}
	else{
		return NULL;
	}
}

void Voiture::Save() const{
	ofstream fichier( (string(getNom())+".car").c_str(), fstream::out | fstream::trunc | fstream::binary);
	int temp=0;
	int size;

	size = strlen(this->getNom());
	fichier.write((char*)&size,sizeof(int));
	fichier.write(this->getNom(), size);

	this->modele.Save(fichier);

	for(int i=0;i<10;i++){
		if(this->getOption(i)!=NULL){
			temp++;
		}
	}

	fichier.write((char *)&temp,sizeof(int));

	for(int i=0;i<10;i++){
		if(this->getOption(i)!=NULL){
			options[i]->Save(fichier);
		}
	}


	fichier.close();
}

void Voiture::Load(const char* pFichNom){
	ifstream fichier(&pFichNom[0], fstream::in | fstream::binary);
	int temp=0;
	int size;
	char buff[50];


	fichier.read((char*) &size, sizeof(int));
	fichier.read(buff,size);
	this->setNom(buff);

	this->modele.Load(fichier);

	fichier.read((char*)temp,sizeof(int));
	for(int i=0;i<temp;i++){
		if(options[i]){
			delete options[i];
		}
		options[i] = new Option();
		options[i]->Load(fichier);
	}

	for(int i=temp; i<10;i++){
		if(options[i]){
			delete options[i];
		}
	}

	fichier.close();
}


Voiture& Voiture::operator=(const Voiture& pVoiture){
	setModele(pVoiture.getModele());
	setNom(pVoiture.getNom());

	for(int i=0;i<10;i++){
		if(options[i]){
			delete options[i];
		}
		if(pVoiture.getOption(i)!=NULL){
			options[i] = new Option(*pVoiture.getOption(i));
		}
		else{
			options[i]=NULL;
		}
	}

	return *this;
}

bool Voiture::operator<(const Voiture& pVoiture){
	return getPrix() < pVoiture.getPrix();
}

bool Voiture::operator>(const Voiture& pVoiture){
	return getPrix() > pVoiture.getPrix();
}

bool Voiture::operator==(const Voiture& pVoiture){
	return getPrix() == pVoiture.getPrix();
}


Voiture operator+(const Voiture& pVoiture, const Option& pOption){
	Voiture temp(pVoiture);

	temp.AjouteOption(pOption);

	return temp;
}

Voiture operator-(const Voiture& pVoiture, const Option& pOption){
	Voiture temp(pVoiture);

	temp.RetireOption(pOption.getCode());

	return temp;
}

Voiture operator-(const Voiture& pVoiture, const char * pOptionCode){
	Voiture temp(pVoiture);

	temp.RetireOption(pOptionCode);

	return temp;
}

ostream& operator<<( ostream& flux, const Voiture& pVot){
	flux <<	pVot.nom << endl
	<< pVot.modele;

	return flux;
}

istream& operator>> (istream& flux, Voiture& pVot){

	char buffer[50];

	flux >> buffer;
	pVot.setNom(buffer);
	flux >> pVot.modele;

	flux.clear();
	flux.ignore();

	return flux;
}
