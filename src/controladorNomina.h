#ifndef CONTROLADORNOMINA_H
#define CONTROLADORNOMINA_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "nomina.h"

using namespace std;

class ControladorNomina {

    vector<Nomina *> nominas;
   
    public:

    ControladorNomina();

    ControladorNomina(vector<Nomina *> nominas);

    ~ControladorNomina();
    
    void AgregarNominas(Nomina *nominaNueva);
    vector<Nomina *> getNominas();

    friend istream& operator >> (istream &o, ControladorNomina *controladorNomina);
    //friend ostream& operator << (ostream &o, const ControladorNomina *controladorNomina);
};

#endif