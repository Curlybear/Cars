#include "Date.h"

Date::Date() {
    time_t t = time(0);
    struct tm* now = localtime(&t);
    this->jour = now->tm_mday;
    this->mois = now->tm_mon + 1;
    this->annee = now->tm_year + 1900;
}

Date::Date(int jour, int mois, int annee) {
    this->jour = jour;
    this->mois = mois;
    this->annee = annee;
}

Date::Date(const Date& pDate) {
    this->jour = pDate.jour;
    this->mois = pDate.mois;
    this->annee = pDate.annee;
}

int Date::getJour() const {
    return this->jour;
}

int Date::getMois() const {
    return this->mois;
}

int Date::getAnnee() const {
    return this->annee;
}

void Date::setJour(int jour) {
    this->jour = jour;
}

void Date::setMois(int mois) {
    this->mois = mois;
}

void Date::setAnnee(int annee) {
    this->annee = annee;
}

void Date::Affiche(){
    cout << "\tDate" << jour << "/" << mois << "/" << annee << endl;
}

Date& Date::operator=(const Date& pDate) {
    this->jour = pDate.jour;
    this->mois = pDate.mois;
    this->annee = pDate.annee;
    return *this;
}

bool Date::operator==(const Date& pDate) const {
    return this->jour == pDate.jour
        && this->mois == pDate.mois
        && this->annee == pDate.annee;
}

bool Date::operator!=(const Date& pDate) const {
    return this->jour != pDate.jour
        || this->mois != pDate.mois
        || this->annee != pDate.annee;
}

bool Date::operator>(const Date& pDate) const {
    if(this->annee > pDate.annee) {
        return true;
    }
    if(this->annee == pDate.annee) {
        if(this->mois > pDate.mois) {
            return true;
        }
        if(this->mois == pDate.mois) {
            return this->jour > pDate.jour;
        }
    }
    return false;
}

bool Date::operator<(const Date& pDate) const {
    if(this->annee < pDate.annee) {
        return true;
    }
    if(this->annee == pDate.annee) {
        if(this->mois < pDate.mois) {
            return true;
        }
        if(this->mois == pDate.mois) {
            return this->jour < pDate.jour;
        }
    }
    return false;
}

bool Date::operator>=(const Date& pDate) const {
    return *this > pDate || *this == pDate;
}

bool Date::operator<=(const Date& pDate) const {
    return *this < pDate || *this == pDate;
}

ostream& operator<<(ostream& flux, const Date& pDate) {
    int size;

    size = pDate.getJour(); // jour
    flux.write((char *)&size,sizeof(int));

    size = pDate.getMois(); // mois
    flux.write((char *)&size,sizeof(int));

    size = pDate.getAnnee(); // annee
    flux.write((char *)&size,sizeof(int));
}

istream& operator>> (istream& flux, Date& pDate){
    
    int size;
    int temp;

    flux.read((char*)&temp,sizeof(int));
    pDate.jour=temp;

    flux.read((char*)&temp,sizeof(int));
    pDate.mois=temp;

    flux.read((char*)&temp,sizeof(int));
    pDate.annee=temp;

    return flux;
}