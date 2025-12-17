#include <iostream>
#include <cstring>
#include "clsArchivoProductos.h"
#include "clsProducto.h"

using namespace std;

ArchivoProductos::ArchivoProductos(const char *n){
    strcpy(_nombre, n);
}


bool ArchivoProductos::grabarRegistro(Producto obj){
    FILE *p = fopen(_nombre, "ab");

    if(p == nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
void ArchivoProductos::listar(){

    Producto obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, sizeof(Producto), 1, p)==1){
        if(obj.getEstado()){
            obj.mostrarProducto();
        }
    }
    fclose(p);
}

int ArchivoProductos::contarRegistros(){

    FILE *p = fopen(_nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p,0,2);
    int bytes = ftell(p);
    return bytes/sizeof(Producto);
}

int ArchivoProductos::buscarRegistros(int id){
    Producto obj;
    int cantReg = contarRegistros();
    for(int i=0;i<cantReg;i++){
        obj = leerRegistro(i);
        if(obj.getIdProducto() == id){
            return i;
        }
    }
    return -1;
}
Producto ArchivoProductos::leerRegistro(int lr){
    Producto obj;
    obj.setIdProducto(-1);
    FILE *p;
    p = fopen(_nombre,"rb");

    if(p == nullptr){
        return obj;
    }
    fseek(p, lr * sizeof obj, 0);
    fread(&obj, sizeof(Producto), 1, p);
    fclose(p);
    return obj;
}
bool ArchivoProductos::modificarRegistro(Producto obj, int pos){
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
void ArchivoProductos::listarBaja(){

    Producto obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, sizeof(Producto), 1, p)==1){
        if(obj.getEstado()==false){
            obj.mostrarProducto();
        }
    }
    fclose(p);
}
int ArchivoProductos::generadorId(){
    FILE *p = fopen(_nombre, "rb");
    if(p == nullptr){
        return 1;
    }
    fseek(p,0,SEEK_END);
    long bytes = ftell(p);
    fclose(p);

    int cantReg = bytes / sizeof(Producto);
    return cantReg + 1;
}
