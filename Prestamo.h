#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED
#define VAR 50
class prestamo{
   private:
       int numeroPrestamo;
       cliente *Cliente;
       fecha  *fechaAprobacion;
       float MontoAprobado;
       pago *lstPago[VAR];
       float saldoPendiente;
       int  contadorPago;
   public:
       prestamo(int id){
       this->numeroPrestamo=id;
       this->saldoPendiente=0;
       this->contadorPago=0;
       this->MontoAprobado=0;
       this->numeroPrestamo=0;
       }
       int getNumPrestamo(){
       return this->numeroPrestamo;
       }
       void setNumeroPrestamo(int nump){
         this->numeroPrestamo=nump;
       }
       cliente *getCliente(){
        return this->Cliente;
       }
       void setCliente(cliente *clik){
       this->Cliente=clik;
       }
       void setFecha(fecha *feA){
       this->fechaAprobacion=feA;
       }
       fecha *getfechaAprobacion(){
        return this->fechaAprobacion;
       }
       void setMontoAprobado(float Mp){
       this->MontoAprobado=Mp;
       this->saldoPendiente=Mp;
       }
       float getMontoAprobado(){
       return this->MontoAprobado;
       }
       bool hacerPagos(pago *pg){
           bool retorno=false;
            if(this->contadorPago<VAR){
               this->lstPago[this->contadorPago]=pg;
                this->contadorPago++;
                this->saldoPendiente -= pg->getMontoPago();
                retorno=true;
            }
            return retorno;
       }
       pago **getlstPago(){
      return this->lstPago;
       }

       float getsaldoPendiente(){
       return this->saldoPendiente;
       }
       int getContadorPagos(){
          return this->contadorPago;
       }



};


#endif // PRESTAMO_H_INCLUDED
