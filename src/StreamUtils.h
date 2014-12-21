#ifndef STREAMUTILS_HPP
#define STREAMUTILS_HPP

#include <iostream>
#include <string>

using namespace std;

class StreamUtils {

    public:
        static void write(ostream&, const string&);
        static void write(ostream&, bool);
        static void write(ostream&, int);
        static void write(ostream&, float);

        static string readString(istream&);
        static bool   readBool(istream&);
        static int    readInt(istream&);
        static float  readFloat(istream&);

};

#endif
