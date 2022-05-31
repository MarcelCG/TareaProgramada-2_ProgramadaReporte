#include "controladorProfesionalHoras.h"

ControladorProfesionalHoras::ControladorProfesionalHoras() {

}

ControladorProfesionalHoras::ControladorProfesionalHoras(vector<HorasTrabajadas *> horasTrabajadasNuevo) {
    this->horasTrabajadas = horasTrabajadasNuevo;
   
}

ControladorProfesionalHoras::~ControladorProfesionalHoras() {
    
}


vector<HorasTrabajadas *> ControladorProfesionalHoras::getHorasTrabajadas(){
    return this->horasTrabajadas;
}

void ControladorProfesionalHoras::AgregarHorasTrabajadas(HorasTrabajadas *horasTrabajadas) {
    this->horasTrabajadas.push_back(horasTrabajadas);
}


istream& operator >> (istream &i, ControladorProfesionalHoras *controladorProfesionalHoras)
{
    string linea;

    while (std::getline(i, linea)) {
        // Mientras el getline obtenga alguna línea,
        // procesar línea

        std::istringstream streamLinea(linea);

        HorasTrabajadas *nuevaHorasTrabajadas = new HorasTrabajadas();
        streamLinea >> nuevaHorasTrabajadas;
        controladorProfesionalHoras->AgregarHorasTrabajadas(nuevaHorasTrabajadas);
    }

    return i;
}