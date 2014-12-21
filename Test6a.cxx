#include <iostream>
#include <ctime>
#include <cstdlib>
#include "src/Liste.h"
#include "src/Option.h"

using namespace std;

int  Menu();
void Essai1();
void Essai2();

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
      default : fini = true ; break;
    }
  }

  exit(0);
}

int Menu()
{
  cout << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 6 (classe Liste) -----------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << " 1. Test du template Liste avec des entiers" << endl;
  cout << " 2. Test du template Liste avec des objets de la classe Option" << endl;
  cout << " 3. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

/*******************************************************************************************************/
void Essai1()
{
  cout << "----- 1. Test du template Liste avec des entiers ------------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<int> liste;
  liste.Affiche();                                       // --> ()
  cout << endl;

  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);
  liste.Affiche();                                       // --> (3 -2 5 -1 0)
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;
  cout << endl;
}

/*********************************************************************************************/
void Essai2()
{
  cout << "----- 2. Test du template Liste avec des Options ------------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<Option> liste;
  liste.Affiche();                                    
  cout << endl;

  cout << "On insere l'option 0MM0..." << endl;
  liste.insere(Option("0MM0","Peinture metallisee",450.0f));
  liste.Affiche();

  cout << "On insere l'option ZH75..." << endl;
  Option op("ZH75","Jante alliage leger 15 pouces",450.0f);
  liste.insere(op);
  liste.Affiche();

  cout << "On insere l'option 0P3U..." << endl;
  Option *ptr = new Option("0P3U","Pack Cuir ambiance Mistral",1100.0f);
  liste.insere(*ptr);
  delete ptr;
  liste.Affiche();
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;

  cout << endl;
}

