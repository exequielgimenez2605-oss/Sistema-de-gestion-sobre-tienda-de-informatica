#include <iostream>
#include <cstring>
#include "funcionesDetalle.h"
#include "clsDetalles.h"
#include "clsArchivoDetalles.h"

using namespace std;

void registrarDetalle(){

Detalles obj;
ArchivoDetalles arc;

cout<<"INGRESE EL ID DEL DETALLE: ";
int id;
cin>>id;

 if(arc.buscarRegistros(id) >= 0) {
        cout << "ERROR: YA EXISTE UN DETALLE CON ESE ID. NO SE PUEDE AGREGAR OTRO." << endl;
        return;
    }

    obj.setIdDetalle(id);
    obj.cargar();
    obj.setEstado(true);

    if(arc.grabarRegistro(obj)){

        cout<<"SE AGREGO CORRECTAMENTE."<<endl;

    }
    else{ cout<<"NO SE PUDO AGREGAR. "<<endl;}
}


void listarDetalles(){
 ArchivoDetalles arc;

int cant= arc.contarRegistros();

    if(cant<=0){
        cout<<"NO HAY DETALLES PARA MOSTRAR "<<endl;
    }
        cout <<"||======================================||"<<endl;
        cout <<"||           LISTA DE DETALLES          ||"<<endl;
        cout <<"||======================================||"<<endl;
        arc.listar();

}


void buscarDetalle(){

Detalles obj;
ArchivoDetalles arc;

int cant= arc.contarRegistros();

cout<<"INGRESAR EL  ID DETALLE: ";
int id;
cin>>id;
bool encontrado=false;



for (int i=0;i<cant;i++ ){

    obj=arc.leerRegistro(i);

    if (id == obj.getIdDetalle()){

            cout <<"||======================================||"<<endl;
            cout <<"||          DETALLE ENCONTRADO          ||"<<endl;
            cout <<"||======================================||"<<endl;

        obj.mostrar();
        encontrado=true;
    }

}

if(encontrado==false){
        cout <<"||======================================||"<<endl;
        cout <<"||        DETALLE NO ENCONTRADO         ||"<<endl;
        cout <<"||======================================||"<<endl;


    }

}


void darDeBajaDetalle(){

    cout<<"INGRESE EL ID QUE QUIRE DAR DE BAJA: ";
    int id;
    cin>>id;


    ArchivoDetalles arc;
    Detalles obj;


    int pos = arc.buscarRegistros(id);
    if (pos>=0){
        Detalles obj = arc.leerRegistro(pos);
        obj.setEstado(false);
        arc.modificarRegistro(obj,pos);
        cout<<"DETALLE DADO DE BAJA CORRECTAMENTE. "<<endl;
    }else{

        cout<<"NO EXITE EL DETALLE INGRESADO. "<<endl;
    }
}

void modificarDetalle(){

    cout<<"INGRESA ID DE DETALLES: ";
    int id;
    cin>>id;

    ArchivoDetalles det;

    int aux = det.buscarRegistros(id);

    if(aux<0){
        cout<<"NO EXISTE"<<endl;
        return;
    }

    Detalles obj = det.leerRegistro(aux);

    cout<<"INGRESE LA NUEVA CANTIDAD DE PRODUCTO: ";
    int cant;
    cin>>cant;
    obj.setCantida(cant);
    det.modificarRegistro(obj, aux);

}
void listarDetallesBaja(){
 ArchivoDetalles arc;

int cant= arc.contarRegistros();

    if(cant<=0){
        cout<<"NO HAY DETALLES DADOS DE BAJA PARA MOSTRAR "<<endl;
    }
        cout <<"||======================================||"<<endl;
        cout <<"||    LISTA DE DETALLES DADOS DE BAJA   ||"<<endl;
        cout <<"||======================================||"<<endl;
        arc.listaDeBaja();

}

void DarAltaDetalle(){

    ArchivoDetalles obj;

    cout<<"INGRESE EL ID DEL DETALLE A DAR DE ALTA: ";
    int id;
    cin>>id;
    int aux = obj.buscarRegistros(id);
    if(aux<0){
        cout<<"NO EXISTE ESE DETALLE"<<endl;
        return;
    }

    Detalles det = obj.leerRegistro(aux);
    if(det.getEstado()==true){
        cout<<"ESE DETALLE NO SE ENCUENTRA DADO DE BAJA:"<<endl;
        return;
    }
    det.setEstado(true);
    obj.modificarRegistro(det, aux);

}



