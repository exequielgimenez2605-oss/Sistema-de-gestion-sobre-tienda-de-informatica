#include <iostream>
#include <cstring>
#include "clsArchivoVentas.h"
#include "clsVentas.h"

using namespace std;


ArchivoVentas::ArchivoVentas(const char *n){
    strcpy(_nombre, n);
}


bool ArchivoVentas::grabarRegistro(Ventas obj){
    FILE *p = fopen(_nombre, "ab");

    if(p == nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
void ArchivoVentas::listar(){

    Ventas obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, sizeof(Ventas), 1, p)==1){
        if(obj.getEstado()){
            obj.Mostrar();
        }
    }
    fclose(p);
}

int ArchivoVentas::contarRegistros(){

    FILE *p = fopen(_nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p,0,2);
    int bytes = ftell(p);
    return bytes/sizeof(Ventas);
}

int ArchivoVentas::buscarRegistros(int id){
    Ventas obj;
    int cantReg = contarRegistros();
    for(int i=0;i<cantReg;i++){
        obj = leerRegistro(i);
        if(obj.getIdVenta() == id){
            return i;
        }
    }
    return -1;
}
Ventas ArchivoVentas::leerRegistro(int lr){
    Ventas obj;
    obj.setIdVenta(-1);
    FILE *p;
    p = fopen(_nombre,"rb");

    if(p == nullptr){
        return obj;
    }
    fseek(p, lr * sizeof obj, 0);
    fread(&obj, sizeof(Ventas), 1, p);
    fclose(p);
    return obj;
}
bool ArchivoVentas::modificarRegistro(Ventas obj, int pos){
    FILE *p = fopen(_nombre, "rb+");
    if(p == nullptr){
        cout <<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    fseek(p,pos * sizeof obj, SEEK_SET);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

void ArchivoVentas::listarBaja(){

    Ventas obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, sizeof(Ventas), 1, p)==1){
        if(obj.getEstado()==false){
            obj.Mostrar();
        }
    }
    fclose(p);
}
int ArchivoVentas::generadorId(){
    FILE *p = fopen(_nombre, "rb");
    if(p == nullptr){
        return 1;
    }
    fseek(p,0,SEEK_END);
    long bytes = ftell(p);
    fclose(p);

    int cantReg = bytes / sizeof(Ventas);
    return cantReg + 1;
}
