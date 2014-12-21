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
  cout << "***** Test des op�rateurs < > == de Voiture **************************" << endl;
  cout << "**********************************************************************" << endl;

  Voiture v1("Projet1_208_MrDugenou",Modele("208 Acces 3P 1.4 HDi",68,true,14600.0f));
  v1.AjouteOption(Option("0MM0","Peinture metallisee",450.0f));
  cout << "---- Projet 1 --------------------" << endl;
  v1.Affiche();
  cout << "Prix du projet 1 = " << v1.getPrix() << " euros" << endl << endl;

  Voiture v2("Projet2_208_MrDugenou",Modele("208 Acces 5P 1.2",82,false,13500.0f));
  v2 = v2 + Option("0MM0","Peinture metallisee",450.0f);
  v2 = v2 + Option("ZH75","Jante alliage leger 15 pouces",450.0f);
  cout << "---- Projet 2 --------------------" << endl;
  v2.Affiche();
  cout << "Prix du projet 2 = " << v2.getPrix() << " euros" << endl << endl;

  cout << "---- Comparaison des projets -------------------" << endl;
  if (v1 < v2) cout << "Le projet 1 est moins cher" << endl;
  if (v1 > v2) cout << "Le projet 1 est plus cher" << endl;
  if (v1 == v2) cout << "Les deux projets ont le meme prix" << endl;

  return 0;
}


