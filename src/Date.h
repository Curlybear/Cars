#ifndef DATE_H
#define DATE_H

#include <ctime>
#include <iostream>

using namespace std;

class Date {

private:

    int jour;
    int mois;
    int annee;

public:
    Date();
    Date(int, int, int);
    Date(const Date&);
    ~Date() {}

    int getJour() const;
    int getMois() const;
    int getAnnee() const;
    void setJour(int);
    void setMois(int);
    void setAnnee(int);

    void Affiche();

    Date& operator=(const Date&);

    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;
    bool operator>(const Date&) const;
    bool operator<(const Date&) const;
    bool operator>=(const Date&) const;
    bool operator<=(const Date&) const;

    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
};

#endif