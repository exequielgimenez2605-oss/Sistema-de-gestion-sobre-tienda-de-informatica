#ifndef CLSVENTAS_H_INCLUDED
#define CLSVENTAS_H_INCLUDED
#include "clsFecha.h"

class Ventas{
    private:
        int _idVenta;
        char _cuit[30];
        Fecha _fechaDeVenta;
        bool _estado;
    public:
        ///CONSTRUCTOR
        Ventas(int idVenta = 0, const char *cuit = "s/c", Fecha fecha = Fecha(1,1,1800));
        ///SETTERS
        void setIdVenta(int);
        void setCuit(const char *);
        void setFechaDeVenta(Fecha);
        void setEstado(bool);
        ///GETTERS
        int getIdVenta();
        const char *getCuit();
        Fecha getFechaDeVenta();
        bool getEstado();
        ///OTROS METODOS
        void Cargar();
        void Mostrar();
};

#endif // CLSVENTAS_H_INCLUDED


