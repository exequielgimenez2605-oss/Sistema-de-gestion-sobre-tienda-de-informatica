#ifndef CLSARCHIVODETALLES_H_INCLUDED
#define CLSARCHIVODETALLES_H_INCLUDED
#include "clsDetalles.h"

class ArchivoDetalles{
private:
    char _nombre[30];
public:
    ArchivoDetalles(const char *n = "Detalles.dat");

    bool grabarRegistro(Detalles);
    void listar();
    void listaDeBaja();

    int contarRegistros();
    int buscarRegistros(int);
    Detalles leerRegistro(int);
    bool modificarRegistro(Detalles, int);
    int generadorId();

};

#endif // CLSARCHIVODETALLES_H_INCLUDED
