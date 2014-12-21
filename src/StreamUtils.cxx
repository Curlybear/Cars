#include "StreamUtils.h"

void StreamUtils::write(ostream& os, const string& str) {
    int n = str.size();
    os.write((char*) &n, sizeof(int));
    os.write(str.c_str(), sizeof(char) * n);
}

void StreamUtils::write(ostream& os, bool b) {
    os.write((char*) &b, sizeof(bool));
}

void StreamUtils::write(ostream& os, int i) {
    os.write((char*) &i, sizeof(int));
}

void StreamUtils::write(ostream& os, float f) {
    os.write((char*) &f, sizeof(float));
}

string StreamUtils::readString(istream& is) {
    int n;
    string str;

    is.read((char*) &n, sizeof(int));

    // Create a buffer of the needed size
    char buff[n];
    is.read(buff, n);
    buff[n] = '\0';

    str.assign(buff);
    return str;
}

bool StreamUtils::readBool(istream& is) {
    bool b;
    is.read((char*) &b, sizeof(bool));
    return b;
}

int StreamUtils::readInt(istream& is) {
    int i;
    is.read((char*) &i, sizeof(int));
    return i;
}

float StreamUtils::readFloat(istream& is) {
    float f;
    is.read((char*) &f, sizeof(int));
    return f;
}
