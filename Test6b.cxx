#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "src/Pile.h"
#include "src/Option.h"

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
  cout << "--- JEU DE TEST 6 (classe Pile) ------------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << " 1. Test du template Pile avec des entiers" << endl;
  cout << " 2. Test du template Pile avec des objets de la classe Option" << endl;
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
  cout << "----- 1. Test du template Pile avec des entiers ------------------------" << endl;
  cout << "Creation  d'une Pile..." << endl;
  Pile<int> pile;
  pile.Affiche();                                       // --> ()
  cout << endl;

  cout << "On empile 3..." << endl;
  pile.insere(3);
  pile.Affiche();                                       // --> (3)

  cout << "On empile 8..." << endl;
  pile.insere(8);
  pile.Affiche();                                       // --> (8 3)

  cout << "On empile 5.." << endl;
  pile.insere(5);
  pile.Affiche();                                       // --> (5 8 3)

  cout << "On depile..." << endl;
  int valeurDepilee = pile.retire();
  cout << "Valeur depilee = " << valeurDepilee << endl;
  pile.Affiche();                                       // --> (8 3)

  cout << "On empile 12.." << endl;
  pile.insere(12);
  pile.Affiche();                                       // --> (12 8 3)
  
  cout << endl;
}

/*********************************************************************************************/
void Essai2()
{
  cout << "----- 2. Test du template Pile avec des Options ------------------------" << endl;
  cout << "Creation  d'une Pile..." << endl;
  Pile<Option> pile;
  pile.Affiche();                                       
  cout << endl;

  cout << "On empile l'option 0MM0..." << endl;
  pile.insere(Option("0MM0","Peinture metallisee",450.0f));
  pile.Affiche();                                       

  cout << "On empile l'option ZH75..." << endl;
  Option op("ZH75","Jante alliage leger 15 pouces",450.0f);
  pile.insere(op);
  pile.Affiche();                                       

  cout << "On empile l'option 0P3U..." << endl;
  Option *ptr = new Option("0P3U","Pack Cuir ambiance Mistral",1100.0f);
  pile.insere(*ptr);
  delete ptr;
  pile.Affiche();

  cout << "On depile..." << endl;
  Option valeurDepilee = pile.retire();
  cout << "Valeur depilee = " << valeurDepilee << endl;
  pile.Affiche();                                       

  cout << "On empile l'option VD09.." << endl;
  pile.insere(Option("VD09","Vitres laterales arriere surteintees",150.0f));
  pile.Affiche();                                     
  
  cout << endl;
}
