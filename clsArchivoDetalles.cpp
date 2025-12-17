#include <iostream>
#include <cstring>
#include "clsArchivoDetalles.h"
#include "clsDetalles.h"

using namespace std;

bool ArchivoDetalles::grabarRegistro(Detalles obj){

    FILE *d=fopen(_nombre,"ab");

    if(d == nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return false;
    }

 bool escribio = fwrite(&obj, sizeof obj, 1, d);
    fclose(d);
    return escribio;
}

void ArchivoDetalles::listar(){

    Detalles mos;
    FILE *d=fopen(_nombre,"rb");

    if(d == nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return;
    }

    while(fread(&mos, sizeof(Detalles), 1, d)==1){
        if(mos.getEstado()){
            mos.mostrar();
        }
    }
    fclose(d);
}

ArchivoDetalles::ArchivoDetalles(const char *n){
    strcpy(_nombre, n);
}

int ArchivoDetalles::contarRegistros(){

    FILE *p = fopen(_nombre, "rb");
    if(p == nullptr){

        return -1;
    }
    fseek(p,0,2);

    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Detalles);
}

int ArchivoDetalles::buscarRegistros(int id){

    Detalles obj;
    int cantReg = contarRegistros();
    for(int i=0;i<cantReg;i++){
        obj = leerRegistro(i);
            if(obj.getIdDetalle() == id){

                return i;
            }

    }
    return -1;
}

Detalles ArchivoDetalles::leerRegistro(int lee){

    Detalles obj;
    obj.setIdDetalle(-1);
    FILE *d;

    d=fopen(_nombre,"rb");
    if(d==nullptr) return obj;

    fseek(d, lee * sizeof obj, 0);
    fread(&obj, sizeof(Detalles), 1, d);
    fclose(d);
    return obj;
}



bool ArchivoDetalles::modificarRegistro(Detalles obj, int pos){

    FILE *d=fopen(_nombre,"rb+");
    if(d == nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    fseek(d, pos * sizeof obj, SEEK_SET);
    bool escribo = fwrite(&obj, sizeof obj, 1, d);
    fclose(d);
    return escribo;
}
void ArchivoDetalles::listaDeBaja(){

    Detalles mos;
    FILE *d=fopen(_nombre,"rb");

    if(d == nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return;
    }

    while(fread(&mos, sizeof(Detalles), 1, d)==1){
        if(mos.getEstado()==false){
            mos.mostrar();
        }
    }
    fclose(d);
}
int ArchivoDetalles::generadorId(){
    FILE *p = fopen(_nombre, "rb");
    if(p == nullptr){
        return 1;
    }
    fseek(p,0,SEEK_END);
    long bytes = ftell(p);
    fclose(p);

    int cantReg = bytes / sizeof(Detalles);
    return cantReg + 1;

}
