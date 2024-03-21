#include <iostream>
#include "Cliente.h"
#include "Fecha.h"
#include "Pago.h"
#include "Prestamo.h"
#define Var 50
using namespace std;
//jose gilber
int menu()
{
int op;
    cout << "MENU DE OPCIONES\n";
    cout << "1. Agregar Cliente a la lista\n";
    cout << "2. Agregar Agregar prestamo a la lista\n";
    cout << "3. Hacer pago de prestamo\n";
    cout << "4. Mostrar lista de cliente\n";
    cout << "5. Mostrar lista de prestamos\n";
    cout << "6. Mostrar detalle del prestamo\n";
    cout << "7. Salir\n";
    cout << "Digite la opcion: ";
    cin >> op;
    return op;
}
cliente *agregarCliente(){
cliente *Cliente;
int id;
string nom,ape;
    cout<<"Escriba en este orden el ID, nombre, Apellido del cliente para poder agregralo"<<endl;
    cin>>id;
    cin>>nom;
    cin>>ape;
    Cliente= new cliente(id,nom,ape);
    return Cliente;
}

cliente *buscarCliente(cliente *lstC[],int contC, int id){
    bool encontrado=false;
    int contador=0;
    cliente *cli=NULL;
    while(contador < contC && !encontrado){
        if(lstC[contador]->getIdcliente()==id){
            encontrado=true;
            cli=lstC[contador];
        }
        else{
            contador++;
        }
    }
    return cli;
}

prestamo *agregarPrestamo(cliente *lstcliente[],int cont){
    int idclie,nump,d,m,a;
    prestamo *pres=NULL;
    float monA;
    cout<<"digite el id del cliente\n";
    cin>>idclie;
    cliente *clik=buscarCliente(lstcliente,cont,idclie);
    if(clik){
        ///se encontro
        cout<<"digite el numero del prestamo"<<endl;
        cin>>nump;
        cout<<"digite el monto aprobado\n";
        cin>>monA;
        cout<<"escriba la fecha del prestamo en formato dia,mes y anyo\n";
        cin>>d;
        cin>>m;
        cin>>a;
        fecha *feP=new fecha(d,m,a);
        pres= new prestamo(nump);
        pres->setCliente(clik);
        pres->setMontoAprobado(monA);
        pres->setFecha(feP);
    }
    return pres;


}

prestamo *buscarPrestamo(prestamo *lstP[],int contP, int nup){
    bool encontrado=false;
    int contador=0;
    prestamo *pe=NULL;
    while(contador < contP && !encontrado){
        if(lstP[contador]->getNumPrestamo()==nup){
            encontrado=true;
            pe=lstP[contador];
        }
        else{
            contador++;
        }
    }
    return pe;
}

void mostrarCliente(cliente *lst[],int cont){
   if(cont == 0){
    cout<<"la lista esta llena\n";
   }
   else{
    cout<<"ID\T.nombre\tApellido\n";
    for(int i=0;i <cont;i++){
        cliente *cli=lst[i];
        cout<<cli->getIdcliente()<<"\t";
        cout<<cli->getNombre()<<"\t";
        cout<<cli->getApellido()<<"\t";
    }
   }
}

void mostrarPrestamo(prestamo *lst[],int cont){
   if(cont == 0){
    cout<<"la lista esta llena\n";
   }
   else{
    cout<<"ID\T.cliente\tMopnto\n";
    for(int i=0;i <cont;i++){
        prestamo *pre=lst[i];
        cout<<pre->getNumPrestamo()<<"\t";
        cout<< pre->getCliente()->getNombre() <<"  "<< pre->getCliente()->getApellido()<<"\t";
        cout<<pre->getMontoAprobado()<<"\t";
    }
   }
}



int main(){
int opc;
cliente *lstCli[Var];
prestamo *lstPrestamo[Var];
cliente *clik=NULL;
prestamo *pres=NULL;
int contCli=0,contPr=0,IdClie,IdPres,nump,dp,mp,ap;
float montop;
do{
        system("cls");
         opc=menu();
 switch(opc){
    case 1:
      ///agregar cliente
       if (contCli < VAR){
                    lstCli[contCli] = agregarCliente();
                    contCli++;
                    cout << "El cliente se agrego con exito\n";
                }
                else{
                    cout << "La lista de cliente esta llena\n";
                }
      break;
     case 2:
      //agregar prestamo
      {
      prestamo *prest=agregarPrestamo(lstCli,contCli);
      if(prest){
        if (contPr < VAR){
                    lstPrestamo[contPr] = pres;
                    contCli++;
                    cout << "El cliente se agrego con exito\n";
                }
                else{
                    cout << "La lista de prestamos esta llena o  vacia\n";
                }
      }
      else{
        cout<<"no se encontro el cliente asi que no se registro el prestamp";
        }
      }
      break;
     case 3:
      //pago de prestamo
       {
           cout<<"digite el numero de prestamo\n";
           cin>>nump;
      prestamo *prest=buscarPrestamo(lstPrestamo,contPr,nump);
      if(prest){
        if (contPr < VAR){
                ///se encontro
                cout<<"Digite el monto";
                cin>>montop;
                 cout<<"Digite el dia de pago";
                cin>>dp;
                 cout<<"Digite el mes de pago";
                cin>>mp;
                 cout<<"Digite el anyo de pago";
                cin>>ap;
                fecha *fp= new fecha(dp,mp,ap);
                pago *pg=new pago(fp,montop);
                prest->hacerPagos(pg);
                cout<<"el pago se realizo con existo\n";
                }
                else{
                    cout << "La lista de prestamos esta llena o  vacia\n";
                }
      }
      else{
        cout<<"no se encontro el cliente asi que no se registro el prestamp";
        }
      }
      break;
     case 4:
      //mostrar cliente
      mostrarCliente(lstCli,contCli);
      break;
     case 5:
      //mostrar prestamo
      mostrarPrestamo(lstPrestamo,contPr);
      break;
     case 6:
      //detalle del prestamo
          {
           cout<<"digite el numero de prestamo\n";
           cin>>nump;
      prestamo *prest=buscarPrestamo(lstPrestamo,contPr,nump);
      if(prest){
        if (contPr < VAR){
                ///se encontro
                cout<<"mostrando los detalles del prestamo\n";
                cout<<"el numero del prestamo es: "<< prest->getCliente()->getNombre() <<" "<< prest->getCliente()->getApellido() <<endl;
                cout<<"monto aprobado del prestamo "<< prest->getMontoAprobado()<<endl;
                 cout<<"fecha del prestamo ";
                 prest->getfechaAprobacion()->mostrarFecha();
                if(prest->getContadorPagos()==0){
                    cout<<"no se hay ningun pago \n";
                }
                else{
                    cout<<"LISTA DE PAGO REALIZADOS\n";
                    cout<<"Fecha\tMonto\n";
                    pago **lstP=prest->getlstPago();
                    for(int i=0; i<prest->getContadorPagos();i++){
                        pago *pg=lstP[i];
                        pg->getFechaPago()->mostrarFecha();
                        cout<<"\t";
                        cout<<pg->getMontoPago()<<endl;
                    }
                }
        }
                else{
                    cout << "La lista de prestamos esta llena o  vacia\n";
                }
      }
      else{
        cout<<"no se encontro el cliente asi que no se registro el prestamp";
        }
      }
      break;
     case 7:
      ///Salir
        cout << "Saliendo del Programa...\n";
                break;
      break;
    default:
      cout << "Error, opcion no esta definida";
    break;

 }
system("pause");
    }while(opc!=7);
}
