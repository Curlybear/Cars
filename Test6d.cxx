#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "src/Liste.h"
#include "src/ListeTriee.h"
#include "src/Iterateur.h"
#include "src/Option.h"
#include "src/Personne.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();

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
      default : fini = true ; break;
    }
  }

  exit(0);
}

int Menu()
{
  cout << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 6 (classe Iterateur) -------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << " 1. Test de l'iterateur avec une Liste d'entiers" << endl;
  cout << " 2. Test de l'iterateur avec une Liste d'Options" << endl;
  cout << " 3. Test de l'iterateur avec une ListeTriee d'entiers" << endl;
  cout << " 4. Test de l'iterateur avec une ListeTriee de Personnes" << endl;
  cout << " 5. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

/*******************************************************************************************************/
void Essai1()
{
  cout << "----- 1. Test de l'iterateur avec une Liste d'entiers ------------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<int> liste;
  Iterateur<int> it(liste);

  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);

  cout << "On affiche grace a l'iterateur..." << endl;
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;

  cout << "On modifie le 3eme element de la liste (5 --> 20)..." << endl;
  it.reset();  // on est sur 3
  it++;        // on est sur -2
  it++;        // on est sur 5;
  &it = 20;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;

  cout << "On supprime le 4eme element de la liste (-1)..." << endl;
  it++;        // on est sur -1
  int valeurRetiree = it.remove();
  cout << "Valeur retiree = " << valeurRetiree << endl;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;
}

/*******************************************************************************************************/
void Essai2()
{
  cout << "----- 2. Test de l'iterateur avec une Liste d'Options ------------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<Option> liste;
  Iterateur<Option> it(liste);

  cout << "On insere quelques Options..." << endl;
  liste.insere(Option("0MM0","Peinture metallisee",450.0f));
  liste.insere(Option("ZH75","Jante alliage leger 15 pouces",450.0f));
  liste.insere(Option("0P3U","Pack Cuir ambiance Mistral",1100.0f));

  cout << "On affiche grace a l'iterateur..." << endl;
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (Option)it << endl;
  cout << endl;

  cout << "On modifie le 3eme element de la liste (0P3U --> VD09)..." << endl;
  it.reset();  // on est sur 0MM0
  it++;        // on est sur ZH75
  it++;        // on est sur 0P3U;
  &it = Option("VD09","Vitres laterales arriere surteintees",150.0f);
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;

  cout << "On supprime le 1er element de la liste (0MM0)..." << endl;
  it.reset();        // on est sur 0MM0
  Option valeurRetiree = it.remove();
  cout << "Valeur retiree = " << valeurRetiree << endl;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;
}

/*******************************************************************************************************/
void Essai3()
{
  cout << "----- 3. Test de l'iterateur avec une Liste triee d'entiers ------------------------" << endl;
  cout << "Creation  d'une ListeTriee..." << endl;
  ListeTriee<int> liste;
  Iterateur<int> it(liste);

  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);

  cout << "On affiche grace a l'iterateur..." << endl; // --> (-2 -1 0 3 5)
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;

  cout << "On supprime le 2eme element de la liste (-1)..." << endl;
  it.reset();  // on est sur -2
  it++;        // on est sur -1
  int valeurRetiree = it.remove();
  cout << "Valeur retiree = " << valeurRetiree << endl;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;
}

/*******************************************************************************************************/
void Essai4()
{
  cout << "----- 4. Test de l'iterateur avec une Liste triee de Personnes --------------------" << endl;
  cout << "Creation  d'une ListeTriee..." << endl;
  ListeTriee<Personne> liste;
  Iterateur<Personne> it(liste);

  cout << "On insere quelques personnes..." << endl;
  liste.insere(Personne("Starzak","Richard"));
  liste.insere(Personne("Vilvens","Claude"));
  liste.insere(Personne("Mercenier","Denys"));
  liste.insere(Personne("Wagner","Jean-Marc"));
  liste.insere(Personne("Starzak","Luc"));
  liste.insere(Personne("Charlet","Christophe"));
  liste.insere(Personne("Moitroux","Cecile"));

  cout << "On affiche grace a l'iterateur..." << endl; 
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (Personne)it << endl;
  cout << endl;

  cout << "On supprime le 2eme element de la liste (Mercenier)..." << endl;
  it.reset();  // on est sur Charlet
  it++;        // on est sur Mercenier
  Personne valeurRetiree = it.remove();
  cout << "Valeur retiree = " << valeurRetiree << endl;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;
}
