#include "empleado.h"

Empleado::Empleado() {
}

Empleado::Empleado(int idEmpleadoNuevo, string nombreNuevo, string apellidoNuevo, string emailNuevo, int tipoEmpleadoNuevo, int idSupervisorNuevo) {
    this->idEmpleado = idEmpleadoNuevo;
    this->nombre = nombreNuevo;
    this->apellido = apellidoNuevo;
    this->email = emailNuevo;
    this->tipoEmpleado = tipoEmpleadoNuevo;
    this->idSupervisor = idSupervisorNuevo;
}

Empleado::~Empleado() {  
}

void Empleado::setNombreSupervisor(int idSupervisor,vector<Empleado *> empleados){
    for (Empleado *empleado : empleados)
    {
        if(empleado->getIdEmpleado() == idSupervisor){
             this->nombreSupervisor = empleado->getNombre()+" "+empleado->getApellido();
             break;
        }
    }
    
}
void Empleado::setSalarioNeto(vector<Nomina *> nominas,vector<HorasTrabajadas *> horasTrabajadas){
     //Calcular el salario
        if(this->getTipoEmpleado()==1){//Empleado nomina
            this->setSalarioNetoNomina(nominas);
            //impuestosARetener += this->getImpuestosARetener();
        }else{//Empleado por horas
             this->setSalarioNetoHoras(horasTrabajadas);
        }
}
void Empleado::setSalarioNetoNomina(vector<Nomina *> nominas){
     for (Nomina *nomina : nominas)
    {
        if(nomina->getIdEmpleado() == this->idEmpleado){
             this->impuestosARetener = nomina->getPagoMensualBruto()* 0.07;
             this->salarioNeto = nomina->getPagoMensualBruto() - impuestosARetener;
             break;
        }
    }
}
void Empleado::setSalarioNetoHoras(vector<HorasTrabajadas *> horasTrabajadas){
     for (HorasTrabajadas *horas : horasTrabajadas)
    {
        if(horas->getIdEmpleado() == this->idEmpleado){
             this->salarioNeto = (horas->getMontoPorHora() * horas->getHorasLaboradas());
             break;
        }
    }
}
string Empleado::getNombreSupervisor(){
    return this-> nombreSupervisor;
}

int Empleado::getIdEmpleado(){
    return this->idEmpleado;
}
int Empleado::getIdSupervisor(){
    return this->idSupervisor;
}
string Empleado::getNombre(){
    return this->nombre;
}
string Empleado::getApellido(){
    return this->apellido;
}
int Empleado::getTipoEmpleado(){
    return this->tipoEmpleado;
}
double Empleado::getSalarioNeto(){
    return this->salarioNeto;
}
double Empleado::getImpuestosARetener(){
    return this->impuestosARetener;
}

ostream& operator << (ostream &o, const Empleado *empleado)
{
    o << empleado->idEmpleado << "," << empleado->nombre+" "+empleado->apellido << "," << empleado->nombreSupervisor << "," << empleado->salarioNeto << endl;

    return o;
}

istream& operator >> (istream &i, Empleado *empleado)
{
    i >> empleado->idEmpleado >> empleado->nombre >> empleado->apellido >> empleado->email >> empleado->tipoEmpleado >> empleado->idSupervisor;
    return i;
}