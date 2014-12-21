#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "src/Employe.h"
#include "src/InvalidFonctionException.h"
#include "src/InvalidPasswordException.h"

using namespace std;

int  Menu();
void Essai1();
void Essai2();
void Essai3();

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
      default : fini = true ; break;
    }
  }

  exit(0);
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 5 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test des methodes susceptibles de lancer une InvalidFonctionException" << endl;
  cout << " 2. Test des methodes susceptibles de lancer une InvalidPasswordException" << endl;
  cout << " 3. Gestion de plusieurs exceptions simultanement" << endl;
  cout << " 4. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

/**********************************************************************************************/
// ATTENTION !!!!
// Les methodes de vos classes NE doivent PAS contenir de TRY{...} CATCH{...} mais
// uniquement des THROW !!! Donc, votre classe lance une exception (une erreur) mais
// ce n'est pas elle qui la traite. C'est l'application qui utilise votre classe
// qui doit traiter les exceptions. C'est donc uniquement dans le main (ou les fonctions appelees)
// que l'on trouve des try...catch 
/**********************************************************************************************/
void Essai1()
{
  cout << "----- 1. Test des methodes susceptibles de lancer une exception InvalidFonctionException --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee

  try
  {
    cout << "--> Creation d'un objet de la classe Employe <--" << endl;
    Employe e1("Dupont","Michel",2,"dupomich",Employe::ADMINISTRATIF);  // !!!
    cout << e1 << endl << endl;
    cout << "Nouvelle fonction : ";
    char txt[80];
    cin.getline(txt,80,'\n');
    e1.setFonction(txt);  // !!!
    cout << endl << e1 << endl << endl;

    cout << "--> Creation d'un second objet de la classe Employe <--" << endl;
    Employe e2;
    cout << "Encodez les donnees d'un nouvel employe :" << endl;
    cin >> e2;  // !!!
    cout << endl << "Voici l'employe que vous avez encode :" << endl;
    cout << e2 << endl;
  }
  catch(const InvalidFonctionException& exc){
	  cout << exc << endl;
  }
  
  cout << endl;
}

/**********************************************************************************************/
void Essai2()
{
  cout << "----- 2. Test des methodes susceptibles de lancer une exception InvalidPasswordException --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : Tester le code de l'erreur et affiche la cause exacte de l'erreur.

  try
  {
    Employe e1("Dupont","Michel",2,"dupomich",Employe::ADMINISTRATIF);
    cout << e1 << endl << endl;
    cout << "Encodez son mot de passe : ";
    char txt[80];
    cin.getline(txt,80,'\n');
    e1.setMotDePasse(txt);  // !!!
    cout << endl << "Le mot de passe encode est : " << e1.getMotDePasse() << endl;
  }
  catch(const InvalidPasswordException& exc){
	  cout << exc << endl;
  }
  
  cout << endl;
}

/**********************************************************************************************/
void Essai3()
{
  cout << "----- 3. Gestion de plusieurs exceptions simultanement ---" << endl;
  // A COMPLETER : Traitez TOUTES les exceptions susceptible d'etre lancee par le bloc de code suivant (try...catch)

  try
  {
    Employe e;
    cout << "Encodez un nouvel employe :" << endl;
    cin >> e;
    cout << "Saisissez son mot de passe : ";
    char txt[80];
    cin.getline(txt,80,'\n');
    e.setMotDePasse(txt);
    cout << endl << "Voici l'employe encode :" << endl;
    cout << e << endl;
    cout << "et son mot de passe : " << e.getMotDePasse() << endl << endl;
    cout << "Nouvelle fonction : ";
    cin.getline(txt,80,'\n');
    e.setFonction(txt);
    cout << "Voici la nouvelle fonction encodee : " << e.getFonction() << endl;
  }
  catch(const InvalidFonctionException& exc){
	  cout << exc << endl;
  }
  catch(const InvalidPasswordException& exc){
	  cout << exc << endl;
  }
  
  cout << endl;
}

