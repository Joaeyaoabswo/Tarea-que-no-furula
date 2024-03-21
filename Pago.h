#ifndef PAGO_H_INCLUDED
#define PAGO_H_INCLUDED
#include "Fecha.h"
class pago{
    private:
    fecha *fechaPago;
    float montoPago;
    public:
        *pago(fecha *FP,float MP){
            this->fechaPago=FP;
            this->montoPago=MP;
        }
        fecha *getFechaPago(){
            return this->fechaPago;
        }

        float getMontoPago(){
        return this->montoPago;
        }
};


#endif // PAGO_H_INCLUDED
