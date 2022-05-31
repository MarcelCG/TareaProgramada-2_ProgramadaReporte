#include "empresa.h"

Empresa::Empresa() {
}

Empresa::~Empresa() {
    for (Empleado *empleado : this->empleados)
    {
        delete empleado;
    }
}

void Empresa::AgregarEmpleado(Empleado *nuevoEmpleado) {
    this->empleados.push_back(nuevoEmpleado);
}

void Empresa::AgregarNominas(vector<Nomina *> nominasNueva) {
    this->nominas = nominasNueva;
}

void Empresa::AgregarHorasTrabajadas(vector<HorasTrabajadas *> horasTrabajadasNuevo) {
     this->horasTrabajadas = horasTrabajadasNuevo;
}

 vector<Nomina *> Empresa::getNominas(){
     return this->nominas;
 }

vector<HorasTrabajadas *> Empresa::getHorasTrabajadas(){
     return this->horasTrabajadas;
}

vector<Empleado *> Empresa::getEmpleados(){
     return this->empleados;
}

ostream& operator << (ostream &o, const Empresa *empresa)
{
    double subTotal = 0;
    double impuestosARetener = 0;

    for (Empleado *empleado : empresa->empleados)
    {   
        //Calcular el nombre del supervisor
        empleado->setNombreSupervisor(empleado->getIdSupervisor(),empresa->empleados);

        //Calcular el salario
        empleado->setSalarioNeto(empresa->nominas,empresa->horasTrabajadas);
        subTotal += empleado->getSalarioNeto();
        impuestosARetener += empleado->getImpuestosARetener();
        o << empleado << endl;
    }
     o << "Subtotal:" << setprecision(15) << subTotal << endl;
     o << "Impuestos a retener:" << impuestosARetener << endl;
     o << "Total:" << setprecision(15) << subTotal+impuestosARetener << endl;
    return o;
}

istream& operator >> (istream &i, Empresa *empresa)
{
    string linea;

    while (std::getline(i, linea)) {
        // Mientras el getline obtenga alguna línea,
        // procesar línea

        std::istringstream streamLinea(linea);

        Empleado *nuevoEmpleado = new Empleado();
        streamLinea >> nuevoEmpleado;

        empresa->AgregarEmpleado(nuevoEmpleado);
    }
    return i;
}



