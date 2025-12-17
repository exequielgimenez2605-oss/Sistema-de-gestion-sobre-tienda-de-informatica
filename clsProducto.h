#ifndef CLSPRODUCTO_H_INCLUDED
#define CLSPRODUCTO_H_INCLUDED

class Producto{
private:
    int  _idProducto;
    char _nombre[50];
    char _marca[50];
    int  _tipoDeEquipo;
    char _descripcion[120];
    int  _stock;
    float _precioUnitario;
    bool _estado;
public:
    ///CONSTRUTOR
    Producto(int idProducto=0, const char *nombre="s/n", const char *marca="s/n",int tipoDeEquipo=0, const char *descripcion="s/n",int stock=0, float precioUnitario=0);

    ///SETTERS
    void setIdProducto(int);
    void setNombre(const char*);
    void setMarca(const char*);
    void setTipoDeEquipo(int);
    void setDescripcion(const char *);
    void setStock(int);
    void setPrecioUnitario(float);
    void setEstado(bool);
    ///GETTERS
    int getIdProducto();
    const char *getNombre();
    const char *getMarca();
    int getTipoDeEquipo();
    const char *getDescripcion();
    int getStock();
    float getPrecioUnitario();
    bool getEstado();
    ///OTROS METODOS
    void cargarProducto();
    void mostrarProducto();
};



#endif // CLSPRODUCTO_H_INCLUDED
