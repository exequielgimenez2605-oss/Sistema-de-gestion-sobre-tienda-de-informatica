#include <iostream>
#include <cstring>
#include "clsFecha.h"
#include "clsVentas.h"
#include "cargarCadena.h"

using namespace std;

///CONSTRUCTOR

Ventas::Ventas(int idVenta, const char *cuit, Fecha fecha){
    _idVenta = idVenta;
    strcpy(_cuit, cuit);
    _fechaDeVenta = fecha;
}

///SETTERS

void Ventas::setIdVenta(int idVenta){
    _idVenta = idVenta;
}
void Ventas::setCuit(const char *cuit){
    strcpy(_cuit, cuit);
}
void Ventas::setFechaDeVenta(Fecha fecha){
    _fechaDeVenta = fecha;
}
void Ventas::setEstado(bool estado){
    _estado = estado;
}

///GETTERS

int Ventas::getIdVenta(){
    return _idVenta;
}

const char *Ventas::getCuit(){
    return _cuit;
}

Fecha Ventas::getFechaDeVenta(){
    return _fechaDeVenta;
}

bool Ventas::getEstado(){
    return _estado;
}

///OTROS METODOS

void Ventas::Cargar(){
    char cuitAux[30];
    cout<<"INGRESE EL CUIT DEL CLIENTE: ";
    cargarCadena(cuitAux, 29);
    strcpy(_cuit, cuitAux);
    cout<<"INGRESE LA FECHA DE LA VENTA: ";
    _fechaDeVenta.Cargar();


}

void Ventas::Mostrar(){
    cout<<"||ID DE LA VENTA: "<<_idVenta<<endl;
    cout<<"||CUIT DEL CLIENTE: "<<_cuit<<endl;
    cout<<"||FECHA DE LA VENTA: ";
    _fechaDeVenta.Mostrar();
    cout<<"||======================================||"<<endl;
    cout<<endl;
}
