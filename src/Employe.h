/*
 * Employe.h
 *
 *  Created on: Sep 20, 2014
 *      Author: curlybear
 */

#ifndef EMPLOYE_H_
#define EMPLOYE_H_

#include "Personne.h"


class Employe : public Personne {
    friend ostream& operator<< (ostream& , const Employe&);
    friend istream& operator>> (istream& , Employe&);
private:
    int numero;
    char* login;
    char* motDePasse;
    char* fonction;
public:
    static char* ADMINISTRATIF;
    static char* VENDEUR;

    Employe();
    Employe(const Employe&);
    Employe(const char* pLogin);
    Employe(const char* pNom, const char* pPrenom, const int pNumero, const char * pLogin, const char * pFonction);
    virtual ~Employe();

    const char* getFonction() const;
    const char* getLogin() const;
    const char* getMotDePasse() const;
    const int getNumero() const;
    const int getRole() const;

    void setFonction(const char* fonction);
    void setLogin(const char* login);
    void setMotDePasse(const char* motDePasse);
    void setNumero(const int numero);

    void checkMDP(const char * pMotDePasse);

    void Affiche();
    void AfficheLigne();
    const char * toString();

    Employe& operator=(const Employe&);
    bool operator!=(const Employe&);
    int operator<(const Employe&);
    int operator>(const Employe&);
};

#endif /* EMPLOYE_H_ */
