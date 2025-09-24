#include <iostream>
#include "lectura.h"
#include "palindromos.h"
#include "parte1.h"
#include "parte3.h"

using namespace std;

string t1, t2, m1, m2, m3;

void initializeStrings() {
    t1 = readFile("files/transmission31.txt");
    t2 = readFile("files/transmission32.txt");
    cout << "T1: " << t1 << endl;
    cout << "T2: " << t2 << endl;

    m1 = readFile("files/mcode31.txt");
    m2 = readFile("files/mcode32.txt");
    m3 = readFile("files/mcode33.txt");
}


int main()
{
    initializeStrings();

    // Parte 1: Probar transmisiones por codigos maliciosos
    cout << "--------Pruebas de Deteccion de Codigos Maliciosos---------" << endl;

    // P de pattern y S de string
    vector<string> P {m1, m2, m3};
    vector<string> S {t1, t2};

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


    // Parte 2: Probar transmisiones por sub-palindromo mas largo
    cout << "--------Palindromo mas Largo de las Transmisiones----------" << endl;
    pair<int, int> t1Palindromo = manachers(t1);
    pair<int, int> t2Palindromo = manachers(t2);

    cout << "Transmision 1: {" << t1Palindromo.first << ", " << t1Palindromo.second << "}" << endl;
    cout << t1.substr(t1Palindromo.first - 1, t1Palindromo.second - t1Palindromo.first + 1) << endl;

    cout << "Transmision 2: {" << t2Palindromo.first << ", " << t2Palindromo.second << "}" << endl;
    cout << t2.substr(t2Palindromo.first - 1, t2Palindromo.second - t2Palindromo.first + 1) << endl;

    // Parte 3: Substring mas largo de las transmisiones
    cout << "--------Substring mas Largo de las Transmisiones----------" << endl;
    pair<int, int> positions = longestCommonSubstring(t1, t2);
    cout << positions.first << " " << positions.second << endl;


    return 0;
}
