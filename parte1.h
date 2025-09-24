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

#endif