#include <stdlib.h>
#include <iostream>
using namespace std;
#include "src/Modele.h"
#include "src/Voiture.h"

// Tests de base de la classe Voiture (sans les options)

int main()
{
  cout << "(1) ***** Test du constructeur par defaut de Voiture *****" << endl;
  {
    Voiture voiture;
    voiture.Affiche();
  }

  cout << endl << "(2) **** Test des setters/getters *****" << endl;
  {
    Voiture voiture;
    voiture.setNom("Projet_2008_MrDugenou");
    voiture.setModele(Modele("5008 Active 2.0 HDi 5P",136,true,28080.0f));
    voiture.Affiche();
    cout << "Nom du projet : " << voiture.getNom() << endl;
    cout << "Modele du projet : " << endl;
    voiture.getModele().Affiche();
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation de Voiture *****" << endl;
  {
    Voiture voiture("Projet_508SW_MmeLoreille",Modele("508SW Style 1.6 HDi",115,true,28500.0f));
    voiture.Affiche();
    cout << "Nom du projet : " << voiture.getNom() << endl;
    cout << "Modele du projet : " << endl;
    voiture.getModele().Affiche();
  }

  cout << endl << "(4) ***** Test du constructeur de copie de Voiture *****" << endl;
  {
    Voiture voiture1("Projet_208GTi_MrLepresse",Modele("208 GTi 1.6",200,false,23100.0f));
    cout << "voiture1 (AVANT) :" << endl;
    voiture1.Affiche();
    {   
      Voiture voiture2(voiture1);
      cout << "voiture2 :" << endl;
      voiture2.Affiche();
      voiture2.setNom("Projet_208GTi_MrLepresse_bis");
      voiture2.Affiche();
    }
    cout << "voiture1 (APRES) :" << endl;
    voiture1.Affiche();
  }

  return 0;
}


