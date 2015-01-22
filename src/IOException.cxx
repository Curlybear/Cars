/*
 * IOException.cxx
 *
 *  Created on: Dec 9, 2014
 *      Author: curlybear
 */

#include "IOException.h"
#include <iostream>

using namespace std;

ostream& operator<< (ostream& s, const IOException& m)
{
    s << m.message;
    return s;
}
