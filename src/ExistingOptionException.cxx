/*
 * ExistingOptionException.cxx
 *
 *  Created on: Dec 9, 2014
 *      Author: curlybear
 */

#include "ExistingOptionException.h"
#include <iostream>

using namespace std;

ostream& operator<< (ostream& s, const ExistingOptionException& m)
{
    s << m.message;
    return s;
}
