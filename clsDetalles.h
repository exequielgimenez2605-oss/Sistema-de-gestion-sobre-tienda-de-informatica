#ifndef CLSDETALLES_H_INCLUDED
#define CLSDETALLES_H_INCLUDED

class Detalles{
    private:
        int _idDetalle;
        int _idVentas;
        int _idProducto;
        int _cantidad;
        bool _estado;

    public:
///SETTERS
        void setIdDetalle(int);
        void setIdVenta(int);
        void setIdProducto(int);
        void setCantida(int);
        void setEstado(bool);
///GETTERS
        int getIdDetalle();
        int getIdVenta();
        int getidProducto();
        int getCantidad();
        bool getEstado();
///OTROS METODOS
        void cargar();
        void mostrar();
};


#endif // CLSDETALLES_H_INCLUDED
