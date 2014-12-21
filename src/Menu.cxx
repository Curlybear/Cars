/*
 * Menu.cxx
 *
 *  Created on: Nov 4, 2014
 *      Author: curlybear
 */

#include "Menu.h"
#include <cstring>

void Menu::setChoix(int choix) {
	this->choix = choix;
}

Menu::Menu (char *opt[], int no){
	for (int i=0; i<no ; i++)
	{
		options[i] = new char[strlen(opt[i])+1];
		strcpy(options[i],opt[i]);
	}
	nChoixMenu = no;
	choix = 'Q';
}
void Menu::affiche(void){
	for (int i = 0; i < nChoixMenu; i++){
		cout << options[i] << endl;
	}
}

int Menu::choisir (void){
	int r;

	cout << "Votre choix : ";
	do
	{
		cin >> r;
	}while (r>=nChoixMenu || r<0);
	choix = r;
	return (r);
}
