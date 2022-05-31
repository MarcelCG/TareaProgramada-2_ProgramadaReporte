#include "controladorNomina.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

ControladorNomina::ControladorNomina() {

}

ControladorNomina::ControladorNomina(vector<Nomina *> nominasNuevo) {
    this->nominas = nominasNuevo;
}

ControladorNomina::~ControladorNomina() {
    
}

vector<Nomina *>  ControladorNomina::getNominas(){
    return this->nominas;
}

void ControladorNomina::AgregarNominas(Nomina *nominaNueva) {
    this->nominas.push_back(nominaNueva);
}


istream& operator >> (istream &i, ControladorNomina *controladorNomina)
{
    string linea;

    while (std::getline(i, linea)) {
        // Mientras el getline obtenga alguna línea,
        // procesar línea

        std::istringstream streamLinea(linea);

        Nomina *nuevaNomina = new Nomina();
        streamLinea >> nuevaNomina;
        controladorNomina->AgregarNominas(nuevaNomina);
    }

    return i;
}