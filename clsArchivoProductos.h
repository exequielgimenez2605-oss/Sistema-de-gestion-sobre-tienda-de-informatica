#ifndef CLSARCHIVOPRODUCTOS_H_INCLUDED
#define CLSARCHIVOPRODUCTOS_H_INCLUDED
#include "clsProducto.h"

class ArchivoProductos{
private:
    char _nombre[30];
public:
    ArchivoProductos(const char *n = "Productos.dat");
    int contarRegistros();
    int buscarRegistros(int);
    int generadorId();
    Producto leerRegistro(int);
    bool grabarRegistro(Producto);
    bool modificarRegistro(Producto, int);
    void listar();
    void listarBaja();

};

#endif // CLSARCHIVOPRODUCTOS_H_INCLUDED
