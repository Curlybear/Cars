/*
 * InvalidPasswordException.cxx
 *
 *  Created on: Sep 23, 2014
 *      Author: curlybear
 */

#include "InvalidPasswordException.h"
#include <iostream>

using namespace std;

ostream& operator<< (ostream& s, const InvalidPasswordException& m)
{
	s << m.message;
	return s;
}


