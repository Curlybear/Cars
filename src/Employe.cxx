/*
 * Employe.cxx
 *
 *  Created on: Sep 20, 2014
 *      Author: curlybear
 */

#include "Employe.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include "InvalidFonctionException.h"
#include "InvalidPasswordException.h"

using namespace std;

char * Employe::ADMINISTRATIF = "Administratif";
char * Employe::VENDEUR = "Vendeur";

Employe::Employe():Personne(){
	numero = 0;
	fonction = NULL;
	motDePasse = NULL;
	login = NULL;

	setLogin("DefaultLogin");
	setMotDePasse("DefaultMDP2");
	setFonction(Employe::ADMINISTRATIF);
}
Employe::Employe(const Employe& pEmp){
	nom = NULL;
	prenom = NULL;
	numero = 0;
	fonction = NULL;
	motDePasse = NULL;
	login = NULL;

	setNom(pEmp.getNom());
	setPrenom(pEmp.getPrenom());
	setLogin(pEmp.getLogin());
	setMotDePasse(pEmp.getMotDePasse());
	setFonction(pEmp.getFonction());
	numero = pEmp.getNumero();
}

Employe::Employe(const char* pLogin):Personne(){
	numero = 0;
	fonction = NULL;
	motDePasse = NULL;
	login = NULL;

	setLogin(pLogin);
	setMotDePasse("DefaultMDP2");
	setFonction(Employe::ADMINISTRATIF);
}

Employe::Employe(const char* pNom, const char* pPrenom, const int pNumero, const char * pLogin, const char * pFonction){
	nom = NULL;
	prenom = NULL;
	numero = 0;
	fonction = NULL;
	motDePasse = NULL;
	login = NULL;

	setNom(pNom);
	setPrenom(pPrenom);
	setLogin(pLogin);
	setFonction(pFonction);
	setMotDePasse("DefaultMDP2");
	numero = pNumero;
}

Employe::~Employe(){
	if(login)
		delete[] login;
	if(motDePasse)
		delete[] motDePasse;
	if(fonction)
		delete[] fonction;
}

const char* Employe::getFonction() const{
	return fonction;
}
const char* Employe::getLogin() const{
	return login;
}
const char* Employe::getMotDePasse() const{
	if(motDePasse)
		return motDePasse;
	else
		return "NoPass";
}
const int Employe::getNumero() const{
	return numero;
}

const int Employe::getRole() const{
	if(strcmp(fonction,Employe::ADMINISTRATIF)==0){
		return 0;
	}
	else{
		return 1;
	}
}

void Employe::setFonction(const char* pFonction){
	if(fonction)
	{
		delete fonction;
	}

	if(pFonction)
	{
		if(strcmp(pFonction,Employe::ADMINISTRATIF)==0 ||strcmp(pFonction,Employe::VENDEUR)==0)
		{
			this->fonction=new char[strlen(pFonction)+1];
			strcpy(fonction,pFonction);
		}
		else{
			this->fonction=NULL;
			throw InvalidFonctionException("Fonction invalide!");
		}
	}
	else
		this->fonction=NULL;
}
void Employe::setLogin(const char* pLogin){
	if(login)
	{
		delete login;
	}

	if(pLogin)
	{
		this->login=new char[strlen(pLogin)+1];
		strcpy(login,pLogin);
	}
	else
		this->login=NULL;
}
void Employe::setMotDePasse(const char* pMotDePasse){
	if(motDePasse)
	{
		delete motDePasse;
		motDePasse=NULL;
	}

	if(pMotDePasse)
	{
		checkMDP(pMotDePasse);
		this->motDePasse=new char[strlen(pMotDePasse)+1];
		strcpy(motDePasse,pMotDePasse);
	}

}
void Employe::setNumero(const int pNumero){
	numero = pNumero;
}

void Employe::checkMDP(const char * pMotDePasse){
	bool digit=false, letter=false, temp=false;

	if(strlen(pMotDePasse)<8){
		throw InvalidPasswordException("Le mot de passe doit faire plus de 8 caracteres");
	}
	else{
		for(int i=0; i<strlen(pMotDePasse)+1 && (digit==true && letter==true)==false ; i++){
			temp = isdigit(pMotDePasse[i]);
			if(temp == true){
				digit = true;
			}
			else{
				letter = true;
			}
		}
		if(digit == false || letter == false){
			throw InvalidPasswordException("Le mot de passe doit au moins contenir un chiffre et un lettre");
		}
	}
}

void Employe::Affiche(){
	cout << "EMPLOYE" << endl;
	cout << "Nom: " << getNom() << endl;
	cout << "Prenom: " << getPrenom() << endl;
	cout << "Login: " << getLogin() << endl;
	cout << "MdP: " << getMotDePasse() << endl;
	cout << "Fonction: " << getFonction() << endl;
	cout << "Numero: " << getNumero() << endl;
}

const char * Employe::toString(){
	ostringstream oss;
	oss << getFonction() << ":" << getNom() << "#" << getPrenom() << "#" << getLogin() << "#" << getMotDePasse() << "#" << getFonction() << "#" << getNumero();
	return oss.str().c_str();
}

Employe& Employe::operator=(const Employe& pEmp){
	this->setNom(pEmp.nom);
	this->setPrenom(pEmp.prenom);
	this->setNumero(pEmp.numero);
	this->setLogin(pEmp.login);
	this->setMotDePasse(pEmp.motDePasse);
	this->setFonction(pEmp.fonction);

	return *this;
}

bool Employe::operator!=(const Employe& pEmploye){
	return strcmp(this->getLogin(),pEmploye.getLogin());
}

ostream& operator<<( ostream& flux, const Employe& pEmp){

	int size;

	size = strlen(pEmp.getNom())+1;
	flux.write((char*)&size,sizeof(int));
	flux.write(pEmp.getNom(),size);

	size = strlen(pEmp.getPrenom())+1;
	flux.write((char*)&size,sizeof(int));
	flux.write(pEmp.getPrenom(),size);

	size = strlen(pEmp.getLogin())+1;
	flux.write((char*)&size,sizeof(int));
	flux.write(pEmp.getLogin(),size);

	size = strlen(pEmp.getMotDePasse())+1;
	flux.write((char*)&size,sizeof(int));
	flux.write(pEmp.getMotDePasse(),size);

	size = pEmp.getNumero(); // NUMERO
	flux.write((char *)&size,sizeof(int));

	size = strlen(pEmp.getFonction())+1;
	flux.write((char*)&size,sizeof(int));
	flux.write(pEmp.getFonction(),size);

	return flux;
}

istream& operator>> (istream& flux, Employe& pEmp){
	int size;
	int temp;
	char buff[50];

	cout << ">>1" << endl;
	flux.read((char*) &size, sizeof(int));
	flux.read(buff,size);
	pEmp.setNom(buff);
	cout << ">>2" << endl;
	flux.read((char*) &size, sizeof(int));
	flux.read(buff,size);
	pEmp.setPrenom(buff);
	cout << ">>3" << endl;
	flux.read((char*) &size, sizeof(int));
	flux.read(buff,size);
	pEmp.setLogin(buff);
	cout << ">>4" << endl;
	flux.read((char*) &size, sizeof(int));
	flux.read(buff,size);
	pEmp.setMotDePasse(buff);
	cout << ">>5" << endl;
	flux.read((char*)&temp,sizeof(int));
	pEmp.setNumero(temp);
	cout << ">>6" << endl;
	flux.read((char*) &size, sizeof(int));
	flux.read(buff,size);
	pEmp.setFonction(buff);
	cout << ">>7" << endl;
	return flux;
}

int Employe::operator<(const Employe& pEmp){
	if(this->numero<pEmp.getNumero()){
		return 1;
	}
	else{
		return 0;
	}
}
int Employe::operator>(const Employe& pEmp){
	if(this->numero>pEmp.getNumero()){
		return 1;
	}
	else{
		return 0;
	}
}
