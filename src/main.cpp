#include <sstream>
#include <iostream>
#include <string>
#include <fstream>

#include "empresa.h"
#include "empleado.h"
#include "nomina.h"
#include "controladorNomina.h"
#include "controladorProfesionalHoras.h"

using namespace std;

int main()
{
    Empresa *empresa = new Empresa();
    //Cargar los empleados en la empresa
    ifstream reporteEmpresa("personas.txt", std::ifstream::in);
    
    if (!reporteEmpresa.is_open())
    {
        std::cerr << "Error abriendo archivo personas.txt" << std::endl;
        return -1;
    }

    reporteEmpresa >> empresa;
    reporteEmpresa.close();

    //Cargar la nomina en la empresa
    ControladorNomina *controladorNomina = new ControladorNomina();
    ifstream reporteNomina("nomina.txt", std::ifstream::in);

    if (!reporteNomina.is_open())
    {
        std::cerr << "Error abriendo archivo nomina.txt" << std::endl;
        return -1;
    }

    reporteNomina >> controladorNomina;
    //Asignar la lista de la nomida a la empresa
    empresa->AgregarNominas(controladorNomina->getNominas());
    reporteNomina.close();

    delete controladorNomina;

  //Cargar tabla de horas trabajadas
  ControladorProfesionalHoras *controladorProfesionalHoras = new ControladorProfesionalHoras();
  ifstream reporteHorasTrabajadas("horastrabajadas.txt", std::ifstream::in);
    
    if (!reporteHorasTrabajadas.is_open())
    {
        std::cerr << "Error abriendo archivo horastrabajadas.txt" << std::endl;
        return -1;
    }

    reporteHorasTrabajadas >> controladorProfesionalHoras;
    //Asignar la lista de la horas trabajadas a la empresa
    empresa->AgregarHorasTrabajadas(controladorProfesionalHoras->getHorasTrabajadas());

    cout << "Mi empresa: " << empresa;
    delete controladorProfesionalHoras;
    reporteHorasTrabajadas.close();

    //Crear archivo csv
    ofstream reporte("reporteEmpresa.csv", std::ifstream::out);

    if (!reporte.is_open())
    {
        std::cerr << "Error abriendo archivo reporteEmpresa.txt" << std::endl;
        return -1;
    }
    reporte << empresa;
    reporte.close();
    delete empresa; 
}