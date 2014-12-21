/*
 * InvalidPasswordException.h
 *
 *  Created on: Sep 23, 2014
 *      Author: curlybear
 */

#ifndef INVALIDPASSWORDEXCEPTION_H_
#define INVALIDPASSWORDEXCEPTION_H_

#include <string.h>
#include <iostream>

using namespace std;

class InvalidPasswordException {
	friend ostream& operator<<(ostream& s,const InvalidPasswordException& m);
	private:
		string message;
	public:
		InvalidPasswordException() { message="Default InvalidPasswordException"; }
		~InvalidPasswordException(){}
		InvalidPasswordException(string msg) { message = msg; }
		InvalidPasswordException(const InvalidPasswordException& e)
		{
			message = e.message;
		}
		const char * getMessage() { return message.c_str(); }
};

#endif /* INVALIDPASSWORDEXCEPTION_H_ */
