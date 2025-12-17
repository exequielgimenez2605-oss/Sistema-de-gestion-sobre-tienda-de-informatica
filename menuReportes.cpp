#include<iostream>
#include "funcionesMenus.h"
#include "clsClientes.h"
#include "clsDetalles.h"
#include "clsVentas.h"
#include "clsProducto.h"
#include "clsFecha.h"
#include "clsFuncionesReporte.h"

using namespace std;
void menuReportes()
{

    int opcionPrincipal;
    while(true)
    {

        system("cls");
        cout<<"||============================================================||"<<endl;
        cout<<"||                          GESTIONBIT                        ||"<<endl;
        cout<<"||============================================================||"<<endl;
        cout<<"||                         MENU REPORTES                      ||"<<endl;
        cout<<"||============================================================||"<<endl;
        cout<<"||1 RECAUDACION POR CLIENTE                                   ||"<<endl;
        cout<<"||2 EL MES CON MENOR VENTA EN EL AÑO 2025                     ||"<<endl;
        cout<<"||3 MES CON MAYOR VENTA DEL AÑO 2024 y 2025                   ||"<<endl;
        cout<<"||4 MAYOR FACTURACION EN 2024 Y 2025                          ||"<<endl;
        cout<<"||5 PRODUCTO MAS VENDIDO EN LOS ULTIMOS 2 AÑOS                ||"<<endl;
        cout<<"||6 PROMEDIO PRODUCTO POR VENTA                               ||"<<endl;
        cout<<"||0 SALIR                                                     ||"<<endl;
        cout<<"||============================================================||"<<endl;
        cout<<"   INGRESAR OPCION: ";
        cin>>opcionPrincipal;
        system("cls");

        switch(opcionPrincipal)
        {
        case 1:
            recaudacionPorCliente();
            break;
        case 2:
            MesConMenorVenta2025();
            break;
        case 3:
            mayorVentaAnios();
            break;
        case 4:
            MayorFacturacion2024y2025();
            break;
        case 5:
            ProductoMasVendidoEnLosUltimos2();
            break;
        case 6:
            PromedioProductosPorVenta();
            break;
        case 0:
            return;
            break;
        }
        system("pause");
    }

}

