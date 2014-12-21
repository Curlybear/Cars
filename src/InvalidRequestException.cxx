/*
 * InvalidRequestException.cxx
 *
 *  Created on: Dec 9, 2014
 *      Author: curlybear
 */

#include "InvalidRequestException.h"
#include <iostream>

using namespace std;

ostream& operator<< (ostream& s, const InvalidRequestException& m)
{
	s << m.message;
	return s;
}
