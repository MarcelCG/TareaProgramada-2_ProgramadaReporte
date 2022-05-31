#ifndef EMPRESA_H
#define EMPRESA_H

#include "horasTrabajadas.h"
#include "nomina.h"
#include "empleado.h"
#include "empresa.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip> 

using namespace std;

class Empresa {
    vector<Empleado *> empleados;
    vector<Nomina *> nominas;
    vector<HorasTrabajadas *> horasTrabajadas;
//
    public:
    Empresa();
    ~Empresa();

    void AgregarEmpleado(Empleado *nuevoEmpleado);
    void AgregarNominas(vector<Nomina *> nominas);
    void AgregarHorasTrabajadas(vector<HorasTrabajadas *> horasTrabajadasNuevo);
    vector<Empleado *> getEmpleados();
    vector<Nomina *> getNominas();
    vector<HorasTrabajadas *> getHorasTrabajadas();
    friend istream& operator >> (istream &o, Empresa *empresa);
    friend ostream& operator << (ostream &o, const Empresa *empresa);
};
#endif