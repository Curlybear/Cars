/*
 * Personne.h
 *
 *  Created on: Sep 20, 2014
 *      Author: curlybear
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_
#include <iostream>

using namespace std;

class Personne {
    friend ostream& operator<< (ostream& , const Personne&);
    friend istream& operator>> (istream& , Personne&);
protected:
    char * nom;
    char * prenom;
public:
    Personne();
    Personne(const char * pNom, const char * pPrenom);
    Personne(const Personne&);
    virtual ~Personne();

    const char* getNom() const;
    const char* getPrenom() const;
    void setNom(const char* pNom);
    void setPrenom(const char* pPrenom);

    void Affiche();
    virtual const char * toString();

    Personne& operator=(const Personne&);
    int comparaison(const char*, const char*);
    int operator<(const Personne&);
    int operator>(const Personne&);
};

#endif /* PERSONNE_H_ */
