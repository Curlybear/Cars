#include <stdlib.h>
#include <iostream>
using namespace std;
#include "src/Modele.h"

// Quelques conseils avant de commencer...
// * N'oubliez pas de tracer (cout << ...) tous les constructeurs et le destructeur !!! Ca, c'est pas un conseil,
//   c'est obligatoire :-)
// * N'essayez pas de compiler ce programme entierement immediatement. Mettez tout en commentaires
//   sauf le point (1) et creez votre classe (dans ce fichier pour commencer) afin de compiler et tester 
//   le point (1). Une fois que cela fonctionne, decommentez le point (2) et modifier votre classe en 
//   consequence. Vous developpez, compilez et testez donc etape par etape. N'attendez pas d'avoir encode 
//   300 lignes pour compiler...
// * Une fois que tout le programme compile et fonctionne correctement, creez le .h contenant la declaration
//   de la classe, le .cxx contenant la definition des methodes, et ensuite le makefile permettant de compiler
//   le tout grace a la commande make 

int main()
{
  cout << endl << "(1) ***** Test constructeur par defaut + Affiche *****" << endl;
  {
    Modele modele;
    modele.Affiche();
  } // La presence des accolades assure que le destructeur de Modele sera appele --> a tracer !

  cout << endl << "(2) ***** Test des setters et getters *****" << endl;
  {
    Modele modele;
    modele.setNom("208 Active 1.4HDi 3P");
    modele.setPuissance(68);
    modele.setDiesel(true);
    modele.setPrixDeBase(16450.0f);
    modele.Affiche();
    cout << "Nom          = " << modele.getNom() << endl;
    cout << "Puissance    = " << modele.getPuissance() << " Ch" << endl;
    cout << "Carburant    = ";
    if (modele.isDiesel()) cout << "diesel" << endl;
    else cout << "essence" << endl;
    cout << "Prix de base = " << modele.getPrixDeBase() << " euros" << endl;
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation *****" << endl;
  {
    Modele modele("208 Allure 1.6 5P",120,false,17600.0f);
    modele.Affiche();
  }

  cout << endl << "(4) ***** Test du constructeur de copie *****" << endl;
  {
    Modele modele1("RCZ 2.0 HDi",163,true,30150.0f);
    cout << "modele1 (AVANT) :" << endl;
    modele1.Affiche();
    {   
      Modele modele2(modele1);
      cout << "modele2 :" << endl;
      modele2.Affiche();
      modele2.setNom("RCZ 2.0 HDi FAP");
      modele2.Affiche();
    } // de nouveau, les {} assurent que modele2 sera detruit avant la suite
    cout << "modele1 (APRES) :" << endl;
    modele1.Affiche();
  }

  cout << endl << "(5) ***** Test d'allocation dynamique (constructeur par defaut) *****" << endl;
  {
    Modele *p = new Modele();
    p->setNom("3008 Active 1.6 5P");
    p->setPuissance(120);
    p->setDiesel(false);
    p->setPrixDeBase(22720.0f);
    p->Affiche();
    cout << "Le prix de base de ce modele est : " << p->getPrixDeBase() << " euros" << endl;
    delete p;
  }

  cout << endl << "(6) ***** Test d'allocation dynamique (constructeur de copie) *****" << endl;
  {
    Modele modele1("308CC Sport Pack 1.6 2P",120,false,27725.0f);
    cout << "modele1 (AVANT) :" << endl;
    modele1.Affiche();
    Modele* p = new Modele(modele1);
    cout << "La copie :" << endl;
    p->Affiche();
    cout << "Destruction de la copie..." << endl; 
    delete p;
    cout << "modele1 (APRES) :" << endl;
    modele1.Affiche();
  }

  return 0;
}


