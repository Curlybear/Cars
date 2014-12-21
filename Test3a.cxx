#include <stdlib.h>
#include <iostream>
using namespace std;
#include "src/Modele.h"
#include "src/Option.h"
#include "src/Voiture.h"

void Pause()
{
  char buffer[20];
  cout << endl << "--> RETURN <--";
  cin.getline(buffer,20);
}

int main()
{
  cout << "**********************************************************************" << endl;
  cout << "(1) ***** Test de l'op�rateur d'affectation de Voiture ***************" << endl;
  cout << "**********************************************************************" << endl;
  Voiture v1("Projet_208_MrDugenou",Modele("208 Acces 3P 1.4 HDi",68,true,14600.0f));
  v1.AjouteOption(Option("0MM0","Peinture metallisee",450.0f));
  v1.AjouteOption(Option("ZH75","Jante alliage leger 15 pouces",450.0f));
  cout << "---- v1 (avant affectation) --------------------" << endl;
  v1.Affiche();
  {
    Voiture v2;
    cout << ">>>>> v2 = v1;" << endl;
    v2 = v1;
    cout << "---- v2 ----------------------------" << endl;
    v2.Affiche();
    // Destruction de v2
  }
  cout << "---- v1 (apres affectation) -------------------------" << endl;
  v1.Affiche();
  Pause();

  cout << endl << "***************************************************************" << endl;
  cout         << "(2) ***** Test de l'operateur + de Voiture ********************" << endl;
  cout         << "***************************************************************" << endl;
  Voiture v("Projet_208_MrDugenou",Modele("208 Acces 3P 1.4 HDi",68,true,14600.0f)),v2;
  cout << "---- v (avant) --------------------------" << endl;
  v.Affiche();
  {
    Option op("VD09","Vitres laterales arriere surteintees",150.0f);
    cout << ">>>>> v2 = v + op;" << endl;
    v2 = v + op;
    cout << ">>>>> v2 = v2 + Option(...Pack Cuir...);" << endl;
    v2 = v2 + Option("0P3U","Pack Cuir ambiance Mistral",1100.0f);
  }
  cout << "---- v (apres) --------------------------" << endl; // v ne doit pas etre modifie !!!!
  v.Affiche();
  cout << "---- v2 (v + 2 options) ------------------------" << endl;
  v2.Affiche();
  Pause();

  cout << endl << "*****************************************************************" << endl;
  cout <<         "(3) ***** Test des operateurs - de Voiture **********************" << endl;
  cout <<         "*****************************************************************" << endl;
  Voiture v3("Projet_3008_MrLegrand",Modele("3008 Acces 1.6",120,false,21030.0f));
  v3 = v3 + Option("ZV02","Vision tete haute",350.0f);
  v3 = v3 + Option("OK01","Toit panoramique vitre",500.0f);
  v3 = v3 + Option("0MM0","Peinture metallisee",570.0f);
  cout << "----- v3 (avant) -----------------" << endl;
  v3.Affiche();
  v3 = v3 - Option("ZV02","Vision tete haute",350.0f);
  v3 = v3 - "0MM0";
  cout << "----- v3 (apres) ------------------" << endl;
  v3.Affiche();

  return 0;
}


