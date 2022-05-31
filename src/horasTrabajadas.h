#ifndef HORASTRABAJADAS_H
#define HORASTRABAJADAS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class HorasTrabajadas {

    int idEmpleado;
    double montoPorHora;
    int horasLaboradas;
    
    public:
    HorasTrabajadas();
    HorasTrabajadas(int idEmpleadoNuevo, double montoPorHora,int horasLaboradas);
    ~HorasTrabajadas();

    int getIdEmpleado();
    double getMontoPorHora();
    int getHorasLaboradas();
   
    friend istream& operator >> (istream &o, HorasTrabajadas *horasTrabajadas);
    friend ostream& operator << (ostream &o, const HorasTrabajadas *horasTrabajadas);
};
#endif