#include <iostream>
#include <cstring>
#include "clsDetalles.h"
#include "clsProducto.h"
#include "clsArchivoDetalles.h"
#include "clsArchivoProductos.h"

using namespace std;

///SETTERS

void Detalles::setIdDetalle(int idDetalle){
    _idDetalle=idDetalle;
}

void Detalles::setIdProducto(int idProducto){
    _idProducto=idProducto;
}

void Detalles::setIdVenta(int idVentas){
    _idVentas=idVentas;
}

void Detalles::setCantida(int cantidad){
    _cantidad=cantidad;
}

void Detalles::setEstado(bool activo){
    _estado = activo;
}

///GETTERS

int Detalles::getIdDetalle(){
    return _idDetalle;
}

int Detalles::getidProducto(){
    return _idProducto;
}

int Detalles::getIdVenta(){
    return _idVentas;
}

int Detalles::getCantidad(){
    return _cantidad;
}

bool Detalles::getEstado(){
    return _estado;
}

///OTROS METODOS

void Detalles::cargar(){
    Producto prod;
    ArchivoProductos arcProd;
    ArchivoDetalles arcDet;

    cout << "INGRESE EL ID DEL PRODUCTO: ";
    cin >> _idProducto;

    int posProducto = arcProd.buscarRegistros(_idProducto);
    prod = arcProd.leerRegistro(posProducto);

    while (posProducto < 0 || prod.getEstado() == false) {

        if (posProducto < 0) {
            cout << "El producto con ID " << _idProducto << " NO EXISTE. INGRESE OTRO ID: ";
        }
        else if (prod.getEstado() == false) {
            cout << "EL PRODUCTO ESTA DADO DE BAJA. INGRESE OTRO ID: ";
        }

        cin >> _idProducto;

        posProducto = arcProd.buscarRegistros(_idProducto);
        if (posProducto >= 0) {
            prod = arcProd.leerRegistro(posProducto);
        }
    }

    cout << "CANTIDAD QUE SE VENDIO: ";
    cin >> _cantidad;

}

void Detalles::mostrar() {
    ArchivoProductos arcProd;
    Producto prod;

    cout << "||ID DETALLE: " << _idDetalle << endl;
    cout << "||ID VENTA: " << _idVentas << endl;
    cout << "||ID PRODUCTO: " << _idProducto << endl;

    int pos = arcProd.buscarRegistros(_idProducto);
    if (pos >= 0) {
        prod = arcProd.leerRegistro(pos);
        cout << "||PRODUCTO: " << prod.getNombre() << endl;
    }
    else {
        cout << "||PRODUCTO: NO ENCONTRADO" << endl;
    }

    if (pos >= 0) {
        prod = arcProd.leerRegistro(pos);
        cout << "||PRECIO UNITARIO: $" << prod.getPrecioUnitario() << endl;
    }
    else {
        cout << "||PRECIO UNITARIO: NO ENCONTRADO" << endl;
    }


    cout << "||CANTIDAD: " << _cantidad << endl;
    cout << "||IMPORTE TOTAL: " << prod.getPrecioUnitario() *_cantidad << endl;


    cout << "||========= FIN DE LA VENTA ============||" << endl;

}

