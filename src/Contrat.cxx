#include "Contrat.h"
#include <cstring>
#include <cstdlib>

Contrat::Contrat() {
    this->voiture = NULL;
}

Contrat::Contrat(int id, int idVendeur, int idClient, const Date& date, Voiture* voiture, float ristourne)
    : id(id), idVendeur(idVendeur), idClient(idClient), date(date), voiture(new Voiture(*voiture)), ristourne(ristourne) {}

Contrat::Contrat(const Contrat& pCont){
    this->voiture = NULL;
    id=pCont.id;
    idVendeur=pCont.idVendeur;
    idClient=pCont.idClient;
    setVoiture(pCont.getVoiture());
    date = pCont.date;
    ristourne=pCont.ristourne;
}

Contrat::~Contrat() {
    if(this->voiture) {
        delete this->voiture;
    }
}

int Contrat::getId() const {
    return this->id;
}

int Contrat::getIdVendeur() const {
    return this->idVendeur;
}

int Contrat::getIdClient() const {
    return this->idClient;
}

const Date& Contrat::getDate() const {
    return this->date;
}

Date& Contrat::getDate() {
    return this->date;
}

Voiture* Contrat::getVoiture() const {
    return this->voiture;
}

void Contrat::setVoiture(Voiture* pVoiture) {
    if(this->voiture) {
        delete this->voiture;
    }
    this->risourne= 0;
    this->voiture = new Voiture(*pVoiture);
}

float Contrat::getRistourne() const {
    return this->ristourne;
}

void Contrat::setRistourne(float ristourne) {
    if(this->voiture->getPrix()-ristourne>0){
        this->ristourne = ristourne;
    }
}

void Contrat::Affiche(){
    cout << "Contrat" << endl;
    cout << "\tId contrat: " << id << endl;
    cout << "\tId vendeur: " << idVendeur << endl;
    cout << "\tId client: " << idClient << endl;
    date.Affiche();
    cout << "\tNom du projet: " << voiture->getNom() << endl;
    cout << "\tRistourne: " << ristourne << endl;
}

void Contrat::AfficheLigne(){
    cout << id << "\t" << idVendeur << "\t" << idClient << "\t" << date.getJour() << "/" << date.getMois() << "/" << date.getAnnee() << "\t" << voiture->getNom() << "\t" << ristourne << endl;
}

bool Contrat::operator==(const Contrat& pContrat) const {
    return this->date == pContrat.date;
}

bool Contrat::operator!=(const Contrat& pContrat) const {
    return this->date != pContrat.date;
}

bool Contrat::operator>(const Contrat& pContrat) const {
    return this->date > pContrat.date;
}

bool Contrat::operator<(const Contrat& pContrat) const {
    return this->date < pContrat.date;
}

bool Contrat::operator>=(const Contrat& pContrat) const {
    return this->date >= pContrat.date;
}

bool Contrat::operator<=(const Contrat& pContrat) const {
    return this->date <= pContrat.date;
}

Contrat& Contrat::operator=(const Contrat& pCont){
    id=pCont.id;
    idVendeur=pCont.idVendeur;
    idClient=pCont.idClient;
    setVoiture(pCont.getVoiture());
    date = pCont.date;
    ristourne=pCont.ristourne;

    return *this;
}

ostream& operator<<(ostream& flux, const Contrat& pContrat) {

    int size;

    size = pContrat.getId(); // ID
    flux.write((char *)&size,sizeof(int));

    size = pContrat.getIdVendeur(); // IDVENDEUR
    flux.write((char *)&size,sizeof(int));

    size = pContrat.getIdClient(); // IDCLIENT
    flux.write((char *)&size,sizeof(int));

    flux << pContrat.date;

    size = strlen(pContrat.getVoiture()->getNom())+1;
    flux.write((char*)&size,sizeof(int));
    flux.write(pContrat.getVoiture()->getNom(),size);

    size = pContrat.getRistourne(); // RISTOURNE
    flux.write((char *)&size,sizeof(float));

    return flux;
}

istream& operator>> (istream& flux, Contrat& pContrat){
    
    int size;
    int temp;
    char buff[50];

    flux.read((char*)&temp,sizeof(int));
    pContrat.id=temp;

    flux.read((char*)&temp,sizeof(int));
    pContrat.idVendeur=temp;

    flux.read((char*)&temp,sizeof(int));
    pContrat.idClient=temp;

    flux >> pContrat.date;

    flux.read((char*) &size, sizeof(int));
    flux.read(buff,size);
    pContrat.setVoiture(new Voiture());

    pContrat.voiture->Load((string(buff)+".car").c_str());

    flux.read(buff,sizeof(float));
    pContrat.ristourne=atof(buff);

    return flux;
}

