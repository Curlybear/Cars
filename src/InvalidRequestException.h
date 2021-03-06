/*
 * InvalidRequestException.h
 *
 *  Created on: Dec 9, 2014
 *      Author: curlybear
 */

#ifndef INVALIDREQUESTEXCEPTION_H_
#define INVALIDREQUESTEXCEPTION_H_

#include <iostream>
#include <string.h>

using namespace std;

class InvalidRequestException {
    friend ostream& operator<<(ostream& s,const InvalidRequestException& m);
    private:
        char * message;
    public:
        InvalidRequestException() { message=NULL; }
        ~InvalidRequestException(){}
        InvalidRequestException(char * msg){message=NULL; setMessage(msg);};
        InvalidRequestException(const InvalidRequestException& e)
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

#endif /* INVALIDREQUESTEXCEPTION_H_ */
