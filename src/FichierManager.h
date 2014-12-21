/*
 * FichierManager.h
 *
 *  Created on: Dec 9, 2014
 *      Author: curlybear
 */

#ifndef FICHIERMANAGER_H_
#define FICHIERMANAGER_H_

#include <iostream>
#include <fstream>
#include "Employe.h"
#include "ListeTriee.h"

template <class T>
class FichierManager {

private:
	string nomFichier;
public:
	FichierManager();
	FichierManager(string);
	virtual ~FichierManager();

	void save(T&);
	void list();
	void loadAll(ListeTriee<T>&);
	void saveAll(ListeTriee<T>&);
	bool checkFile();
	void deleteFile();
};


template<class T> FichierManager<T>::FichierManager() {
	nomFichier = "DefaultFichierUser.dat";
}

template<class T> FichierManager<T>::FichierManager(string nomFich) {
	nomFichier = nomFich;
}

template<class T> FichierManager<T>::~FichierManager() {

}

template<class T> void FichierManager<T>::save(T& user){
	fstream fichier(&nomFichier[0], fstream::out | fstream::app | fstream::binary);
	fichier << user;
	fichier.close();
}

template<class T> void FichierManager<T>::list(){
	T user;

	if(checkFile()){
		fstream fichier(&nomFichier[0], fstream::in | fstream::binary);

		while(fichier >> user){
			user.Affiche();
		};
		fichier.close();
	}
}

template<class T> void FichierManager<T>::loadAll(ListeTriee<T>& liste){
	T user;
	if(checkFile()){
		fstream fichier(&nomFichier[0], fstream::in | fstream::binary);

		liste.read(fichier);
		fichier.close();
	}
}

template<class T> void FichierManager<T>::saveAll(ListeTriee<T>& liste){

	ofstream fichier(&nomFichier[0], fstream::out | fstream::trunc | fstream::binary);
	liste.write(fichier);
	fichier.close();
}

template<class T> bool FichierManager<T>::checkFile()
{
	ifstream ifile(&nomFichier[0], fstream::binary);
	return ifile;
}

template<class T> void FichierManager<T>::deleteFile(){
	remove(&nomFichier[0]);
}


#endif /* FICHIERMANAGER_H_ */
