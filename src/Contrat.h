#ifndef CONTRAT_H
#define CONTRAT_H

#include <iostream>

#include "Voiture.h"
#include "Date.h"

using namespace std;

class Contrat {

private:
    int id;
    int idVendeur;
    int idClient;
    Date date;
    Voiture* voiture;
    float ristourne;

public:
    Contrat();
    Contrat(int, int, int, const Date&, Voiture*, float = 0);
    ~Contrat();

    int getId() const;
    int getIdVendeur() const;
    int getIdClient() const;
    const Date& getDate() const;
    Date& getDate();
    Voiture* getVoiture() const;
    void setVoiture(Voiture*);
    float getRistourne() const;
    void setRistourne(float);

    bool operator==(const Contrat&) const;
    bool operator!=(const Contrat&) const;
    bool operator>(const Contrat&) const;
    bool operator<(const Contrat&) const;
    bool operator>=(const Contrat&) const;
    bool operator<=(const Contrat&) const;

    friend ostream& operator<<(ostream&, const Contrat&);
    friend istream& operator>>(istream&, Contrat&);
};

#endif