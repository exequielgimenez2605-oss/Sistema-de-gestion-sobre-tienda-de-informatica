#include <iostream>
#include "funcionesDetalle.h"
using namespace std;

void menuDetalles(){
    int opcionPrincipal;

    while(true){

        system("cls");

    cout << "||========================||"<<endl;
    cout << "||       GESTIONBIT       ||"<<endl;
    cout << "||========================||"<<endl;
    cout << "||      MENU DETALLES     ||"<<endl;
    cout << "||========================||"<<endl;
    cout << "||1 REGISTRAR DETALLE     ||"<<endl;
    cout << "||2 LISTAR DETALLES       ||"<<endl;
    cout << "||3 BUSCAR DETALLE        ||"<<endl;
    cout << "||4 DAR DE BAJA DETALLE   ||"<<endl;
    cout << "||5 MODIFICAR DETALLE     ||"<<endl;
    cout << "||0 ATRAS                 ||"<<endl;
    cout << "||========================||"<<endl;
    cout << "   INGRESAR OPCION: ";
    cin >> opcionPrincipal;
    system("cls");

    switch(opcionPrincipal){
    case 1: registrarDetalle();

        break;
    case 2: listarDetalles();

        break;
    case 3: buscarDetalle();

        break;
    case 4: darDeBajaDetalle();

        break;
    case 5: modificarDetalle();

        break;
    case 6: listarDetallesBaja();

        break;
    case 7: DarAltaDetalle();

        break;
    case 0: return;

        return;

        }
    system("pause");
  }
}
