#include "horasTrabajadas.h"

HorasTrabajadas::HorasTrabajadas() {
}

HorasTrabajadas::HorasTrabajadas(int idEmpleadoNuevo, double montoPorHoraNuevo,int horasLaboradasNuevo) {
    this->idEmpleado = idEmpleadoNuevo;
    this->montoPorHora = montoPorHoraNuevo;
    this->horasLaboradas = horasLaboradasNuevo;
}

HorasTrabajadas::~HorasTrabajadas() {
}

int HorasTrabajadas::getIdEmpleado(){
    return this->idEmpleado;
}
double HorasTrabajadas::getMontoPorHora(){
     return this->montoPorHora;
}
int HorasTrabajadas::getHorasLaboradas(){
     return this->horasLaboradas;
}

ostream& operator << (ostream &o, const HorasTrabajadas *horasTrabajadas)
{
    o << horasTrabajadas->idEmpleado << "," << horasTrabajadas->montoPorHora << "," << horasTrabajadas->horasLaboradas;

    return o;
}

istream& operator >> (istream &i, HorasTrabajadas *horasTrabajadas)
{
     i >> horasTrabajadas->idEmpleado >> horasTrabajadas->montoPorHora >> horasTrabajadas->horasLaboradas;
    return i;
}