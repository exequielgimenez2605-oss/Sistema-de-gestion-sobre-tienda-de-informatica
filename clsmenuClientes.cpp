#include <iostream>
#include "funcionesCliente.h"

using namespace std;

void menuClientes(){

    int opcionPrincipal;

    while(true){
        system("cls");

    cout << "||=========================||"<<endl;
    cout << "||       GESTIONBIT        ||"<<endl;
    cout << "||=========================||"<<endl;
    cout << "||      MENU CLIENTES      ||"<<endl;
    cout << "||=========================||"<<endl;
    cout << "||1 REGISTRAR CLIENTE      ||"<<endl;
    cout << "||2 LISTAR CLIENTES        ||"<<endl;
    cout << "||3 BUSCAR CLIENTE         ||"<<endl;
    cout << "||4 DAR DE BAJA CLIENTE    ||"<<endl;
    cout << "||5 MODIFICAR CLIENTE      ||"<<endl;
    cout << "||6 CLIENTES DADOS DE BAJA ||"<<endl;
    cout << "||7 DAR DE ALTA CLIENTES   ||"<<endl;
    cout << "||0 ATRAS                  ||"<<endl;
    cout << "||=========================||"<<endl;
    cout << "   INGRESAR OPCION: ";
    cin >> opcionPrincipal;

    system("cls");
    switch(opcionPrincipal){
    case 1:
        registrarCliente();
        break;
    case 2:
        listarClientes();
        break;
    case 3:
        buscarCliente();
        break;
    case 4:
        darDeBajaCliente();
        break;
    case 5:
        modificarCliente();
        break;
    case 6:
        listarClientesBaja();
        break;
    case 7:
        darAltaClientes();
        break;
    case 0:

      return;
        }
    system("pause");
    }
}
