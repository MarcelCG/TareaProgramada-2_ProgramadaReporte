#ifndef NOMINA_H
#define NOMINA_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Nomina {

    int idEmpleado;
    double pagoMensualBruto;
    
    public:
    Nomina();
    Nomina(int idEmpleadoNuevo, double pagoMensualBrutoNuevo);
    ~Nomina();
    int getIdEmpleado();
    double getPagoMensualBruto();
    friend istream& operator >> (istream &o, Nomina *nomina);
    friend ostream& operator << (ostream &o, const Nomina *nomina);
};
#endif