/*
 * Client.h
 *
 *  Created on: Sep 20, 2014
 *      Author: curlybear
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Personne.h"

class Client : public Personne{
    friend ostream& operator<< (ostream& , const Client&);
    friend istream& operator>> (istream& , Client&);
private:
    int numero;
    char * adresse;
public:
    Client();
    Client(const Client&);
    Client(const char* pNom, const char* pPrenom, const int pNumero, const char* pAdresse);
    virtual ~Client();

    const char* getAdresse() const;
    const int getNumero() const;
    void setAdresse(const char* pAdresse);
    void setNumero(const int pNumero);

    void Affiche();
    void AfficheLigne();
    const char * toString();

    Client& operator=(const Client&);
    bool operator!=(const Client&);
    int operator<(const Client&);
    int operator>(const Client&);
};

#endif /* CLIENT_H_ */
