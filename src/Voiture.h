/*
 * Voiture.h
 *
 *  Created on: Sep 16, 2014
 *      Author: curlybear
 */

#ifndef VOITURE_H_
#define VOITURE_H_

#include "Option.h"
#include "Modele.h"
#include <iostream>

using namespace std;

class Voiture {

    friend Voiture operator+(const Voiture&, const Option&);
    friend Voiture operator-(const Voiture&, const Option&);
    friend Voiture operator-(const Voiture&, const char *);
    friend ostream& operator<< (ostream& , const Voiture&);
    friend istream& operator>> (istream& , Voiture&);

private:

    char * nom;
    Modele modele;
    Option * options[10];

public:

    Voiture();
    Voiture(const Voiture&);
    Voiture(const char*, const Modele);
    virtual ~Voiture();

    const void Affiche() const;

    void AjouteOption(const Option pOpt);
    void RetireOption(const char * pNomOption);

    void setNom(const char* pNom);
    void setModele(const Modele pModele);

    const char * getNom() const;
    const Modele getModele() const;
    const float getPrix() const;
    const Option* getOption(int i) const;

    bool checkOption(const Option&) const;
    bool appliquerRistourne(const Option&);

    void Save() const;
    void Load(const char*);

    Voiture& operator=(const Voiture&);
    bool operator<(const Voiture&);
    bool operator>(const Voiture&);
    bool operator==(const Voiture&);
};

#endif /* VOITURE_H_ */
