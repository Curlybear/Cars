/*
 * IOException.h
 *
 *  Created on: Dec 9, 2014
 *      Author: curlybear
 */

#ifndef IOEXCEPTION_H_
#define IOEXCEPTION_H_

#include <iostream>
#include <string.h>

using namespace std;

class IOException {
    friend ostream& operator<<(ostream& s,const IOException& m);
    private:
        char * message;
    public:
        IOException() { message=NULL; }
        ~IOException(){}
        IOException(char * msg){message=NULL; setMessage(msg);};
        IOException(const IOException& e)
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

#endif /* IOEXCEPTION_H_ */
