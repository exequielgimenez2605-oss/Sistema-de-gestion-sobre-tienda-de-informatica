#include <iostream>
#include <cstring>
#include "clsVentas.h"
#include "clsArchivoVentas.h"
#include "cargarCadena.h"
#include "clsDetalles.h"
#include "clsArchivoDetalles.h"
#include "clsArchivoProductos.h"
#include "clsProducto.h"

using namespace std;

void registrarVenta()
{
    ArchivoVentas arcVen;
    ArchivoDetalles arcDet;
    ArchivoProductos arcProd;

    Ventas ven;
    Detalles det;
    Producto prod;

    int idNuevo = arcVen.generadorId();
    ven.setIdVenta(idNuevo);

    cout << "VENTA Nº: " << idNuevo << endl;
    ven.Cargar();
    ven.setEstado(true);

    det.setIdVenta(idNuevo);

    int idDetalle = arcDet.generadorId();
    det.setIdDetalle(idDetalle);

    cout << "ID DETALLE: " << idDetalle << endl;

    det.cargar();
    det.setEstado(true);

    int idProducto = det.getidProducto();
    int cantVendida = det.getCantidad();

    int pos = arcProd.buscarRegistros(idProducto);
    prod = arcProd.leerRegistro(pos);

    int stockAnterior = prod.getStock();

    if (stockAnterior < cantVendida) {
        cout << "STOCK INSUFICIENTE"<<endl;
        cout << "DISPONIBLE: " << stockAnterior << "UNIDADES"<<endl;
        cout << "SOLICITADO: " << cantVendida << "UNIDADES"<<endl;

        return;
    }


    int nuevoStock = stockAnterior - cantVendida;

    prod.setStock(nuevoStock);
    arcProd.modificarRegistro(prod, pos);

    cout << "STOCK ACTUALIZADO"<<endl;
    cout << "STOCK ANTERIOR : " << stockAnterior << " UNIDADES"<<endl;
    cout << "StOCK ACTUAL   : " << nuevoStock   << " UNIDADES"<<endl;


    if (!arcDet.grabarRegistro(det)) {
        cout << "NO SE PUDO GUARDAR EL DETALLE."<<endl;


        prod.setStock(stockAnterior);
        arcProd.modificarRegistro(prod, pos);
        cout << "STOCK REVERTIDO."<<endl;

        return;
    }


    if (arcVen.grabarRegistro(ven)) {
        cout << "VENTA Y DETALLE GUARDADOS CORRECTAMENTE."<<endl;
    }
    else {
        cout << "NO SE PUDO GUARDAR LA VENTA."<<endl;


        prod.setStock(stockAnterior);
        arcProd.modificarRegistro(prod, pos);
        cout << "STOCK REVERTIDO."<<endl;

    }
    cout <<endl;
    cout <<"||======== RESUMEN DE LA VENTA =========||"<<endl;
    ven.Mostrar();

    cout <<"||======== DETALLE DE LA VENTA =========||"<<endl;
    det.mostrar();




}
void listarVentas()
{
    ArchivoVentas arcVen;
    ArchivoDetalles arcDet;
    Ventas ven;
    Detalles det;

    int cant = arcVen.contarRegistros();

    if(cant <= 0)
    {
        cout << "NO HAY VENTAS PARA MOSTRAR." << endl;
        return;
    }

    cout <<"||======================================||"<<endl;
    cout <<"||           LISTA DE VENTAS            ||"<<endl;
    cout <<"||======================================||"<<endl;
    cout << endl;

    for(int i = 0; i < cant; i++)
    {
        ven = arcVen.leerRegistro(i);

        if(ven.getEstado() == true)
        {
            cout <<"||=============== VENTA ================||"<<endl;
            ven.Mostrar();

            int cantDetalles = arcDet.contarRegistros();

            if (cantDetalles > 0)
            {
                cout << "||======= DETALLES DE LA VENTA =========||" << endl;

                for(int j = 0; j < cantDetalles; j++)
                {
                    det = arcDet.leerRegistro(j);

                    if(det.getIdVenta() == ven.getIdVenta() && det.getEstado() == true)
                    {
                        det.mostrar();
                    }
                }
            }
            else
            {
                cout << "NO HAY DETALLES CARGADOS EN EL ARCHIVO." << endl;
            }

            cout << endl << endl << endl << endl << endl;
        }

    }
}



void buscarVenta()
{

    ArchivoVentas arcVen;
    ArchivoDetalles arcDet;
    Ventas ven;
    Detalles det;
    int id;

    int cant= arcVen.contarRegistros();

    cout<<"INGRESAR EL ID DE LA VENTA: ";
    cin>>id;
    bool encontrado=false;

    for (int i=0; i<cant; i++ )
    {

        ven=arcVen.leerRegistro(i);

        if (id == ven.getIdVenta())
        {

            cout <<"||======================================||"<<endl;
            cout <<"||          VENTA ENCONTRADA            ||"<<endl;
            cout <<"||======================================||"<<endl;
            cout <<endl;
            cout <<"||=============== VENTA ================||"<<endl;
            ven.Mostrar();
            int cantDetalles = arcDet.contarRegistros();
        if (cantDetalles > 0)
        {
            cout <<"||======= DETALLES DE LA VENTA =========||" << endl;

            for(int j = 0; j < cantDetalles; j++)
            {
                det = arcDet.leerRegistro(j);
                if(det.getIdVenta() == ven.getIdVenta() && det.getEstado() == true)
                {
                    det.mostrar();
                }
            }
        }
        else
        {
            cout << "NO HAY DETALLES CARGADOS EN EL ARCHIVO." << endl;
        }
            encontrado=true;
        }

    }

    if(encontrado==false)
    {
        cout <<"||======================================||"<<endl;
        cout <<"||        VENTA NO ENCONTRADA           ||"<<endl;
        cout <<"||======================================||"<<endl;
    }
}

void darDeBajaVenta()
{

    cout<<"INGRESE EL ID DE LA VENTA QUE QUIRE DAR DE BAJA: ";
    int id;
    cin>>id;

    ArchivoVentas arcVen;
    ArchivoDetalles arcDet;
    ArchivoProductos arcProd;
    Ventas ven;
    Detalles det;
    Producto prod;

    int pos = arcVen.buscarRegistros(id);
    if (pos>=0)
    {   ven = arcVen.leerRegistro(pos);
        ven.setEstado(false);
        arcVen.modificarRegistro(ven,pos);
        cout<<"VENTA DADA DE BAJA CORRECTAMENTE. "<<endl;

        int cantDetalles = arcDet.contarRegistros();
        int detBaja = 0;

        for (int i=0; i<cantDetalles; i++)
        {

            det= arcDet.leerRegistro(i);

            if (det.getIdVenta()== id && det.getEstado()==true)
            {
                det.setEstado(false);
                arcDet.modificarRegistro(det,i );
                detBaja++;

            }

        }
        cout<<"SE DIERON DE BAJA "<<detBaja <<" ASOCIADOS A LA VENTA " <<endl;
    }
    else
    {
        cout<<"NO EXITE LA VENTA INGRESADA. "<<endl;
    }
}
void listarVentasBaja()
{
    ArchivoVentas arcVen;
    ArchivoDetalles arcDet;

    int cant = arcVen.contarRegistros();

    if(cant <= 0)
    {
        cout <<" NO HAY VENTAS PARA MOSTRAR. "<<endl;
        return;

    }
    cout <<"||======================================||"<<endl;
    cout <<"||       LISTA DE VENTAS DE BAJA        ||"<<endl;
    cout <<"||======================================||"<<endl;
    arcVen.listarBaja();
    arcDet.listaDeBaja();
}


void DarAltaVenta()
{

    cout<<"INGRESE EL ID DE LA VENTA QUE QUIRE DAR DE ALTA: ";
    int id;
    cin>>id;

    ArchivoVentas arcVen;
    ArchivoDetalles arcDet;
    Ventas ven;
    Detalles det;

    int pos = arcVen.buscarRegistros(id);
    if (pos>=0)
    {
        ven = arcVen.leerRegistro(pos);

        if( ven.getEstado()== true)
        {
            cout<<"VENTA DADA DE ALTA CORRECTAMENTE. "<<endl;
            return;
        }


        ven.setEstado(true);
        arcVen.modificarRegistro(ven, pos);

        cout<<"VENTA DADA DE ALTA CORRECTAMENTE "<<endl;

        int cantDetalles = arcDet.contarRegistros();
        int detAlta = 0;

        for (int i=0; i<cantDetalles; i++)
        {

            det= arcDet.leerRegistro(i);

            if (det.getIdVenta()== id && det.getEstado()==false)
            {

                det.setEstado(true);
                arcDet.modificarRegistro(det,i );
                detAlta++;

            }

        }
        cout<<"SE AGREGARON "<<detAlta <<" ASOCIADOS A LA VENTA " <<endl;

    }
    else
    {
        cout<<"NO EXITE LA VENTA INGRESADA. "<<endl;;
    }

}
