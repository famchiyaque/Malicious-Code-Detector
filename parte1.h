#ifndef PARTE1_H
#define PARTE1_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// construir el arreglo Z
vector<int> buildZArray(const string& str) {
    int n = str.length();
    vector<int> z(n);

    // el primer valor siempre coincide con toda la cadena
    z[0] = n;


    int left = 0, right = 0;
    for (int i = 1; i < n; i++) {

        // podemos reutilizar información ya calculada
        if (i <= right) {
            z[i] = min(right - i + 1, z[i - left]);
        }
        
        // extender la coincidencia lo mas posible
        while (i + z[i] < n && str[z[i]] == str[i + z[i]]) {
            z[i]++;
        }
        
        // si hay una coincidencia mas larga, actualizar
        if (i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }
    
    return z;
}

// buscar el patrón usando el arreglo Z
vector<int> findPattern(const string& text, const string& pattern) {
    vector<int> positions;

    // crear el z array
    string combined = pattern + "$" + text;
    vector<int> z = buildZArray(combined);

    // buscar donde z[i] == longitud del pattern
    int patternLen = pattern.length();

    for (int i = patternLen + 1; i < combined.length(); i++) {
        if (z[i] == patternLen) {
            int positionInText = i - patternLen - 1;
            positions.push_back(positionInText);
        }
    }
    return positions;
}


// Lee todo el contenido de un archivo y lo devuelve como string
string leerArchivo(const string& nombre) {
    ifstream archivo(nombre);
    string str, line, newStr;

    while (getline(archivo, line)) {
        str += line;
    }

    for (char c : str) {
        if (c != ' ' && c != '\n' && c != '\r' && c != '\t') {
            newStr += c;
        }
    }

    return newStr;
}

// main function
void ejecutarParte1() {
    vector<string> mcodes = {"mcode01.txt", "mcode02.txt", "mcode03.txt"};
    vector<string> transmissions = {"transmission01.txt", "transmission02.txt"};
    
    // P de pattern y S de string
    vector<string> P(3);
    vector<string> S(2);
    
    // leer y alamacenar archivos
    for (int i = 0; i < 3; i++) {
        P[i] = leerArchivo(mcodes[i]);
    }
    for (int i = 0; i < 2; i++) {
        S[i] = leerArchivo(transmissions[i]);
    }

    // buscar el patron mcode para cada transmission
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            vector<int> pos = findPattern(S[i], P[j]);

            if (pos.empty()) {
                cout << "false" << endl;
            } else {
                cout << "true " << (pos[0] + 1) << endl;
            }
        }
    }
}

#endif