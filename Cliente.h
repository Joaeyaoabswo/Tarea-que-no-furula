#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <iostream>
 using namespace std;
class cliente{
    private:
    int IdCliente;
    string nombre;
    string apellido;
    public:

        cliente(int ID,string nom,string ape);
        int getIdcliente();
        string getNombre();
        string getApellido();

};


#endif // CLIENTE_H_INCLUDED
