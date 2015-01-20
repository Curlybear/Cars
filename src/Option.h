/*
 * Option.h
 *
 *  Created on: Sep 17, 2014
 *      Author: curlybear
 */

#ifndef OPTION_H_
#define OPTION_H_

#include <iostream>
using namespace std;

class Option {
    friend ostream& operator<< (ostream& , const Option&);
    friend istream& operator>> (istream& , Option&);
private:
    char code[5];
    char * intitule;
    float prix;
public:
    Option();
    Option(const Option&);
    Option(const char pCode[]);
    Option(const char pCode[], const char* pIntitule, const float pPrix);
    virtual ~Option();

    const void Affiche() const;

    void setCode(const char pCode[]);
    void setIntitule(const char* pIntitule);
    void setPrix(const float pPrix);

    const char* getCode() const;
    const char* getIntitule() const;
    const float getPrix() const;

    void Save(ofstream& flux) const;
    void Load(ifstream& flux);

    Option& operator=(const Option&);
    Option& operator--();
    Option operator--(int);
    bool operator==(const Option& pOption);

};

#endif /* OPTION_H_ */
