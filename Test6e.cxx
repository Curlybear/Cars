#include <iostream>
using namespace std;

#include "src/Liste.h"
#include "src/ListeTriee.h"
#include "src/Iterateur.h"

// Jeu de tests combines de la classe Liste, ListeTriee et Iterateur

int main()
{
  cout << "Creation  d'une Liste (triee ou non)..." << endl;

  Liste<int> liste;             // compiler et tester en inversant les commentaires
  // ListeTriee<int> liste;     // compiler et tester en inversant les commentaires
  // --> Si vous avez bien travaille, vous ne devez pas modifier les lignes de codes ci-dessous :)...

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
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;

  cout << "On supprime un element de la liste..." << endl;
  cout << "Valeur a retirer ? ";
  int aRetirer;
  cin >> aRetirer;
  it.reset();  
  bool trouve = false;
  while (!it.end() && !trouve)
  {
    if ((int)it == aRetirer) trouve = true;
    else it++;
  }
  if (trouve)
  {
    it.remove();
    cout << "Element supprime avec succes !" << endl;
  }
  else cout << "Element non trouve..." << endl << endl;
        
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;

  return 0;
}

