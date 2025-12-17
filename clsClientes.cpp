#include<iostream>
#include <cstring>
#include "clsClientes.h"
#include "clsFecha.h"
#include "cargarCadena.h"
using namespace std;



///CONSTRUCTOR

Clientes::Clientes(const char *cuit, const char *nombre, const char *apellido, int telefono,const char *email, const char *direccion, int tipoCliente, Fecha fecha)
{
    strcpy(_cuit,cuit);
    strcpy(_nombre,nombre);
    strcpy(_apellido,apellido);
    _telefono=telefono;
    strcpy(_email,email);
    strcpy(_direccion,direccion);
    _tipoCliente=tipoCliente;
    _fechaIngreso=fecha;
}

///SETTERS
void Clientes::setCuit(const char *cuit)
{
    strcpy(_cuit,cuit);
}
void Clientes::setNombre(const char *nombre)
{
    strcpy(_nombre,nombre);
}
void Clientes::setApellido(const char *apellido)
{
    strcpy(_apellido,apellido);
}
void Clientes::setTelefono(int telefono)
{
    _telefono=telefono;
}
void Clientes::setEmail(const char *email)
{
    strcpy(_email,email);
}
void Clientes::setDireccion(const char *direccion)
{
    strcpy(_direccion,direccion);
}
void Clientes::setTipoCliente(int tipoCliente)
{
    _tipoCliente=tipoCliente;
}
void Clientes::setFechaIngreso(Fecha fecha)
{
    _fechaIngreso=fecha;
}
void Clientes::setEstado(bool activo)
{
    _estado=activo;
}

///GETTERS
const char *Clientes::getCuit()
{
    return _cuit;

}
const char *Clientes::getNombre()
{
    return _nombre;
}
const char *Clientes::getApellido()
{
    return _apellido;
}
int Clientes::getTelefono()
{
    return _telefono;
}
const char *Clientes::getEmail()
{
    return _email;
}
const char *Clientes::getDireccion()
{
    return _direccion;
}
int Clientes::getTipoCliente()
{
    return _tipoCliente;
}
Fecha Clientes::getFechaIngreso()
{
    return _fechaIngreso;
}
bool Clientes::getEstado()
{
    return _estado;
}

///OTROS METODOS
void Clientes::Cargar()
{
    cout<<"INGRESE EL NOMBRE: ";
    char nomAux[30];
    cargarCadena(nomAux,29);
    setNombre(nomAux);

    cout<<"INGRESE EL APELLIDO: ";
    char apeAux[30];
    cargarCadena(apeAux,29);
    setApellido(apeAux);

    cout<<"INGRESE TELEFONO: ";
    cin>> _telefono;

    cout<<"INGRESE EL EMAIL: ";
    char emailAux[50];
    cargarCadena(emailAux,49);
    setEmail(emailAux);

    cout<<"INGRESE LA DIRECCION: ";
    char dirAux[50];
    cargarCadena(dirAux,49);
    setDireccion(dirAux);

    cout<<"INGRESE TIPO CLIENTE (1: PARTICULAR, 2: EMPRESA): ";
    cin>>_tipoCliente;

    while(_tipoCliente !=1 and _tipoCliente !=2){
    cout <<"ERROR. INGRESE EL TIPO DE CLIENTE (1: PARTICULAR, 2: EMPRESA): ";
    cin >> _tipoCliente;
    }

    cout<<"<FECHA DE INGRESO> "<<endl;
    _fechaIngreso.Cargar();
}
void Clientes::Mostrar(){
    cout<<"||EL CUIT DEL CLIENTE: "<<_cuit<<endl;
    cout<<"||EL NOMBRE: "<<_nombre<<endl;
    cout<<"||EL APELLIDO: "<<_apellido<<endl;
    cout<<"||EL TELEFONO: "<<_telefono<<endl;
    cout<<"||EL EMAIL: "<<_email<<endl;
    cout<<"||LA DIRECCION: "<<_direccion<<endl;
    cout<<"||TIPO CLIENTE: ";
    if(_tipoCliente == 1){
    cout<<"PARTICULAR"<<endl;
    }else if(_tipoCliente == 2){
    cout<<"EMPRESA"<<endl;
    }
    cout<<"||FECHA DE INGRESO: ";
    _fechaIngreso.Mostrar();
    cout<<"||======================================||"<<endl;
    cout<<"||"<<endl;
}
