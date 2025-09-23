#include <iostream>
#include "lectura.h"
#include "palindromos.h"

using namespace std;




int main()
{
    //string t1 = readFile("files/transmission31.txt");
    //cout << t1 << endl;
    //string t2 = readFile("files/transmission32.txt");
    //cout << t2 << endl;
    //string m1 = readFile("files/mcode31.txt");
    //cout << m1 << endl;
    //string m2 = readFile("files/mcode32.txt");
    //cout << m2 << endl;
    string m3 = readFile("files/mcode33.txt");
    cout << m3 << endl;
    //string m4 = "noon";

    pair<int, int> m1Pal = manachers(m3);

    cout << m1Pal.first << ", " << m1Pal.second << endl;

    cout << m3.substr(m1Pal.first - 1, m1Pal.second - m1Pal.first + 1);

    return 0;
}
