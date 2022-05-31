#ifndef CONTROLADORPROFESIONALHORAS_H
#define CONTROLADORPROFESIONALHORAS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "HorasTrabajadas.h"

using namespace std;

class ControladorProfesionalHoras {

    vector<HorasTrabajadas *> horasTrabajadas;

    public:

    ControladorProfesionalHoras();

    ControladorProfesionalHoras(vector<HorasTrabajadas *> horasTrabajadas);

    ~ControladorProfesionalHoras();
    
    void AgregarHorasTrabajadas(HorasTrabajadas *horasTrabajadas);
    vector<HorasTrabajadas *> getHorasTrabajadas();

    friend istream& operator >> (istream &o, ControladorProfesionalHoras *controladorProfesionalHoras);
    friend ostream& operator << (ostream &o, const ControladorProfesionalHoras *controladorProfesionalHoras);
};

#endif