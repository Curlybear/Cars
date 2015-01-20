/*
 * InvalidFonctionException.cxx
 *
 *  Created on: Sep 23, 2014
 *      Author: curlybear
 */

#include "InvalidFonctionException.h"
#include <iostream>

using namespace std;

ostream& operator<< (ostream& s, const InvalidFonctionException& m)
{
    s << m.message;
    return s;
}
