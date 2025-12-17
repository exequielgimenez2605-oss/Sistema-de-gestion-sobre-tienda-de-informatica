#include <iostream>
#include "funcionesVenta.h"

using namespace std;

void menuVentas(){

    int opcionPrincipal;

    while(true){

        system("cls");

        cout << "||========================||"<<endl;
        cout << "||       GESTIONBIT       ||"<<endl;
        cout << "||========================||"<<endl;
        cout << "||       MENU VENTAS      ||"<<endl;
        cout << "||========================||"<<endl;
        cout << "||1 REGISTRAR VENTA       ||"<<endl;
        cout << "||2 LISTAR VENTAS         ||"<<endl;
        cout << "||3 BUSCAR VENTA          ||"<<endl;
        cout << "||4 DAR DE BAJA VENTA     ||"<<endl;
        cout << "||5 LISTAR VENTAS DE BAJA ||"<<endl;
        cout << "||6 DAR DE ALTA VENTA     ||"<<endl;
        cout << "||0 ATRAS                 ||"<<endl;
        cout << "||========================||"<<endl;
        cout << "   INGRESAR OPCION: ";
        cin >> opcionPrincipal;
        system("cls");

        switch(opcionPrincipal){
        case 1:
            registrarVenta();
            break;
        case 2:
            listarVentas();
            break;
        case 3:
            buscarVenta();
            break;
        case 4:
            darDeBajaVenta();
            break;
        case 5:
            listarVentasBaja();
            break;
        case 6:
            DarAltaVenta();
            break;
        case 0:
            return;
        }
        system("pause");
    }
}
