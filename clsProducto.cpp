#include<iostream>
#include <cstring>
#include "clsProducto.h"
#include "clsFecha.h"
#include "cargarCadena.h"

using namespace std;

///CONSTRUTOR
Producto::Producto(int idProducto, const char *nombre, const char *marca,int tipoDeEquipo, const char *descripcion,int stock, float precioUnitario){
     _idProducto=idProducto;
     strcpy(_nombre,nombre);
     strcpy(_marca,marca);
     _tipoDeEquipo=tipoDeEquipo;
     strcpy(_descripcion,descripcion);
     _stock=stock;
     _precioUnitario=precioUnitario;
}
///SETTERS
void Producto::setIdProducto(int idProducto){
        _idProducto=idProducto;
}
void Producto::setNombre(const char *nombre){
        strcpy(_nombre,nombre);
}
void Producto::setMarca(const char *marca){
        strcpy(_marca,marca);
}
void Producto::setTipoDeEquipo(int tipoDeEquipo){
        _tipoDeEquipo=tipoDeEquipo;
}
void Producto::setDescripcion(const char *descripcion){
        strcpy(_descripcion,descripcion);
}
void Producto::setStock(int stock){
        _stock=stock;
}
void Producto::setEstado(bool activo){
        _estado = activo;
}
void Producto::setPrecioUnitario(float precioUnitario){
        _precioUnitario = precioUnitario;
}

///GETTERS

int Producto::getIdProducto(){
    return _idProducto;
}
const char *Producto::getNombre(){
    return _nombre;
}
const char *Producto::getMarca(){
    return _marca;
}
int Producto::getTipoDeEquipo(){
    return _tipoDeEquipo;
}
const char *Producto::getDescripcion(){
    return _descripcion;
}
int Producto::getStock(){
    return _stock;
}
bool Producto::getEstado(){
    return _estado;
}
float Producto::getPrecioUnitario(){
    return _precioUnitario;
}

///OTROS METODOS

void Producto::cargarProducto(){

    cout<<"INGRESE EL NOMBRE DEL PRODUCTO: ";
    char nomAux[30];
    cargarCadena(nomAux,29);
    setNombre(nomAux);
    cout<<"INGRESE LA MARCA DEL PRODUCTO: ";
    char marAux[30];
    cargarCadena(marAux,29);
    setMarca(marAux);
    cout<<"INGRESE UNA OPCION(1:PERIFERICO, 2:CONSOLA, 3:PC): ";
    cin>>_tipoDeEquipo;

    while(_tipoDeEquipo != 1 and _tipoDeEquipo != 2 and _tipoDeEquipo != 3){
    cout <<"ERROR. INGRESE UNA OPCION(1:PERIFERICO, 2:CONSOLA, 3:PC): ";
    cin >>_tipoDeEquipo;
    }

    cout<<"INGRESE EL PRECIO UNITARIO: $";
    cin>>_precioUnitario;

    while (_precioUnitario <=0){

    cout<<"El MONTO INGRESADO NO ES VALIDO: "<<endl;
    cout<<"INGRESE NUEVAMENTE EL PRECIO DEL PRODUCTO : $";
    cin>>_precioUnitario;

    }
    cout<<"INGRESE LA DESCRIPCION DEL PRODUCTO: ";
    char desAux[120];
    cargarCadena(desAux,119);
    setDescripcion(desAux);



    cout<<"INGRESE EL STOCK DEL PRODUCTO: ";
    cin>>_stock;
    while(_stock <= 0){
    cout<<"STOCK INVALIDO. El STOCK TIENE QUE SER MAYOR A CERO."<<endl;
    cin>>_stock;
    }
}
void Producto::mostrarProducto(){
    cout<<"||EL ID DEL PRODUCTO ES: "<<_idProducto<<endl;
    cout<<"||EL NOMBRE ES: "<<_nombre<<endl;
    cout<<"||LA MARCA ES: "<<_marca<<endl;
    cout<<"||EL TIPO DE EQUIPO ES: ";
    if(_tipoDeEquipo == 1){
    cout << "PERIFERICO "<<endl;
    }
    if(_tipoDeEquipo == 2){
    cout << "CONSOLA "<<endl;
    }
    if(_tipoDeEquipo == 3){
    cout << "PC "<<endl;
    }
    cout<<"||PRECIO UNITARIO DEL PRODUCTO: $"<<_precioUnitario<<endl;
    cout<<"||DESCRIPCION DEL PRODUCTO: "<<_descripcion<<endl;
    cout<<"||El STOCK ES: "<<_stock<<endl;
    cout<<"||======================================||"<<endl;
    cout<<"||"<<endl;
}
