#include <iostream>
#include "clsArchivoVentas.h"
#include "clsVentas.h"
#include "clsArchivoDetalles.h"
#include "clsDetalles.h"
#include "reportes.h"


using namespace std;

///MAYOR VENTA DEL AÑO


void mayorVentaAno(){

    ArchivoVentas auxV;
    ArchivoDetalles auxD;

    cout<< "INGRESE UN AÑO: ";
    int ano;
    cin>>ano;

    int posV = auxV.buscarRegistros(ano);
    if(posV > 0){
        cout<<"NO HUVO VENTAS ESE AÑO"<<endl;
        return;
    }

    Ventas objV = auxV.leerRegistro(posV);

    int IDD = objV.getIdVenta();
    int posD = auxD.buscarRegistros(IDD);

    Detalles objD = auxD.leerRegistro(posD);


    objD.mostrar();


}


