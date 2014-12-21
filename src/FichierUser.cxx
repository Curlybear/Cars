/*
 * FichierUser.cxx
 *
 *  Created on: 25 juil. 2014
 *      Author: curlybear
 */

#include "FichierUser.h"
#include "ListeTriee.h"

FichierUser::FichierUser() {
	nomFichier = "DefaultFichierUser.dat";
}

FichierUser::FichierUser(string nomFich) {
	nomFichier = nomFich;
}

FichierUser::~FichierUser() {

}

void FichierUser::save(Employe& user){
	fstream fichier(&nomFichier[0], fstream::out | fstream::app | fstream::binary);
	fichier << user;
	fichier.close();
}

void FichierUser::list(){
	Employe user;

	if(checkFile()){
		fstream fichier(&nomFichier[0], fstream::in | fstream::binary);

		while(fichier >> user){
			user.Affiche();
		};
		fichier.close();
	}
}

void FichierUser::loadAll(ListeTriee<Employe>& liste){
	Employe user;
	if(checkFile()){
		fstream fichier(&nomFichier[0], fstream::in | fstream::binary);

		liste.read(fichier);
//		cout << "DEBUG1" << endl;
//		while(fichier >> user){
//			cout << "DEBUG2" << endl;
//			user.Affiche();
//			liste.insere(user);
//		};
		fichier.close();
	}
}

void FichierUser::saveAll(ListeTriee<Employe>& liste){

	ofstream fichier(&nomFichier[0], fstream::out | fstream::trunc | fstream::binary);
	liste.write(fichier);
	fichier.close();
}

bool FichierUser::checkFile()
{
	ifstream ifile(&nomFichier[0], fstream::binary);
	return ifile;
}
