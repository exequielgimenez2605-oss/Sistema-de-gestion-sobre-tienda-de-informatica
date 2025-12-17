#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{
private:
    int dia;
    int mes;
    int anio;

    bool esValida(int d, int m, int a);
    bool esBisiesto(int a);
    int diasDelMes(int m,int a);


public:
    ///CONSTRUCTOR
    Fecha(int d=1, int m=1, int a=2025);
    ///SETTERS
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    ///GETTERS
    int getDia();
    int getMes();
    int getAnio();
    ///OTROS METODOS
    void Cargar();
    void Mostrar();
};
#endif // CLSFECHA_H_INCLUDED
