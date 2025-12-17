#ifndef CLSARCHIVOVENTAS_H_INCLUDED
#define CLSARCHIVOVENTAS_H_INCLUDED
#include "clsVentas.h"

class ArchivoVentas{
private:
    char _nombre[30];
public:
    ArchivoVentas(const char *n = "Ventas.dat");
    int generadorId();
    int contarRegistros();
    int buscarRegistros(int);
    Ventas leerRegistro(int);
    bool grabarRegistro(Ventas);
    bool modificarRegistro(Ventas, int);
    void listar();
    void listarBaja();

};

#endif // CLSARCHIVOVENTAS_H_INCLUDED
