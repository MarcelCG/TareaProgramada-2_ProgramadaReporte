#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <iostream>
#include <vector>
#include "nomina.h"
#include "horasTrabajadas.h"

using namespace std;

class Empleado {
    int idEmpleado;
    string nombre;
    string apellido;
    string email;
    int tipoEmpleado;
    int idSupervisor;
    double impuestosARetener;
    void setSalarioNetoNomina(vector<Nomina *> nominas);
    void setSalarioNetoHoras(vector<HorasTrabajadas *> horasTrabajadas);
    //
    public:
    string nombreSupervisor;
    double salarioNeto;
    Empleado();
    Empleado(int idEmpleadoNuevo, string nombreNuevo, string apellidoNuevo, string emailNuevo, int tipoEmpleadoNuevo, int idSupervisorNuevo);
    ~Empleado();

    void setNombreSupervisor(int idSupervisor,vector<Empleado *> empleados);
    void setSalarioNeto(vector<Nomina *> nominas,vector<HorasTrabajadas *> horasTrabajadas);
    
    int getIdEmpleado();
    int getIdSupervisor();
    string getNombre();
    string getApellido();
    string getNombreSupervisor();
    int getTipoEmpleado();
    double getSalarioNeto();
    double getImpuestosARetener();

    friend istream& operator >> (istream &o, Empleado *empleado);
    friend ostream& operator << (ostream &o, const Empleado *empleado);
};
#endif