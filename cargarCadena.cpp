#include <iostream>
#include <cstring>
using namespace std;

void cargarCadena(char *cad, int tam){
    string texto;
    if(cin.peek() == '\n'){
        cin.ignore();
    }
    getline(cin, texto);
    strncpy(cad, texto.c_str(), tam);
}
