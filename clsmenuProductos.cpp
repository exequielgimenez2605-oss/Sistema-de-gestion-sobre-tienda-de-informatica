#include <iostream>
#include "funcionesProducto.h"

using namespace std;

void menuProductos(){

    int opcionPrincipal;

    while(true){
        system("cls");

    cout << "||========================||"<<endl;
    cout << "||       GESTIONBIT       ||"<<endl;
    cout << "||========================||"<<endl;
    cout << "||      MENU PRODUCTOS    ||"<<endl;
    cout << "||========================||"<<endl;
    cout << "||1 REGISTRAR PRODUCTO    ||"<<endl;
    cout << "||2 LISTAR PRODUCTOS      ||"<<endl;
    cout << "||3 BUSCAR PRODUCTO       ||"<<endl;
    cout << "||4 DAR DE BAJA PRODUCTO  ||"<<endl;
    cout << "||5 MODIFICAR PRODUCTO    ||"<<endl;
    cout << "||6 LISTAR DADOS DE BAJA  ||"<<endl;
    cout << "||7 DAR DE ALTA           ||"<<endl;
    cout << "||0 ATRAS                 ||"<<endl;
    cout << "||========================||"<<endl;
    cout << "   INGRESAR OPCION: ";
    cin >> opcionPrincipal;
    system("cls");

    switch(opcionPrincipal){
    case 1:
        registrarProducto();
        break;
    case 2:
        listarProductos();
        break;
    case 3:
        buscarProducto();
        break;
    case 4:
        darDeBajaProducto();
        break;
    case 5:
        modificarProducto();
        break;
    case 6:
        listarProductoBaja();
        break;
    case 7:
        darAltaProducto();
        break;
    case 0:
        return;
        }
    system("pause");
    }
}
