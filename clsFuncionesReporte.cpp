#include <iostream>
#include "clsArchivoClientes.h"
#include "clsArchivoDetalles.h"
#include "clsArchivoVentas.h"
#include "clsArchivoProductos.h"
#include "clsClientes.h"
#include "clsDetalles.h"
#include "clsVentas.h"
#include <cstring>

using namespace std;

void recaudacionPorCliente()
{

    cout << "||======================================||"<<endl;
    cout << "||       RECAUDACION POR  CLIENTE       ||"<<endl;
    cout << "||======================================||"<<endl;
    cout <<endl;

    ArchivoClientes arcCl("Clientes.dat");
    Clientes cl;

    ArchivoDetalles arcDet("Detalles.dat");
    Detalles det;

    ArchivoVentas arcVen("Ventas.dat");
    Ventas ven;

    ArchivoProductos arcProd("Productos.dat");
    Producto prod;

    int cantRegClientes = arcCl.contarRegistros();
    int cantRegDetalles = arcDet.contarRegistros();
    int cantRegVentas = arcVen.contarRegistros();
    int cantRegProducto=arcProd.contarRegistros();



    for(int i = 0; i < cantRegClientes; i++)
    {
        cl = arcCl.leerRegistro(i);

        float recaudacionCliente = 0;


        char CuitCliente[20];
        strcpy(CuitCliente, cl.getCuit());


        for(int j = 0; j < cantRegVentas; j++)
        {
            ven = arcVen.leerRegistro(j);

            if(strcmp(ven.getCuit(), CuitCliente) == 0)
            {
                int idVenta = ven.getIdVenta();


                for(int k = 0; k < cantRegDetalles; k++)
                {
                    det = arcDet.leerRegistro(k);


                    if(det.getIdVenta() == idVenta)
                    {
                        int idProducto= det.getidProducto();

                        for (int l=0; l<cantRegProducto; l++)
                        {
                            prod= arcProd.leerRegistro(l);

                            if (prod.getIdProducto() == idProducto)
                            {


                                float subtotal = det.getCantidad() * prod.getPrecioUnitario();
                                recaudacionCliente += subtotal;
                                break;
                            }

                        }


                    }
                }
            }
        }

        cout << "||======================================||"<<endl;
        cout << "||CLIENTE: " << cl.getNombre() << endl;
        cout << "||CUIT: " << CuitCliente << endl;
        cout << "||RECAUDACION: $" << recaudacionCliente << endl;
        cout << "||======================================||"<<endl;
         cout << endl << endl << endl;
    }
    cout <<"||======================================||"<<endl;
    cout <<"||           FIN DEL REPORTE            ||"<<endl;
    cout <<"||======================================||"<<endl;

}
void MesConMenorVenta2025()
{
    cout <<"||=====================================================||"<<endl;
    cout <<"||               MES CON MENOR VENTAS 2025             ||"<<endl;
    cout <<"||=====================================================||"<<endl;
    cout <<endl;

    ArchivoVentas arcVen("Ventas.dat");
    Ventas ven;

    int cantRegVentas = arcVen.contarRegistros();
    if (cantRegVentas == 0)
    {
        cout << "NO HUBO VENTAS." << endl;
        return;
    }

    int contadorMes[12] {};
    string nombremes[12] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio", "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};


    for (int i = 0; i < cantRegVentas; i++)
    {
        ven = arcVen.leerRegistro(i);
        int mes = ven.getFechaDeVenta().getMes();
        int anio = ven.getFechaDeVenta().getAnio();

        if (anio == 2025 && mes >= 1 && mes <= 12)
        {
            contadorMes[mes - 1]++;
        }
    }


    int mesMin = -1;
    for(int i = 0; i < 12; i++)
    {
        if(contadorMes[i] != 0)
        {
            if(mesMin == -1 || contadorMes[i] < contadorMes[mesMin])
            {
                mesMin = i;
            }
        }
    }

    if(mesMin != -1)
    {
        cout << "EL MES CON MENOR VENTA EN 2025 ES: " << nombremes[mesMin] << " CON " << contadorMes[mesMin] << " VENTA/S." << endl;
    }
    else
    {
        cout << "NO HUBO VENTAS EN 2025." << endl;
    }
    cout <<endl;
    cout <<"||=====================================================||"<<endl;
    cout <<"||                    FIN DEL REPORTE                  ||"<<endl;
    cout <<"||=====================================================||"<<endl;


}
void mayorVentaAnios()
{

    cout <<"||=====================================================||"<<endl;
    cout <<"||     MES CON  MAYOR VENTAS DEL AÑO 2024 Y 2025       ||"<<endl;
    cout <<"||=====================================================||"<<endl;
    cout <<endl;

    ArchivoVentas arcVen("Ventas.dat");
    Ventas ven;
    int cantRegVentas = arcVen.contarRegistros();

    if(cantRegVentas == 0)
    {
        cout << "NO HAY VENTAS REGISTRADAS." << endl;
        return;
    }

    int contadorMes2024[12] {};
    int contadorMes2025[12] {};

    string nombresMes[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio","Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};


    for(int i=0; i<cantRegVentas; i++)
    {
        ven = arcVen.leerRegistro(i);
        int mes = ven.getFechaDeVenta().getMes();
        int anio = ven.getFechaDeVenta().getAnio();

        if(mes >= 1 && mes <= 12)
        {
            if(anio == 2024) contadorMes2024[mes-1]++;
            else if(anio == 2025) contadorMes2025[mes-1]++;
        }
    }

    int mesMayor2024;
    int maxVentas2024;
    bool encontrado2024 = false;

    for(int i=0; i<12; i++)
    {
        if(contadorMes2024[i] > 0)
        {
            if(!encontrado2024 || contadorMes2024[i] > maxVentas2024)
            {
                maxVentas2024 = contadorMes2024[i];
                mesMayor2024 = i;
                encontrado2024 = true;
            }
        }
    }

    if(encontrado2024)
    {
        cout << "MES CON MAYOR VENTA EN 2024 FUE: " << nombresMes[mesMayor2024] << " CON " << maxVentas2024 << " VENTAS." << endl;
    }
    else
    {
        cout << "NO HUBO VENTAS EN 2024." << endl;
    }
    int mesMayor2025;
    int maxVentas2025;
    bool encontrado2025 = false;

    for(int i=0; i<12; i++)
    {
        if(contadorMes2025[i] > 0)
        {
            if(!encontrado2025 || contadorMes2025[i] > maxVentas2025)
            {
                maxVentas2025 = contadorMes2025[i];
                mesMayor2025 = i;
                encontrado2025 = true;
            }
        }
    }

    if(encontrado2025)
    {
        cout << "MES CON MAYOR VENTA EN 2025 FUE: " << nombresMes[mesMayor2025] << " CON " << maxVentas2025 << " VENTAS." << endl;
    }
    else
    {
        cout << "NO HUBO VENTAS EN 2025." << endl;
    }

    cout <<endl;
    cout <<"||=====================================================||"<<endl;
    cout <<"||                    FIN DEL REPORTE                  ||"<<endl;
    cout <<"||=====================================================||"<<endl;


}
void MayorFacturacion2024y2025()
{
    cout <<"||=====================================================||"<<endl;
    cout <<"||          MAYOR FACTURACION EN 2024 Y 2025           ||"<<endl;
    cout <<"||=====================================================||"<<endl;
    cout <<endl;

    ArchivoVentas arcVen("Ventas.dat");
    ArchivoDetalles arcDet("Detalles.dat");
    ArchivoProductos arcProd("Productos.dat");

    Ventas ven;
    Detalles det;
    Producto prod;

    int cantVentas = arcVen.contarRegistros();
    int cantDetalles = arcDet.contarRegistros();
    int cantProducto= arcProd.contarRegistros();

    float facturacion2024 = 0;
    float facturacion2025 = 0;


    for (int i = 0; i < cantVentas; i++)
    {
        ven = arcVen.leerRegistro(i);

        int anio = ven.getFechaDeVenta().getAnio();
        int idVenta = ven.getIdVenta();

        float totalVenta = 0;

        for (int j = 0; j < cantDetalles; j++)
        {
            det = arcDet.leerRegistro(j);

            if (det.getIdVenta() == idVenta)
            {
                int idProducto =det.getidProducto();

                for (int k=0; k<cantProducto; k++)
                {
                    prod= arcProd.leerRegistro(k);

                    totalVenta += det.getCantidad() * prod.getPrecioUnitario();
                    break;

                }


            }
        }

        if (anio == 2024)
        {
            facturacion2024 += totalVenta;
        }
        else if (anio == 2025)
        {
            facturacion2025 += totalVenta;
        }
    }

    cout << "FACTURACION TOTAL 2024: $" << facturacion2024 << endl;
    cout << "FACTURACION TOTAL 2025: $" << facturacion2025 << endl;



    cout <<endl;
    cout <<"||=====================================================||"<<endl;
    cout <<"||                    FIN DEL REPORTE                  ||"<<endl;
    cout <<"||=====================================================||"<<endl;

}
void ProductoMasVendidoEnLosUltimos2()
{

    cout <<"||=====================================================||"<<endl;
    cout <<"||    PRODUCTO MAS VENDIDOS EN LOS ULTIMOS 2 AÑOS      ||"<<endl;
    cout <<"||=====================================================||"<<endl;
    cout <<endl;


    ArchivoVentas arcVen("Ventas.dat");
    ArchivoDetalles arcDet("Detalles.dat");
    ArchivoProductos arcProd("Productos.dat");

    int cantVentas = arcVen.contarRegistros();
    int cantDetalles = arcDet.contarRegistros();
    int cantProductos = arcProd.contarRegistros();


    int *cantidadesPorProducto = new int[cantProductos + 1]();

    if (cantidadesPorProducto == nullptr)
    {
        cout << "NO SE PUDO ASIGNAR MEMORIA" << endl;
        return;
    }

    for (int i = 0; i < cantVentas; i++)
    {
        Ventas ven = arcVen.leerRegistro(i);
        int anio = ven.getFechaDeVenta().getAnio();

        if (anio == 2024 || anio == 2025)
        {
            int idVenta = ven.getIdVenta();

            for (int j = 0; j < cantDetalles; j++)
            {
                Detalles det = arcDet.leerRegistro(j);

                if (det.getIdVenta() == idVenta)
                {
                    int idProducto = det.getidProducto();
                    int cantidad = det.getCantidad();

                    if (idProducto >= 1 && idProducto <= cantProductos)
                    {
                        cantidadesPorProducto[idProducto] += cantidad;
                    }
                }
            }
        }
    }


    int idProductoMasVendido = -1;
    int maxCantidad = 0;

    for (int i = 1; i <= cantProductos; i++)
    {
        if (cantidadesPorProducto[i] > maxCantidad)
        {
            maxCantidad = cantidadesPorProducto[i];
            idProductoMasVendido = i;
        }
    }

    if (idProductoMasVendido != -1)
    {
        Producto prod = arcProd.leerRegistro(idProductoMasVendido - 1);
        cout << "ID PRODUCTO: " << idProductoMasVendido << endl;
        cout << "NOMBRE: " << prod.getNombre() << endl;
        cout << "CANTIDAD TOTAL VENDIDAS: " << maxCantidad << " UNIDADES" << endl;
    }
    else
    {
        cout << "NO SE ENCONTRARON VENTAS." << endl;
    }

    delete[] cantidadesPorProducto;

    cout <<endl;
    cout <<"||=====================================================||"<<endl;
    cout <<"||                    FIN DEL REPORTE                  ||"<<endl;
    cout <<"||=====================================================||"<<endl;



}
void PromedioProductosPorVenta()
{
    cout <<"||=====================================================||"<<endl;
    cout <<"||           PROMEDIO DE PRODUCTOS POR VENTA           ||"<<endl;
    cout <<"||=====================================================||"<<endl;
    cout <<endl;



    ArchivoVentas arcVen("Ventas.dat");
    ArchivoDetalles arcDet("Detalles.dat");

    Ventas ven;
    Detalles det;

    int cantVentas = arcVen.contarRegistros();
    int cantDetalles = arcDet.contarRegistros();

    if(cantVentas == 0)
    {
        cout << "NO HAY VENTAS REGISTRADAS." << endl;
        return;
    }

    int totalProducVendidos = 0;

    for(int i = 0; i < cantVentas; i++)
    {
        ven = arcVen.leerRegistro(i);
        int idVenta = ven.getIdVenta();
        int productosEnVenta = 0;

        for(int j = 0; j < cantDetalles; j++)
        {
            det = arcDet.leerRegistro(j);
            if(det.getIdVenta() == idVenta)
            {
                productosEnVenta += det.getCantidad();
            }
        }

        totalProducVendidos += productosEnVenta;
    }

    float promedio = (float)totalProducVendidos / cantVentas;

    cout<<"El PROMEDIO DE PRODUCTOS POR VENTA ES :"<< promedio <<endl;
    cout<<"TOTAL DE VENTAS "<<cantVentas<<endl;
    cout<<"TOTAL DE PRODUCTOS VENDIDO: "<<totalProducVendidos<<endl;



    cout <<endl;
    cout <<"||=====================================================||"<<endl;
    cout <<"||                    FIN DEL REPORTE                  ||"<<endl;
    cout <<"||=====================================================||"<<endl;


}
