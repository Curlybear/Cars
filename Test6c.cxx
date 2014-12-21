#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "src/ListeTriee.h"
#include "src/Personne.h"

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
  cout << "--- JEU DE TEST 6 (classe ListeTriee) ------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << " 1. Test du template ListeTriee avec des entiers" << endl;
  cout << " 2. Test du template ListeTriee avec des objets de la classe Personne" << endl;
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
  cout << "----- 1. Test du template ListeTriee avec des entiers ------------------------" << endl;
  cout << "Creation  d'une Liste triee..." << endl;
  ListeTriee<int> liste;
  liste.Affiche();                                       // --> ()
  cout << endl;

  cout << "On insere 3,-2,5,-1,0 et -8..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);
  liste.insere(-8);
  liste.Affiche();                                       // --> (-8 -2 -1 0 3 5)
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;
  cout << endl;
}

/*******************************************************************************************************/
void Essai2()
{
  cout << "----- 2. Test du template ListeTriee avec des Personnes ------------------------" << endl;
  cout << "Creation  d'une Liste triee..." << endl;
  ListeTriee<Personne> liste;
  liste.Affiche();                                       
  cout << endl;

  cout << "On insere quelques personnes..." << endl;
  liste.insere(Personne("Starzak","Richard"));
  liste.insere(Personne("Vilvens","Claude"));
  liste.insere(Personne("Mercenier","Denys"));
  liste.insere(Personne("Wagner","Jean-Marc"));
  liste.insere(Personne("Starzak","Luc"));
  liste.insere(Personne("Charlet","Christophe"));
  liste.insere(Personne("Moitroux","Cecile"));
  liste.Affiche();
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;
  cout << endl;
}
