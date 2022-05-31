#include "nomina.h"

using namespace std;

Nomina::Nomina() {

}

Nomina::Nomina(int idEmpleadoNuevo, double pagoMensualBrutoNuevo) {
    this->idEmpleado = idEmpleadoNuevo;
    this->pagoMensualBruto = pagoMensualBrutoNuevo;
}

Nomina::~Nomina() {
}

int Nomina::getIdEmpleado(){
    return this->idEmpleado;
}

double Nomina::getPagoMensualBruto(){
    return this->pagoMensualBruto;
}

ostream& operator << (ostream &o, const Nomina *nomina)
{
    o << nomina->idEmpleado << "," << nomina->pagoMensualBruto;
    return o;
}

istream& operator >> (istream &i, Nomina *nomina)
{
     i >> nomina->idEmpleado >> nomina->pagoMensualBruto;
    return i;
}