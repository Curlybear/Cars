/*
 * ExistingOptionException.h
 *
 *  Created on: Dec 9, 2014
 *      Author: curlybear
 */

#ifndef EXISTINGOPTIONEXCEPTION_H_
#define EXISTINGOPTIONEXCEPTION_H_

#include <iostream>
#include <string.h>

using namespace std;

class ExistingOptionException {
    friend ostream& operator<<(ostream& s,const ExistingOptionException& m);
    private:
        char * message;
    public:
        ExistingOptionException() { message=NULL; }
        ~ExistingOptionException(){}
        ExistingOptionException(char * msg){message=NULL; setMessage(msg);};
        ExistingOptionException(const ExistingOptionException& e)
        {
            message = e.message;
        }
        const char * getMessage() { return message; }
        void setMessage(char* pMsg){
            if(message)
            {
                delete message;
            }

            if(pMsg)
            {
                this->message=new char[strlen(pMsg)+1];
                strcpy(message,pMsg);
            }
            else
                this->message=NULL;
        }
};

#endif /* EXISTINGOPTIONEXCEPTION_H_ */
