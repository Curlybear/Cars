/*
 * Option.cxx
 *
 *  Created on: Sep 17, 2014
 *      Author: curlybear
 */

#include "Option.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;

Option::Option() {
	intitule = NULL;
	setCode("Def");
	setIntitule("defaultIntitule");
	setPrix(0);
}

Option::Option(const Option& pOption){
	intitule = NULL;
	setCode(pOption.getCode());
	setIntitule(pOption.getIntitule());
	setPrix(pOption.getPrix());
}

Option::Option(const char pCode[]){
	intitule = NULL;
	setCode(pCode);
	setIntitule("defaultIntitule");
	setPrix(0);
}

Option::Option(const char pCode[], const char* pIntitule, const float pPrix){
	intitule = NULL;
	setCode(pCode);
	setIntitule(pIntitule);
	setPrix(pPrix);
}

Option::~Option() {
	if(this->intitule){
		delete[] this->intitule;
	}
}

const void Option::Affiche() const{
	cout << "Option" << endl;
	cout << "\tCode:" << getCode() << endl;
	cout << "\tIntitule:" << getIntitule() << endl;
	cout << "\tPrix:" << getPrix() << " euros" << endl;
}

void Option::setCode(const char pCode[]){
	strcpy(code,pCode);
}
void Option::setIntitule(const char* pIntitule){
	if(intitule)
	{
		delete intitule;
	}

	if(pIntitule)
	{
		this->intitule=new char[strlen(pIntitule)+1];
		strcpy(intitule,pIntitule);
	}
	else
		this->intitule=NULL;
}
void Option::setPrix(const float pPrix){
	prix = pPrix;
}

const char* Option::getCode() const{
	return code;
}
const char* Option::getIntitule() const{
	return intitule;
}
const float Option::getPrix() const{
	return prix;
}

void Option::Save(ofstream& flux) const{
	int size;
	float tempFloat;

	flux.write(this->getCode(),5);

	size = strlen(this->getIntitule());
	flux.write((char*)&size,sizeof(int));
	flux.write(this->getIntitule(),size);

	tempFloat = this->getPrix();
	flux.write((char *)&tempFloat,sizeof(float));
}
void Option::Load(ifstream& flux){
	int size;
	int temp;
	float tempFloat;
	char buff[50];

	flux.read(buff,5);
	this->setCode(buff);

	flux.read((char*) &size, sizeof(int));
	flux.read(buff,size);
	this->setIntitule(buff);

	flux.read((char*) &tempFloat,sizeof(float));
	this->setPrix(tempFloat);
}

Option& Option::operator=(const Option& pOpt){
	this->setCode(pOpt.code);
	this->setIntitule(pOpt.intitule);
	this->setPrix(pOpt.prix);

	return *this;
}

Option& Option::operator--(){
	this->prix = prix - 50;
	return *this;
}
Option Option::operator--(int){
	Option ret(*this);
	--(*this);
	return ret;
}

bool Option::operator==(const Option& pOption){
	return (strcmp(this->getCode(), pOption.getCode()) == 0);
}

ostream& operator<<( ostream& flux, const Option& pOpt){
	flux <<	pOpt.code << endl
	<< pOpt.intitule << endl
	<< pOpt.prix;

	return flux;
}

istream& operator>> (istream& flux, Option& pOpt){

	flux >> pOpt.code;
	flux >> pOpt.intitule;
	flux >> pOpt.prix;

	flux.clear();
	flux.ignore();

	return flux;
}
