/*
 * FichierUser.h
 *
 *  Created on: 25 juil. 2014
 *      Author: curlybear
 */

#ifndef FICHIERUSER_H_
#define FICHIERUSER_H_

#include <iostream>
#include <fstream>
#include "Employe.h"
#include "ListeTriee.h"

class FichierUser {
private:
	string nomFichier;
public:
	FichierUser();
	FichierUser(string);
	virtual ~FichierUser();

	void save(Employe&);
	void list();
	void loadAll(ListeTriee<Employe>&);
	void saveAll(ListeTriee<Employe>&);
	bool checkFile();
};

#endif /* FICHIERUSER_H_ */
