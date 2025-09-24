#ifndef LECTURA_H_INCLUDED
#define LECTURA_H_INCLUDED

#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

string readFile(string fileName) {
    ifstream file(fileName);
    string str, line, newStr;

    while (getline(file, line)) {
        str += line;
    }

    for (char c : str) {
        if (c != ' ' && c != '\n' && c != '\r' && c != '\t') {
            newStr += c;
        }
    }

    return newStr;
}

#endif // LECTURA_H_INCLUDED
