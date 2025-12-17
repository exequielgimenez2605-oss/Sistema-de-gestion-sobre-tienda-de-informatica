#ifndef CLSARCHIVOCLIENTES_H_INCLUDED
#define CLSARCHIVOCLIENTES_H_INCLUDED
#include "clsClientes.h"

class ArchivoClientes{
private:
    char _nombre[30];
public:
    ArchivoClientes(const char *n = "Clientes.dat");
    int contarRegistros();
    int buscarRegistros(const char *cuit);
    Clientes leerRegistro(int);
    bool grabarRegistro(Clientes);
    bool modificarRegistro(Clientes, int);
    void listar();
    void listarDeBaja();
};

#endif // CLSARCHIVOCLIENTES_H_INCLUDED
