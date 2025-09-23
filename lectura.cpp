#include <fstream>
#include <sstream>
#include <string>
#include "lectura.h"

string readFile(string fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        throw runtime_error("Could not open file");
    }

    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
