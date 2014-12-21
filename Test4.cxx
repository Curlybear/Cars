#include <stdlib.h>
#include <iostream>
using namespace std;
#include <time.h>

#include "src/Personne.h"
#include "src/Client.h"
#include "src/Employe.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();
void Essai6();

int main()
{
  int choix;
  bool fini = false;
  srand((unsigned)time(NULL));

  while(!fini)
  {
    choix = Menu();
    switch(choix)
    {
      case 1 : Essai1(); break;
      case 2 : Essai2(); break;
      case 3 : Essai3(); break;
      case 4 : Essai4(); break;
      case 5 : Essai5(); break;
      case 6 : Essai6(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 4 ----------------------------------------------------------" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << " 1. Test de la classe Personne" << endl;
  cout << " 2. Test de la classe Client" << endl;
  cout << " 3. Test de la classe Employe" << endl;
  cout << " 4. Heritage et virtualite : Test des methodes (non) virtuelles" << endl;
  cout << " 5. Test du downcasting et du dynamic-cast" << endl;
  cout << " 6. Test des variables statiques de la classe Employe" << endl;
  cout << " 7. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

/***********************************************************************************************/
// A FAIRE : la classe Persone qui contient le nom (char*) et le prenom (char*) d'une personne  
//           la methode Affiche (NON virtuelle !!!) dans Activite et dans Regate
//           les methodes << et >> de Personne
//           l'operateur d'affectation (=) de Personne
void Essai1()
{
  cout << "----- 1.1 Test du constructeur par defaut de Personne ------------------------" << endl;
  Personne p1;
  cout << "--> Voici p1 :" << endl;
  p1.Affiche();
  cout << endl;
 
  cout << "----- 1.2 Test du constructeur d'initialisation de Personne ------------------" << endl;
  Personne p2("Wagner","Jean-Marc");
  cout << "--> Voici p2 :" << endl;
  p2.Affiche();
  cout << endl;

  cout << "----- 1.3 Test du constructeur de copie de Personne --------------------------" << endl;
  Personne p3(p2);
  cout << "--> Voici p3 :" << endl;
  p3.Affiche();
  cout << endl;

  cout << "----- 1.4 Test des getXXX et setXXX de Personne ------------------------------" << endl;
  p3.setNom("Mercenier");
  p3.setPrenom("Denys");
  cout << "Nom : " << p3.getNom() << endl;
  cout << "Prenom : " << p3.getPrenom() << endl;
  cout << endl;

  cout << "----- 1.5 Test des operateurs << et >> de Personne ----------------------------" << endl;
  cout << "Encodez une personne :" << endl;
  cin >> p3;
  cout << "Voici la personne encodee : " << p3 << endl;
  cout << endl;

  cout << "----- 1.6 Test de l'operateur = de Personne -----------------------------------" << endl;
  p1 = p3;
  p1.Affiche();
}

/***********************************************************************************************/
// A FAIRE : la classe Client qui herite de Personne, contenant en plus un numero (int) et une adresse (char*)
//           la methode Affiche (NON virtuelle !!!) de Client
//           les operateurs << et >> de Client
//           l'operateur d'affectation (=) de Client

void Essai2()
{
  cout << "----- 2.1 Test du constructeur par defaut ----------------------------------" << endl;
  Client c1;
  cout << "--> Voici c1 :" << endl;
  c1.Affiche();
  cout << endl;

  cout << "----- 2.2 Test des setters -------------------------------------------------" << endl;
  c1.setNom("Lagalere");
  c1.setPrenom("Pierre");
  c1.setNumero(17);
  c1.setAdresse("Rue des ennuis 26A 4000 Liege");
  cout << "--> Voici c1 (apres les setters) :" << endl;
  c1.Affiche();
  cout << endl;
  
  cout << "----- 2.3 Test des getters -------------------------------------------------" << endl;
  cout << "Nom     : " << c1.getNom() << endl;
  cout << "Prenom  : " << c1.getPrenom() << endl;
  cout << "Numero  : " << c1.getNumero() << endl;
  cout << "Adresse : " << c1.getAdresse() << endl;
  cout << endl;

  cout << "----- 2.4 Test du constructeur d'initialisation ----------------------------" << endl;
  Client c2("Issier","Pol",41,"Rue de la Gendarmerie 24 4100 Seraing");
  cout << "--> Voici c2 :" << endl; 
  c2.Affiche();
  cout << endl;

  cout << "----- 2.5 Allocation dynamique de Client avec pointeur de type Client + test du constructeur de copie ------" << endl;
  cout << "--> Copie de c2..." << endl;
  Client *p1 = new Client(c2); // Vive le constructeur de copie !
  cout << "--> Voici la copie de c2 :" << endl;
  p1->Affiche();
  cout << "--> Destruction de la copie..." << endl;
  delete p1;
  cout << "--> Revoici c2 :" << endl;
  c2.Affiche();
  cout << endl;

  cout << "----- 2.6 Allocation dynamique de Client avec pointeur de type Personne (Upcasting) -----" << endl;
  Personne *p2 = new Client(c2);
  p2->Affiche();  // Quelle methode Affiche est appelee ? celle de Personne ou de Client ?
  delete p2;      // Quel destructeur est appele ? celui de Personne ou de Client ?
  cout << endl;

  cout << "----- 2.7 Test de cin et cout ----------------------------------------------" << endl;
  Client c3;
  cout << "--> Entrez le client c3 :" << endl;  
  cin >> c3;
  cout << endl << "--> Voici c3 :" << endl;
  cout << c3 << endl;
  cout << endl;

  cout << "----- 2.8 Test de l'operateur d'affectation --------------------------------" << endl;
  Client c4;
  cout << "--> Execution du code c4 = c3; :" << endl;
  c4 = c3;
  cout << "--> c4 = " << c4 << endl;
}

/***********************************************************************************************/
// A FAIRE : la classe Employe qui herite de Personne, contenant en plus un numero (int), un (char*),
//           un mot de passe (char*) et une fonction (char*)
//           la methode Affiche (NON virtuelle !!!) de Employe
//           les operateurs << et >> de Employe
//           l'operateur d'affectation (=) de Employe

void Essai3()
{
  cout << "----- 3.1 Test du constructeur par defaut ----------------------------------" << endl;
  Employe e1;
  cout << "--> Voici e1 :" << endl;
  e1.Affiche();
  cout << endl;

  cout << "----- 3.2 Test des setters -------------------------------------------------" << endl;
  e1.setNom("Tombale");
  e1.setPrenom("Pierre");
  e1.setNumero(4);
  e1.setLogin("tombpier");
  e1.setMotDePasse("azerty34");
  e1.setFonction("Vendeur");
  cout << "--> Voici e1 (apres les setters) :" << endl;
  e1.Affiche();
  cout << endl;

  cout << "----- 3.3 Test des getters -------------------------------------------------" << endl;
  cout << "Nom          : " << e1.getNom() << endl;
  cout << "Prenom       : " << e1.getPrenom() << endl;
  cout << "Numero       : " << e1.getNumero() << endl;
  cout << "Login        : " << e1.getLogin() << endl;
  cout << "Mot de passe : " << e1.getMotDePasse() << endl;
  cout << "Fonction     : " << e1.getFonction() << endl;
  cout << endl;

  cout << "----- 3.4 Test du constructeur d'initialisation ----------------------------" << endl;
  Employe e2("Dugenou","Jean-Paul",2,"dugejean","Administratif");
  // Le pointeur motDePasse est initialise a NULL. Le mot de passe ne peut etre modifie (intialise)
  // qu'avec la methode setMotDePasse ou ResetMotDePasse (qui remet le pointeur a NULL).
  e2.setMotDePasse("qsdf1234");
  cout << "--> Voici e2 :" << endl; 
  e2.Affiche();
  cout << "Son mot de passe est : " << e2.getMotDePasse() << endl;
  cout << endl;

  cout << "----- 3.5 Allocation dynamique de Employe avec pointeur de type Employe + test du constructeur de copie ------" << endl;
  cout << "--> Copie de e2..." << endl;
  Employe *p1 = new Employe(e2); // Vive le constructeur de copie !
  // Le constructeur de copie copie tout, y compris le mot de passe
  cout << "--> Voici la copie de e2 :" << endl;
  p1->Affiche();
  cout << "Son mot de passe est : " << p1->getMotDePasse() << endl;
  cout << "--> Destruction de la copie..." << endl;
  delete p1;
  cout << "--> Revoici e2 :" << endl;
  e2.Affiche();
  cout << "Son mot de passe est : " << e2.getMotDePasse() << endl;
  cout << endl;

  cout << "----- 3.6 Allocation dynamique de Employe avec pointeur de type Personne (Upcasting) -----" << endl;
  Personne *p2 = new Employe(e2);
  p2->Affiche();  // Quelle methode Affiche est appelee ? celle de Personne ou de Client ?
  delete p2;      // Quel destructeur est appele ? celui de Personne ou de Client ?
  cout << endl;

  cout << "----- 3.7 Test de cin et cout ----------------------------------------------" << endl;
  Employe e3;
  cout << "--> Entrez l'employe e3 :" << endl;  
  cin >> e3;
  cout << endl << "--> Voici c3 :" << endl;
  cout << e3 << endl;
  cout << endl;

  cout << "----- 3.8 Test de l'operateur d'affectation --------------------------------" << endl;
  Employe e4;
  cout << "--> Execution du code e4 = e3; :" << endl;
  e4 = e3;
  cout << "--> e4 = " << e4 << endl;
}

/******************************************************************************************/
// A FAIRE : La m�thode virtuelle toString() des classes Personne, Client et Employe

void Essai4()
{
  srand((unsigned)time(NULL));

  cout << "----- 4.1 Allocation dynamique de personnes --------------------------------" << endl;
  Personne* personnes[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << endl << "personnes[" << i << "] : ";
    int n = rand()%3;
    switch(n)
    {
      case 0 : personnes[i] = new Personne();
               cout << "Personne" << endl;
               break;

      case 1 : personnes[i] = new Client();
               cout << "Client" << endl;
               break;

      case 2 : personnes[i] = new Employe();
               n = rand()%2;
               if (n == 0)
               {
                 ((Employe*)personnes[i])->setFonction("Administratif");
                 cout << "Administratif" << endl;
               }
               else
               {
                 ((Employe*)personnes[i])->setFonction("Vendeur");
                 cout << "Vendeur" << endl;
               }
               break;
    }
  }
  cout << endl;

  // Rappel : on vous demande de d�finir la methode Affiche en NON virtuelle a des fins
  // pedagogiques, dans le but de comprendre la difference entre virtuelle et non virtuelle

  cout << "----- 4.2 Test de la methode NON VIRTUELLE Affiche() (redefinie dans chaque classe heritee) -------" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << endl << "personnes[" << i << "] :" << endl;
    personnes[i]->Affiche();
  }
  cout << endl;

  cout << "----- 4.3 Test de la methode VIRTUELLE toString() (redefinie dans chaque classe heritee) -------" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << endl << "personnes[" << i << "] : " << personnes[i]->toString() << endl;
  }
  cout << endl;
  
  cout << "----- 4.4 Liberation memoire ----------------------------------------------------------------------------" << endl;
  for (int i=0 ; i<10 ; i++) delete personnes[i];  // Tout se passe-t-il comme vous voulez ?
  // Pour etre plus precis, quid des destructeurs et de la virtualite ?
}

/*********************************************************************************************/
// A FAIRE : normalement rien dans vos classes...
//           juste comprendre et tester le code ci-dessous

void Essai5()
{
  srand((unsigned)time(NULL));

  cout << "----- 5.1 Allocation dynamique de personnes --------------------------------" << endl;
  Personne* personnes[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << endl << "personnes[" << i << "] : ";
    int n = rand()%3;
    switch(n)
    {
      case 0 : personnes[i] = new Personne();
               cout << "Personne" << endl;
               break;

      case 1 : personnes[i] = new Client();
               cout << "Client" << endl;
               break;

      case 2 : personnes[i] = new Employe();
               cout << "Employe" << endl;
               break;
    }
  }
  cout << endl;

  cout << "----- 5.2 Test du downcasting et dynamic-cast ------------------------------" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << "personnes[" << i << "] ";
    Client* pClient = dynamic_cast<Client*>(personnes[i]);
    if (pClient != NULL) cout << "est un Client" << endl;
    else
    {
      Employe* pEmploye = dynamic_cast<Employe*>(personnes[i]);
      if (pEmploye != NULL) cout << "est un Employe" << endl;
      else cout << "est une personne (ni Client ni Employe)" << endl;
    }
  }
  cout << endl;

  cout << "----- 5.3 Liberation memoire ----------------------------------------------------------------------------" << endl;
  for (int i=0 ; i<10 ; i++) delete personnes[i];
}

/******************************************************************************************/
// A FAIRE : Les deux variables statiques ADMINISTRATIF et VENDEUR (char[]) de la classe Employe

void Essai6()
{
  cout << "Les deux fonctions possibles pour un employe sont :" << endl;
  cout << " - " << Employe::ADMINISTRATIF << endl;
  cout << " - " << Employe::VENDEUR << endl << endl;

  Employe e("Dugenou","Jean-Paul",2,"dugejean",Employe::ADMINISTRATIF);
  cout << e << endl;
  e.setFonction(Employe::VENDEUR);
  cout << e << endl;
}
