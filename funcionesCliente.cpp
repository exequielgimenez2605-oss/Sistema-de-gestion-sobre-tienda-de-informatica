#include <iostream>
#include <cstring>
#include "clsClientes.h"
#include "clsArchivoClientes.h"
#include "funcionesCliente.h"
#include "clsFecha.h"
#include "cargarCadena.h"


using namespace std;

void registrarCliente(){
    Clientes obj;
    ArchivoClientes arc;

    cout << "INGRESE EL CUIT DEL CLIENTE: ";
    char cuitAux[30];
    cargarCadena(cuitAux,29);
    obj.setCuit(cuitAux);


    if(arc.buscarRegistros(cuitAux) >= 0) {
        cout << "ERROR: YA EXISTE UN CLIENTE CON ESE CUIT. NO SE PUEDE AGREGAR OTRO." << endl;
        return;
    }


    obj.Cargar();
    obj.setEstado(true);



    if(arc.grabarRegistro(obj)) {
        cout << "SE AGREGO CORRECTAMENTE" << endl;
    } else {
        cout << "NO SE PUDO GUARDAR EL CLIENTE" << endl;
    }
}

void listarClientes(){
    ArchivoClientes arc;
    int cant = arc.contarRegistros();

        if(cant <= 0){
        cout <<" NO HAY USUARIOS PARA MOSTRAR. "<<endl;
        return;

        }
        cout <<"||======================================||"<<endl;
        cout <<"||           LISTA DE CLIENTES          ||"<<endl;
        cout <<"||======================================||"<<endl;
        arc.listar();

}

void buscarCliente(){
    Clientes obj;
    ArchivoClientes arc;

    int cantidadRegistros = arc.contarRegistros();

    cout << "INGRESE EL CUIT DEL CLIENTE QUE QUIERE BUSCAR: ";
    char cuitAux[30];
    cargarCadena(cuitAux, 29);
    bool encontrado = false;


    for (int i = 0; i < cantidadRegistros; i++) {
    obj = arc.leerRegistro(i);
        if (strcmp(cuitAux, obj.getCuit()) == 0){
            cout <<"||======================================||"<<endl;
            cout <<"||          CLIENTE ENCONTRADO          ||"<<endl;
            cout <<"||======================================||"<<endl;
            obj.Mostrar();
            encontrado = true;

        }
    }
    if (encontrado == false){
        cout <<"||======================================||"<<endl;
        cout <<"||        CLIENTE NO ENCONTRADO         ||"<<endl;
        cout <<"||======================================||"<<endl;
    }
}

void darDeBajaCliente(){
    ArchivoClientes arc;
    Clientes obj;

    cout <<"INGRESE EL CUIT DEL CLIENTE: ";
    char cuitAux[30];
    cargarCadena(cuitAux,29);
    obj.setCuit(cuitAux);

    int pos = arc.buscarRegistros(cuitAux);
    if (pos >= 0){
        Clientes obj = arc.leerRegistro(pos);
        obj.setEstado(false);
        arc.modificarRegistro(obj, pos);
        cout <<"USUARIO DADO DE BAJA CORRECTAMENTE. "<<endl;

    }else{
        cout <<"USUARIO INEXISTENTE. "<<endl;
    }
}

void modificarCliente(){

    ArchivoClientes arc;

    cout<<"INGRESE EL CUIT DEL CLIENTE QUE QUIERE MODIFICAR: ";
    char cuitAux[30];
    cargarCadena(cuitAux,29);


    int pos = arc.buscarRegistros(cuitAux);
    if(pos <0){
        cout<<"NO HAY UN CLIENTE CON ESE CUIT."<<endl;
            return;
    }
    Clientes obj = arc.leerRegistro(pos);

    while(true){
        int opcionMod;
        system("cls");

        cout <<"||=====================||"<<endl;
        cout <<"||===== MODIFICAR======||"<<endl;
        cout <<"||=====================||"<<endl;
        cout <<"||1 NOMBRE             ||"<<endl;
        cout <<"||2 TELEFONO           ||"<<endl;
        cout <<"||3 EMAIL              ||"<<endl;
        cout <<"||4 DIRECCION          ||"<<endl;
        cout <<"||5 TIPO DE CLIENTE    ||"<<endl;
        cout <<"||0 SALIR              ||"<<endl;
        cout <<"||=====================||"<<endl;
        cout <<"  INGRESE UNA OPCION: ";
        cin >> opcionMod;
        system("cls");

        switch(opcionMod){
        case 1:
            cout<<"INGRESAR NUEVO NOMBRE: ";
            char nombreNuevo[30];
            cargarCadena(nombreNuevo, 29);
            obj.setNombre(nombreNuevo);
            cout <<endl;
            cout<<"NOMBRE ACTUALIZADO CORRECTAMENTE."<<endl;
            break;
        case 2:
            cout<<"INGRESE EL NUEVO TELEFONO: ";
            int telefonoNuevo;
            cin >>telefonoNuevo;
            obj.setTelefono(telefonoNuevo);
            cout<<endl;
            cout<<"TELEFONO ACTUALIZADO CORRECTAMENTE."<<endl;
            break;
        case 3:
            cout<<"INGRESE EL NUEVO EMAIL: ";
            char emailNuevo[50];
            cargarCadena(emailNuevo,49);
            obj.setEmail(emailNuevo);
            cout<<endl;
            cout<<"NUEVO MAIL ACTUALIZADO CORRECTAMENTE."<<endl;
            break;
        case 4:
            cout<<"INGRESE LA NUEVA DIRECCION: ";
            char direccionNueva[50];
            cargarCadena(direccionNueva,49);
            obj.setDireccion(direccionNueva);
            cout<<endl;
            cout<<"NUEVA DIRECCION ACTUALIZADA CORRECTAMENTE."<<endl;
            break;
        case 5:
            cout<<"INGRESE EL NUEVO TIPO DE CLIENTE(1: PARTICULAR, 2: EMPRESA): ";
            int tipoClienteNuevo;
            cin >>tipoClienteNuevo;
            obj.setTipoCliente(tipoClienteNuevo);
            cout<<endl;
            cout<<"NUEVO TIPO DE CLIENTE ACTUALIZADO CORRECTAMENTE."<<endl;
            break;
        case 0:
            return;

        }
    system("pause");
    arc.modificarRegistro(obj, pos);
    }

}
void listarClientesBaja(){
 ArchivoClientes arc;

int cant= arc.contarRegistros();

    if(cant<=0){
        cout<<"NO HAY CLIENTES DADOS DE BAJA PARA MOSTRAR "<<endl;
    }
        cout <<"||======================================||"<<endl;
        cout <<"||    LISTA DE CLIENTES DADOS DE BAJA   ||"<<endl;
        cout <<"||======================================||"<<endl;
        arc.listarDeBaja();

}
void darAltaClientes(){
    ArchivoClientes arc;
    Clientes obj;

    cout <<"INGRESE EL CUIT DEL CLIENTE: ";
    char cuitAux[30];
    cargarCadena(cuitAux,29);
    obj.setCuit(cuitAux);

    int pos = arc.buscarRegistros(cuitAux);

    if (pos >= 0){
        obj = arc.leerRegistro(pos);

        if(obj.getEstado()){
            cout<<"CLIENTE ACTIVO."<<endl;
        return;
        }
        obj.setEstado(true);
        arc.modificarRegistro(obj, pos);
        cout <<"USUARIO DADO DE ALTA CORRECTAMENTE. "<<endl;

    }else{
        cout <<"USUARIO INEXISTENTE. "<<endl;
    }
}
