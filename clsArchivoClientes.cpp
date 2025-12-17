#include <iostream>
#include <cstring>
#include "clsArchivoClientes.h"

using namespace std;

ArchivoClientes::ArchivoClientes(const char *n){
    strcpy(_nombre, n);
}

int ArchivoClientes::contarRegistros(){

    FILE *p = fopen(_nombre, "rb");
    if(p == nullptr){

        return -1;
    }
    fseek(p,0,2);

    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Clientes);
}

int ArchivoClientes::buscarRegistros(const char *cuit){

    Clientes obj;
    int cantReg = contarRegistros();
    for(int i=0;i<cantReg;i++){
        obj = leerRegistro(i);
            if(strcmp(obj.getCuit(),cuit) == 0){

                return i;
            }

    }
    return -1;
}

Clientes ArchivoClientes::leerRegistro(int pos){

    FILE *p = fopen(_nombre, "rb");
    Clientes obj;
    if(p == nullptr){
        obj.setCuit("error");
        return obj;
    }
    fseek(p,pos * sizeof obj, SEEK_SET);
    obj.setCuit("error");
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;

}
bool ArchivoClientes::grabarRegistro(Clientes obj)
{
    FILE *p = fopen(_nombre, "ab");
    if(p == nullptr)
    {
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;

}
bool ArchivoClientes::modificarRegistro(Clientes obj, int pos)
{
    FILE *p = fopen(_nombre, "rb+");
    if(p == nullptr)
    {
        return false;
    }
    fseek(p, pos * sizeof obj, SEEK_SET);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
void ArchivoClientes::listar()
{
    Clientes obj;
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++)
    {
        obj = leerRegistro(i);
        if(obj.getEstado())
        {
                obj.Mostrar();
            }
        }
    }
void ArchivoClientes::listarDeBaja()
{
    Clientes obj;
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++)
    {
        obj = leerRegistro(i);
        if(obj.getEstado()==false)
        {
                obj.Mostrar();

            }
        }
    }
