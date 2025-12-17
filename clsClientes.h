#ifndef CLSCLIENTES_H_INCLUDED
#define CLSCLIENTES_H_INCLUDED
#include "clsfecha.h"

class Clientes{
private:
    char _cuit[30];
    char _nombre[30];
    char _apellido[30];
    int  _telefono;
    char _email[50];
    char _direccion[30];
    int  _tipoCliente;
    Fecha _fechaIngreso;
    bool _estado;
public:
    /// CONSTRUTOR

    Clientes(const char *cuit="s/n", const char *nombre="s/n", const char *apellido="s/n", int telefono=0,const char *email="s/n", const char *direccion="s/n", int tipoCliente=0, Fecha fecha=Fecha(1/1/2025));

    /// SETTERS
    void setCuit(const char*);
    void setNombre(const char*);
    void setApellido(const char*);
    void setTelefono(int);
    void setEmail(const char*);
    void setDireccion(const char*);
    void setTipoCliente(int);
    void setFechaIngreso(Fecha);
    void setEstado(bool);

    /// GETTERS
    const char *getCuit();
    const char *getNombre();
    const char *getApellido();
    int getTelefono();
    const char *getEmail();
    const char *getDireccion();
    int getTipoCliente();
    Fecha getFechaIngreso();
    bool getEstado();

     ///OTROS METODOS
    void Cargar();
    void Mostrar();
};

#endif // CLSCLIENTES_H_INCLUDED
