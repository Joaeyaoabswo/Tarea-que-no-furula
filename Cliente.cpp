#include <iostream>
#include "Cliente.h"
using namespace std;

int main(){
  cliente::cliente(int ID,string nom,string ape){
            IdCliente=ID;
            nombre=nom;
            apellido=ape;
  }
      int  cliente::getIdcliente(){
         return IdCliente;
        }
       string cliente::getNombre(){
        return nombre;
        }
        string cliente::getApellido(){
        return apellido;
        }
return 0;
}
