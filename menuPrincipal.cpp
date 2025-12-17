#include <iostream>
#include <cstring>
#include "funcionesCliente.h"
#include "funcionesDetalle.h"
#include "funcionesProducto.h"
#include "funcionesVenta.h"
#include "funcionesMenus.h"
using namespace std;

void menuPrincipal()
{

    int opcionPrincipal;
    while(true)
    {

        system("cls");
        cout<<"||========================||"<<endl;
        cout<<"||       GESTIONBIT       ||"<<endl;
        cout<<"||========================||"<<endl;
        cout<<"||      MENU PRINCIPAL    ||"<<endl;
        cout<<"||========================||"<<endl;
        cout<<"||1 CLIENTES              ||"<<endl;
        cout<<"||2 PRODUCTOS             ||"<<endl;
        cout<<"||3 VENTAS                ||"<<endl;
        cout<<"||4 REPORTES              ||"<<endl;
        cout<<"||0 SALIR                 ||"<<endl;
        cout<<"||========================||"<<endl;
        cout<<"   INGRESAR OPCION: ";
        cin>>opcionPrincipal;

        switch(opcionPrincipal)
        {
        case 1:
            menuClientes();
            break;
        case 2:
            menuProductos();
            break;
        case 3:
            menuVentas();
            break;
        case 4:
           menuReportes();
            break;
        case 0:
            return;
            break;
        }

    }

}






