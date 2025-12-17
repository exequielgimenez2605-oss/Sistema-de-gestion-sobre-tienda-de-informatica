#include <iostream>
#include "clsFecha.h"

using namespace std;

///CONSTRUCTOR
Fecha::Fecha(int d, int m, int a)
{

    if (esValida (d,m,a))
    {
        dia = d;
        mes = m;
        anio = a;
    }
    else
    {
        dia=1;
        mes=1;
        anio=2025;
    }
}
///SETTERS
void Fecha::setDia(int d)
{
    if (d>= 1 && d <=diasDelMes(mes,anio))
        dia=d;
}
void Fecha::setMes(int m)
{
    if (m >= 1 && m <=12)
    {
        mes=m;

        if(dia > diasDelMes(mes,anio))
    {
        dia=diasDelMes(mes,anio);

        }

    }
}
void Fecha::setAnio(int a)
{
    if(a >= 2020 && a <= 2030)
    {
        anio=a;

        if(dia > diasDelMes(mes,anio))
    {
        dia=diasDelMes(mes,anio);

        }
    }
}
///GETTERS
int Fecha::getDia()
{
    return dia;
}
int Fecha::getMes()
{
    return mes;
}
int Fecha::getAnio()
{
    return anio;
}
///OTROS METODOS

bool Fecha::esBisiesto(int a){

return (a % 4 ==0 && a % 100 !=0)||(a % 400 ==0);

}

int Fecha::diasDelMes(int m, int a){

int dias[]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

if(m < 1 || m > 12){ return 0;}

if (m == 2 && esBisiesto(a)){

    return 29;
}
    return dias[m];

}

bool Fecha::esValida(int d, int m, int a){

    if(a < 2020 || a >2030){

        return false;
    }

    if(m < 1 || m > 12 ){

        return false;
    }

    if(d < 1 || d >diasDelMes(m,a )){

        return false;
    }

    return true;

}




void Fecha::Cargar()
{
    int d;
    int m;
    int a;
    bool fechaValida=false;

    while (!fechaValida){
    cout <<"DIA: ";
    cin >> d;
    cout <<"MES: ";
    cin >> m;
    cout <<"AÑO: ";
    cin >> a;

    if (esValida( d, m, a)){

        dia=d;
        mes=m;
        anio=a;

        fechaValida = true;
    }else{

        cout <<"FECHA INVALIDA"<<endl;
        cout <<"INGRESE UNA FECHA VALIDA NUEVAMENTE "<<endl;
        cout << "---------------------------------------------------"<<endl;
        }
    }
}
void Fecha::Mostrar()
{
    cout <<dia<<"/"<<mes<<"/"<<anio<<endl;
}
