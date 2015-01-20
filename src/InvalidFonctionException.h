/*
 * InvalidFonctionException.h
 *
 *  Created on: Sep 23, 2014
 *      Author: curlybear
 */

#ifndef INVALIDFONCTIONEXCEPTION_H_
#define INVALIDFONCTIONEXCEPTION_H_

#include <string.h>
#include <iostream>

using namespace std;

class InvalidFonctionException {

    friend ostream& operator<<(ostream& s,const InvalidFonctionException& m);
    private:
        string message;
    public:
        InvalidFonctionException() { message="Default InvalidFonctionException"; }
        ~InvalidFonctionException(){}
        InvalidFonctionException(string msg) { message = msg; }
        InvalidFonctionException(const InvalidFonctionException& e)
        {
            message = e.message;
        }
        const char * getMessage() { return message.c_str(); }
};

#endif /* INVALIDFONCTIONEXCEPTION_H_ */
