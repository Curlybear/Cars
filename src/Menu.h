/*
 * Menu.h
 *
 *  Created on: Nov 4, 2014
 *      Author: curlybear
 */

#ifndef MENU_H_
#define MENU_H_

#include <iostream>

using namespace std;

const int N_C_MENU = 12;
class Menu{
protected:
    char *options[N_C_MENU];
    int nChoixMenu;
    int choix;
    virtual void affiche (void);
    virtual int choisir (void);
public:
    Menu(){
    nChoixMenu = 1;
    choix = 'Q';
    }
    Menu(char *opt[], int no);
    virtual ~Menu(){
        for(int i=0; i<nChoixMenu; i++){
            delete options[i];
        }
    }

    void showMenu (char *t) { cout << t << endl; affiche(); choisir(); }
    int getChoix(void) { return choix; }
    void setChoix(int choix);
};
#endif /* MENU_H_ */
