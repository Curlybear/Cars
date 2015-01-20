/*
 * Modele.h
 *
 *  Created on: Sep 16, 2014
 *      Author: curlybear
 */

#ifndef MODELE_H_
#define MODELE_H_

#include <iostream>

using namespace std;

class Modele {
    friend ostream& operator<< (ostream& , const Modele&);
    friend istream& operator>> (istream& , Modele&);
private:

    char * nom;
    int puissance;
    bool diesel;
    float prixDeBase;

public:

    Modele();
    Modele(const Modele&);
    Modele(const char*, const int, const bool, const float);
    virtual ~Modele();

    const void Affiche() const;

    void setNom(const char* pNom);
    void setPuissance(const int pPuissance);
    void setDiesel(const bool pDiesel);
    void setPrixDeBase(const float pPrixDeBase);

    const char * getNom() const;
    int getPuissance() const;
    bool isDiesel() const;
    float getPrixDeBase() const;

    Modele& operator=(const Modele&);

    void Save(ofstream& flux) const;
    void Load(ifstream& flux);

    bool operator<(const Modele&);
    bool operator>(const Modele&);

};

#endif /* MODELE_H_ */
