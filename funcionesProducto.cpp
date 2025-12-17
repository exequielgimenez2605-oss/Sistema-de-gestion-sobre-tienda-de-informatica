#include <iostream>
#include <cstring>
#include "clsProducto.h"
#include "clsArchivoProductos.h"
#include "funcionesMenus.h"
#include "funcionesProducto.h"
#include "cargarCadena.h"

using namespace std;

void registrarProducto(){
    Producto obj;
    ArchivoProductos arc;

    int idNuevo = arc.generadorId();
    obj.setIdProducto(idNuevo);

    cout <<"PRODUCTO Nro: "<<idNuevo<<endl;


    obj.cargarProducto();
    obj.setEstado(true);

    if(arc.grabarRegistro(obj)){
        cout <<"SE AGREGO CORRECTAMENTE" << endl;
    }else{
        cout <<"NO SE PUDO GUARDAR EL PRODUCTO" << endl;
    }
}
void listarProductos(){

ArchivoProductos arc;
int cant = arc.contarRegistros();

    if(cant <= 0){
        cout <<"NO HAY PRODUCTOS PARA MOSTRAR."<<endl;
        return;
    }
    cout <<"||======================================||"<<endl;
    cout <<"||          LISTA DE PRODUCTOS          ||"<<endl;
    cout <<"||======================================||"<<endl;
    arc.listar();
}
void buscarProducto(){
    Producto obj;
    ArchivoProductos arc;

    int cantidadRegistros = arc.contarRegistros();

    cout << "INGRESE EL ID DEL PRODUCTO QUE QUIERE BUSCAR: ";
    int id;
    cin >> id;

    bool encontrado = false;

    for(int i=0;i<cantidadRegistros;i++){
        obj = arc.leerRegistro(i);
        if(id == obj.getIdProducto()){

            cout <<"||======================================||"<<endl;
            cout <<"||         PRODUCTO ENCONTRADO          ||"<<endl;
            cout <<"||======================================||"<<endl;
        obj.mostrarProducto();
        encontrado = true;
        }
    }
if(encontrado == false){

    cout <<"||======================================||"<<endl;
    cout <<"||        PRODUCTO NO ENCONTRADO        ||"<<endl;
    cout <<"||======================================||"<<endl;
    }
}
void darDeBajaProducto(){
    ArchivoProductos arc;
    Producto obj;

    cout<<"INGRESE EL ID QUE QUIERE DAR DE BAJA ";
    int id;
    cin>>id;

    int pos = arc.buscarRegistros(id);
    if(pos>=0){
    obj = arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
    cout << "PRODUCTO DADO DE BAJA CORRECTAMENTE. "<<endl;
    }else{
    cout<<"NO EXISTE EL PRODUCTO INGRESADO. "<<endl;

    }

}
void modificarProducto(){
    ArchivoProductos arc;
    Producto obj;
    cout<<"INGRESA EL ID DEL PRODUCTO: "<<endl;
    int id;
    cin >>id;

    int pos = arc.buscarRegistros(id);
    if(pos<0){
        cout<<"NO EXISTE ESE ID. "<<endl;
    }
    obj = arc.leerRegistro(pos);

    while(true){
        int opcionMod;
        system("cls");
        cout <<"||=====================||"<<endl;
        cout <<"||===== MODIFICAR======||"<<endl;
        cout <<"||=====================||"<<endl;
        cout <<"||1 NOMBRE             ||"<<endl;
        cout <<"||2 MARCA              ||"<<endl;
        cout <<"||3 PRECIO             ||"<<endl;
        cout <<"||4 DESCRIPCION        ||"<<endl;
        cout <<"||5 STOCK              ||"<<endl;
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
            cout<<"INGRESE LA MARCA: ";
            char marcaNueva[30];
            cargarCadena(marcaNueva, 29);
            obj.setMarca(marcaNueva);
            cout <<endl;
            cout<<"MARCA ACTUALIZADA CORRECTAMENTE."<<endl;
            break;
        case 3:
            cout<<"INGRESE EL NUEVO PRECIO: ";
            int nuevoPrecio;
            cin >> nuevoPrecio;
            obj.setPrecioUnitario(nuevoPrecio);
            cout<<endl;
            cout<<"PRECIO ACTUALIZADO CORRECTAMENTE."<<endl;
            break;
        case 4:
            cout<<"INGRESE LA NUEVA DESCRIPCION: ";
            char descripcionNueva[50];
            cargarCadena(descripcionNueva,49);
            obj.setDescripcion(descripcionNueva);
            cout<<endl;
            cout<<"DESCRIPCION ACTUALIZADA CORRECTAMENTE."<<endl;
            break;
        case 5:
            cout<<"INGRESE EL NUEVO STOCK:";
            int stockNuevo;
            cin >>stockNuevo;
            obj.setStock(stockNuevo);
            cout<<endl;
            cout<<"NUEVO STOCK ACTUALIZADO CORRECTAMENTE."<<endl;
            break;
        case 0:
            return;

        }
    system("pause");
    arc.modificarRegistro(obj, pos);
    }
}
void listarProductoBaja(){

ArchivoProductos arc;
int cant = arc.contarRegistros();

    if(cant <= 0){
        cout <<"NO HAY PRODUCTOS PARA MOSTRAR."<<endl;
        return;
    }
    cout <<"||======================================||"<<endl;
    cout <<"||          LISTA DE PRODUCTOS          ||"<<endl;
    cout <<"||======================================||"<<endl;
    arc.listarBaja();
}
void darAltaProducto(){
    ArchivoProductos arc;
    Producto obj;

    cout<<"INGRESE EL ID QUE QUIERE DAR DE ALTA ";
    int id;
    cin>>id;

    int pos = arc.buscarRegistros(id);
    if(pos>=0){
    obj = arc.leerRegistro(pos);
    obj.setEstado(true);
    arc.modificarRegistro(obj, pos);
    cout << "PRODUCTO DADO DE ALTA CORRECTAMENTE. "<<endl;
    }else{
    cout<<"NO EXISTE EL PRODUCTO INGRESADO. "<<endl;

    }

}
