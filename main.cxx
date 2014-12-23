/*
 * main.cxx
 *
 *  Created on: huehuehue
 *      Author: curlybear
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <cstring>
#include "src/Employe.h"
#include "src/FichierUser.h"
#include "src/FichierManager.h"
#include "src/ListeTriee.h"
#include "src/Liste.h"
#include "src/Menu.h"
#include "src/InvalidFonctionException.h"
#include "src/InvalidPasswordException.h"
#include "src/InvalidRequestException.h"
#include "src/Option.h"
#include "src/Voiture.h"
#include "src/Modele.h"
#include "src/Client.h"
#include "src/Contrat.h"
#include "src/Date.h"

using namespace std;

int affichageMenu(const Employe& usr, int menuEnCours = -1);
Employe login();
void clrscreen();
void pause();

//Admin-User
void infoUser();
void newUser();
void changePassword();
void resetPassword();
void listUser();

//Vendeur-Client
void newClient();
void delClient();

void newVoiture();
void loadVoiture();

void loadOptions();
void loadModeles();

void afficherModeles();
void afficherOptions();

ListeTriee<Employe> listeUsers;
ListeTriee<Client> listeClients;
ListeTriee<Modele> listeModeles;
ListeTriee<Contrat> listeContrat;
Liste<Option> listeOptions;

FichierManager<Employe> fichierUser("Users.dat");
FichierManager<Client> fichierClient("Client.dat");
FichierManager<Contrat> fichierContrat("Contrat.dat");

Employe userConnected;
Voiture* currentCar=NULL;

int main() {

	int choix, lastMenu = -1;
	bool loop = true;

	fichierUser.loadAll(listeUsers);
	fichierClient.loadAll(listeClients);
	fichierContrat.loadAll(listeContrat);
	loadModeles();
	loadOptions();

	listeUsers.Affiche();
	listeClients.Affiche();
	listeContrat.Affiche();
	listeOptions.Affiche();
	listeModeles.Affiche();

	userConnected = login();

	userConnected.Affiche();

	choix = affichageMenu(userConnected);
	while (loop) {

		switch (choix) {
		case 11: // ---------------------------MENU CLIENT---------------------------    OK
			// Ajouter un nouveau client
			newClient();
			lastMenu = 2;
			break;
		case 12:
			// Supprimer un client
			delClient();
			lastMenu = 2;
			break;
		case 13:
			// Afficher la liste des clients
			listeClients.Affiche();
			lastMenu = 2;
			break;
		case 21: // ---------------------------MENU PROJET---------------------------
			// Afficher la liste des modèles
			afficherModeles();
			lastMenu = 3;
			break;
		case 22:
			// Afficher la liste des options
			afficherOptions();
			lastMenu = 3;
			break;
		case 23:
			// Nouvelle voiture
			newVoiture();
			lastMenu = 3;
			break;
		case 24:
			loadVoiture();
			// Charger une voiture
			lastMenu = 3;
			break;
		case 25:
			currentCar->Affiche();
			// Afficher la voiture en cours
			lastMenu = 3;
			break;
		case 26:
			// Ajouter une option à la voiture en cours
			lastMenu = 3;
			break;
		case 27:
			// Retirer une option à la voiture en cours
			lastMenu = 3;
			break;
		case 28:
			// Appliquer une ristourne à une option de la voiture en cours
			lastMenu = 3;
			break;
		case 29:
			// Enregistrer la voiture en cours
			lastMenu = 3;
			break;
		case 31: // ---------------------------MENU VENTE---------------------------
			// Nouveau contrat
			lastMenu = 4;
			break;
		case 32:
			// Afficher tous mes contrats
			lastMenu = 4;
			break;
		case 33:
			// Afficher un contrat et le prix de vente définitif
			lastMenu = 4;
			break;
		case 34:
			// Modifier un contrat
			lastMenu = 4;
			break;
		case 41: // ---------------------------MENU ADMIN USER--------------------------- OK
			// Afficher liste utilisateur - OK
			listUser();
			lastMenu = -1;
			break;
		case 42:
			// Afficher info d'un user - OK
			infoUser();
			lastMenu = -1;
			break;
		case 43:
			// Créer user - OK
			newUser();
			lastMenu = -1;
			break;
		case 44:
			// Reset specified user's password - OK
			resetPassword();
			lastMenu = -1;
			break;
		case 51: //---------------------------MENU ADMIN CONTRAT---------------------------
			// Afficher tous les contrats
			lastMenu = -1;
			break;
		case 52:
			// Afficher contrat spécifié
			lastMenu = -1;
			break;
		case 53:
			// Afficher les contrats et le chiffre d'affaire d'un vendeur
			lastMenu = -1;
			break;
		case 98: // CHANGEMENT DE MDP DE userConnected - OK
			changePassword();
			lastMenu = -1;
			break;
		case 99: //Nouvelle session
			userConnected = login();
			lastMenu = -1;
			break;
		case 0:
			loop = false;
			break;
		}
		pause();
		if (loop) {
			choix = affichageMenu(userConnected, lastMenu);
		}
		cout << endl << endl;
	}
	if (!listeUsers.vide()) {
		fichierUser.saveAll(listeUsers);
	}
	if (!listeClients.vide()) {
		fichierClient.saveAll(listeClients);
	}else{
		if(fichierClient.checkFile()){
			fichierClient.deleteFile();
		}
	}
	return 0;
}

int affichageMenu(const Employe& user, int menuEnCours) {

	char *optionVendeur[] = { "1. Changer de mot de passe",
			"2. Gerer les clients", "3. Gerer les projets de voiture",
			"4. Gerer les contrat vente", "0. Quitter l'application" };
	int nbMenuVendeur = 5;
	Menu menuVendeur(optionVendeur, nbMenuVendeur);
	char *optionsMenuClient[] = { "1. Ajouter un nouveau client",
			"2. Supprimer un client", "3. Afficher la liste des clients",
			"0. Retour" };
	int nbMenuClient = 4;
	Menu menuClients(optionsMenuClient, nbMenuClient);
	char *optionsMenuProjet[] = { "1. Afficher la liste des modèles",
			"2. Afficher la liste des options", "3. Nouvelle voiture",
			"4. Charger une voiture", "5. Afficher la voiture en cours",
			"6. Ajouter une option à la voiture en cours",
			"7. Retirer une option à la voiture en cours",
			"8. Appliquer une ristourne à une option de la voiture en cours",
			"9. Enregistrer la voiture en cours", "0. Retour" };
	int nbMenuProjet = 10;
	Menu menuProjet(optionsMenuProjet, nbMenuProjet);
	char *optionsMenuVente[] = { "1. Nouveau contrat",
			"2. Afficher tous mes contrats",
			"3. Afficher un contrat et le prix de vente définitif",
			"4. Modifier un contrat", "0. Retour" };
	int nbMenuVente = 5;
	Menu menuVente(optionsMenuVente, nbMenuVente);
	char *optionsAdmin[] = { "1. Changer le mot de passe",
			"2. Gestion des utilisateurs", "3. Gestion des contrats",
			"0. Quitter l'application" };
	int nbMenuAdmin = 4;
	Menu menuAdmin(optionsAdmin, nbMenuAdmin);
	char *optionsAdminUser[] = { "1. Afficher la liste des utilisateurs",
			"2. Afficher les infos d'un utilisateur",
			"3. Créer un nouvel utilisateur",
			"4. Réinitialiser le mot de passe d'un utilisateur ", "0. Retour" };
	int nbMenuAdminUser = 5;
	Menu menuAdminUser(optionsAdminUser, nbMenuAdminUser);
	char *optionsAdminContrat[] = { "1. Afficher tous les contrats",
			"2. Afficher les détails d'un contrat",
			"3. Afficher les contrats et le chiffre d’affaire d’un vendeur",
			"0. Retour" };
	int nbMenuAdminContrat = 4;
	Menu menuAdminContrat(optionsAdminContrat, nbMenuAdminContrat);

	if (user.getRole()) {
		for (;;) {
			clrscreen();
			if (menuEnCours == -1) {
				menuVendeur.showMenu(
						"\n***************************************************\n***   InpresCarSeller - ADMIN                   ***\n***************************************************");
			} else {
				menuVendeur.setChoix(menuEnCours);
			}
			clrscreen();
			switch (menuVendeur.getChoix()) {
			case 1:
				return 98;
				break;
			case 2:
				menuClients.showMenu(
						"\n***************************************************\n***   InpresCarSeller - ADMIN                   ***\n***************************************************");
				if (menuClients.getChoix() != 0) {
					return 10 + menuClients.getChoix();
				} else {
					menuEnCours = -1;
				}
				break;
			case 3:
				menuProjet.showMenu(
						"\n***************************************************\n***   InpresCarSeller - ADMIN                   ***\n***************************************************");
				if (menuProjet.getChoix() != 0) {
					return 20 + menuProjet.getChoix();
				} else {
					menuEnCours = -1;
				}
				break;
			case 4:
				menuVente.showMenu(
						"\n***************************************************\n***   InpresCarSeller - ADMIN                   ***\n***************************************************");
				if (menuVente.getChoix() != 0) {
					return 30 + menuVente.getChoix();
				} else {
					menuEnCours = -1;
				}
				break;
			case 0:
				return 0;
				break;
			}
		}
	} else {
		for (;;) {
			clrscreen();
			if (menuEnCours == -1) {
				menuAdmin.showMenu(
						"\n***************************************************\n***   InpresCarSeller - ADMIN                   ***\n***************************************************");
			} else {
				menuAdmin.setChoix(menuEnCours);
			}
			clrscreen();
			switch (menuAdmin.getChoix()) {
			case 1:
				return 98;
			case 2:

				menuAdminUser.showMenu(
						"\n***************************************************\n***   InpresCarSeller - ADMIN                   ***\n***************************************************");
				if (menuAdminUser.getChoix() != 0) {
					return 40 + menuAdminUser.getChoix();
				} else {
					menuEnCours = -1;
				}
				break;
			case 3:
				menuAdminContrat.showMenu(
						"\n***************************************************\n***   InpresCarSeller - ADMIN                   ***\n***************************************************");
				if (menuAdminContrat.getChoix() != 0) {
					return 50 + menuAdminContrat.getChoix();
				} else {
					menuEnCours = -1;
				}
				break;
			case 4:
				return 99; // Nouvelle session
				break;
			case 0:
				return 0;
				break;
			}
		}
	}
}

Employe login() {
	Employe *tempUser;
	char username[50], password[50];
	bool loop = true;
	while (loop) {
		clrscreen();
		cout << "***************************************************" << endl;
		cout << "***************    Carhuehuehue    ****************" << endl;
		cout << "***************************************************" << endl
				<< endl;
		cout << "\tUsername: ";
		cin.getline(username,50,cin.widen('\n'));
		if (fichierUser.checkFile()) {
			try{
				tempUser = new Employe(listeUsers.getElem(Employe(&username[0])));
			}catch(const InvalidRequestException& e){
				cout << e << endl;
				pause();
				continue;
			}
			if (tempUser != NULL) {
				if (strcmp(tempUser->getMotDePasse(),Employe().getMotDePasse())==0) {
					while (1) {
						try {
							cout << "\tInitialisez le password: ";
							cin.getline(password,50,cin.widen('\n'));
							tempUser->setMotDePasse(password);
							listeUsers.getElemPtr(*tempUser)->setMotDePasse(password);
						} catch (const InvalidPasswordException& exc) {
							cout << exc << endl;
							continue;
						}
						break;
					}
				} else {
					cout << "\tPassword: ";
					cin.getline(password,50,cin.widen('\n'));
				}
			}

			if (tempUser != NULL && strcmp(tempUser->getMotDePasse(), password) == 0) {
				loop = false;
			} else {
				cout << "Le mot de passe et/ou l'utilisateur n'est pas correct"
						<< endl;
				pause();
			}
		} else {
			cout << "\tPassword: ";
			cin.getline(password,50,cin.widen('\n'));
			if (strcmp(password, "admin") == 0
					&& strcmp(username, "admin") == 0) {
				loop = false;
				tempUser = new Employe();
			} else {
				cout << "Le mot de passe et/ou l'utilisateur n'est pas correct"
						<< endl;
				pause();
			}
		}
		cout << endl;

	}
	return Employe(*tempUser);
}

void infoUser() {

	char recherche[50];
	cout << "Login de l'utilisateur a afficher: ";
	cin.getline(recherche,50,cin.widen('\n'));

	Employe user;
	Employe temp(recherche);


	try{
		user = listeUsers.getElem(temp);
	}catch(const InvalidRequestException& e){
		cout << e << endl;
		return;
	}


//	if(user == NULL){
//		cout << "Utilisateur inconnu." << endl;    // TODO BREAKAGE INCOMMING
//	}
//	else{
	user.Affiche();
//	}
}

void clrscreen() {
	cout << string(50, '\n');
}

void pause() {
	cout << "Press ENTER to continue...";
	cin.get();
	cin.ignore();
}

void newUser() {
	char login[50], nom[50], prenom[50];
	char mod;
	int numero;

	cout << "Nouvel utilisateur" << endl << "---------------------" << endl;
	cout << "Login: ";
	cin >> login;
	cout << "Nom: ";
	cin >> nom;
	cout << "Prenom: ";
	cin >> prenom;
	cout << "Numero: ";
	cin >> numero;
	cout << "Admin? (y/n): ";
	cin >> mod;

	listeUsers.insere(Employe(nom, prenom, numero, login,toupper(mod) == 'Y' ? Employe::ADMINISTRATIF : Employe::VENDEUR));
}

void newClient() {
	char adresse[250], nom[50], prenom[50];
	int numero;

	cout << "Nouveau client" << endl << "---------------------" << endl;
	cout << "Nom: ";
	cin >> nom;
	cout << "Prenom: ";
	cin >> prenom;
	cout << "Adresse: ";
	cin >> adresse;
	cout << "Numero: ";
	cin >> numero;

	listeClients.insere(Client(nom, prenom, numero, adresse));
}

void newVoiture() {
	char choix;
	char nom[150];
	int nummod=0;

	if(currentCar!=NULL){
		cout << "Il y a déjà un projet en cours d'édition voulez vous le sauvegarder et commencer un nouveau projet? (y/n) : ";
		cin >> choix;
		if(toupper(choix) == 'Y'){
			currentCar->Save();
			delete currentCar;
			currentCar=NULL;
		}
		else{
			return;
		}
	}

	cout << "\nComment souhaitez-vous nommer ce nouveau projet ?: ";
	cin >> nom;
	
	while(nummod==0){
		cout << "\nQuel modèle voulez vous utiliser ? (0 pour la liste): ";
		cin >> nummod;
		if(nummod == 0){
			afficherModeles();
		}
	}

	Iterateur<Modele> it(listeModeles);
	int i=0;
	while(i+1<nummod){
		i++;
		it++;
	}

	currentCar = new Voiture(nom,(&it));
}

void loadVoiture(){

}

void delClient() {
	int numero;

	cout << "Numero du client a supprimer: ";
	cin >> numero;

	try{
		listeClients.delElem(Client(" "," ",numero," "));
	}catch(const InvalidRequestException& exc){
		cout << exc << endl;
	}
}

void changePassword() { // USERCONNECTED
	char login[50], password[50];
	Employe* tempUser = listeUsers.getElemPtr(userConnected);

	try {
		cout << "Modification du password" << endl
			 << "---------------------------------------------------"
			 << endl;
		cout << "Nouveau mot de passe: ";
		cin >> password;
		tempUser->setMotDePasse(password);
	} catch (const InvalidPasswordException& exc) {
		cout << exc << endl;
	}
}

void resetPassword() {
	char login[50];
	Employe *tempUser;

	cout << "Modification du password d'un utilisateur" << endl
		 << "---------------------------------------------------" << endl;
	cout << "Login de l'utilisateur: ";
	cin >> login;
	tempUser = listeUsers.getElemPtr(Employe(login));
	if (tempUser != NULL) {
		try {
			tempUser->setMotDePasse(Employe().getMotDePasse());
		} catch (const InvalidPasswordException& exc) {
			cout << exc << endl;
		}
	} else {
		cout << "Utilisateur inconnu" << endl;
	}
}

void listUser() {
	Iterateur<Employe> it(listeUsers);
	Employe ret = NULL;
	while (!it.end()) {
		(&it).Affiche();
	}
}

void loadOptions() {
	char buffer[100],code[50],intitule[70], temp[20];
	float prix;

	ifstream flux("Options.csv", ios::in);

	if(flux){
		flux.getline(buffer, 100, '\n');

		while(flux.peek() != EOF){
			flux.getline(code, 50, ';');
			flux.getline(intitule, 70, ';');
			flux.getline(temp, 20, '\n');
			prix = atof(temp);

			listeOptions.insere(Option(code,intitule,prix));
		}
	}
	else{
		// throw some I/O exception i guess
	}

	flux.close();
}

void loadModeles() {
	char nom[100],buffer[100];
	int puissance;
	bool diesel;
	float prix;
	char temp[20];

	ifstream flux("Modeles.csv", ios::in);

	if(flux){
		flux.getline(buffer,100,'\n');
		cout << "DEBUG MODELE" << buffer << endl;
		while(flux.peek() != EOF){
			flux.getline(nom, 100, ';');
			flux.getline(temp, 20, ';');
			puissance = atoi(temp);
			flux.getline(temp, 20, ';');
			diesel = atoi(temp);
			flux.getline(temp, 20, '\n');
			prix = atof(temp);

			listeModeles.insere(Modele(nom,puissance,diesel,prix));
		}
	}
	else{
		// throw some I/O exception i guess
	}
	flux.close();
}

void afficherModeles(){
	Iterateur<Modele> it(listeModeles);
	int i=1;
	cout << "\n\nLISTE MODELES" << endl;
	while(!it.end()){
		cout << i << '\t' << (&it).getNom() << " " << (&it).getPuissance() << " " << (&it).isDiesel() << " " << (&it).getPrixDeBase() << endl;

		i++;
		it++;
	}
}

void afficherOptions(){
	Iterateur<Option> it(listeOptions);
	int i=1;
	cout << "\n\nLISTE OPTIONS" << endl;
	while(!it.end()){
		cout << i << '\t' << (&it).getCode() << " " << (&it).getIntitule() << " " << (&it).getPrix() << endl;

		i++;
		it++;
	}
}