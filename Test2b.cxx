#include <stdlib.h>
#include <iostream>
using namespace std;
#include "src/Option.h"

// Tests de la classe Option seule

int main()
{
  cout << "(1) ***** Test du constructeur par defaut de Option *****" << endl;
  {
    Option option;
    option.Affiche();
  }

  cout << endl << "(2) **** Test des setters/getters *****" << endl;
  {
    Option option;
    option.setCode("0MM0");
    option.setIntitule("Peinture metallisee");
    option.setPrix(450.0f);
    option.Affiche();
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation de Option *****" << endl;
  {
    Option option("ZH75","Jante alliage leger 15 pouces",450.0f);
    option.Affiche();
  }

  cout << endl << "(4) ***** Test du constructeur de copie de Option *****" << endl;
  {
    Option option1("UB01","Detecteur obstacles arriere",250.0f);
    cout << "option1 (AVANT) :" << endl;
    option1.Affiche();
    {   
      Option option2(option1);
      cout << "option2 :" << endl;
      option2.Affiche();
      option2.setPrix(300.0f);
      option2.Affiche();
    }
    cout << "option1 (APRES) :" << endl;
    option1.Affiche();
  }

  return 0;
}


