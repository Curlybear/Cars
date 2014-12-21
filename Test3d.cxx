#include <stdlib.h>
#include <iostream>
using namespace std;
#include "src/Modele.h"
#include "src/Option.h"
#include "src/Voiture.h"

int main()
{
  cout << "**********************************************************************" << endl;
  cout << "(1) ***** Test de l'operateur de pre-decrementation ******************" << endl;
  cout << "**********************************************************************" << endl;
  Option op1("0MM0","Peinture metallisee",450.0f);
  cout << "Affichons d'abord op1 : " << op1 << endl;
  cout << "Resultat de cout << --op1 << endl; :" << endl;  
  cout << --op1 << endl;        // Si tout va bien, op1 est decremente avant d'etre affiche !
  cout << "et on reaffiche op1 : " << op1 << endl << endl;

  cout << "**********************************************************************" << endl;
  cout << "(2) ***** Test de l'operateur de post-decrementation *****************" << endl;
  cout << "**********************************************************************" << endl;
  Option op2("ZH75","Jantes alliage 15 pouces",350.0f);
  cout << "Affichons d'abord op2 : " << op2 << endl;
  cout << "Resultat de cout << op2-- << endl; :" << endl;  
  cout << op2-- << endl;        // Si tout va bien, op2 est decremente apres avoir ete affiche !
  cout << "et on reaffiche op2 :" << op2 << endl << endl;

  return 0;
}


