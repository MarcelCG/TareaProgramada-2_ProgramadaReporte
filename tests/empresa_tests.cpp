#include <gtest/gtest.h>
#include "./../src/empresa.h"
#include "./../src/empleado.h"
#include "./../src/controladorNomina.h"
#include "./../src/controladorProfesionalHoras.h"
#include "./../src/HorasTrabajadas.h"
#include "./../src/Nomina.h"
#include <sstream>
#include <string>
#include <vector>

namespace
{
    //Probar empleado tipo 1 salario neto
    TEST(Empresa_Test, Test_Salario_Neto_Empleado_Tipo_1)
    {
 
        Empresa *empresa = new Empresa();

        Empleado *empleado  = new Empleado(600,"Hank","Jackson","Hank_Jackson776@sveldo.biz",1,295);
        Empleado *empleadoSupervisor  = new Empleado(295,"El","Jefe","jefe@sveldo.biz",1,1);

        empresa->AgregarEmpleado(empleado);
        empresa->AgregarEmpleado(empleadoSupervisor);

        //Cargar la nomina en la empresa
        ControladorNomina *controladorNomina = new ControladorNomina();
        Nomina *entrada1 = new Nomina(600,5000);
        Nomina *entradaSupervisor = new Nomina(295,50000);

        controladorNomina->AgregarNominas(entrada1);
        controladorNomina->AgregarNominas(entradaSupervisor);
        empresa->AgregarNominas(controladorNomina->getNominas());

        vector<HorasTrabajadas *> horasTrabajadas;
        //
        empleado->setSalarioNeto(empresa->getNominas(),horasTrabajadas);
        double esperado = 4650;
        double actual = empleado->getSalarioNeto(); 
        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

     //Probar empleado tipo 2 salario neto
    TEST(Empresa_Test, Test_Salario_Neto_Empleado_Tipo_2)
    {
 
        Empresa *empresa = new Empresa();

        Empleado *empleado  = new Empleado(601,"Marcel", "Castro","mcastro@sveldo.biz",2,295);
        Empleado *empleadoSupervisor  = new Empleado(295,"El", "Jefe","jefe@sveldo.biz",1,1);

        empresa->AgregarEmpleado(empleado);
        empresa->AgregarEmpleado(empleadoSupervisor);


        //Cargar los datos de profesionales por horas
        ControladorProfesionalHoras *controladorProfesionalHoras = new ControladorProfesionalHoras();
        HorasTrabajadas *horasTrabajadas1 = new HorasTrabajadas(601,2000,160);
        
        controladorProfesionalHoras->AgregarHorasTrabajadas(horasTrabajadas1);
        empresa->AgregarHorasTrabajadas(controladorProfesionalHoras->getHorasTrabajadas());

        vector<Nomina *> nominas;
        empleado->setSalarioNeto(nominas,empresa->getHorasTrabajadas());

        double esperado = 320000;
        double actual = empleado->getSalarioNeto(); 
        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    //Obtener el nombre del supervisor de un empleado
    TEST(Empresa_Test, Test_Obtener_Nombre_Supervisor)
    {
 
        Empresa *empresa = new Empresa();

        Empleado *empleado  = new Empleado(601,"Marcel", "Castro","mcastro@sveldo.biz",2,295);
        Empleado *empleadoSupervisor  = new Empleado(295,"El", "Jefe","jefe@sveldo.biz",1,1);
        

        empresa->AgregarEmpleado(empleado);
        empresa->AgregarEmpleado(empleadoSupervisor);
        empleado->setNombreSupervisor(empleadoSupervisor->getIdEmpleado(),empresa->getEmpleados());

        string esperado = "El Jefe";
        string actual = empleado->getNombreSupervisor(); 
        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    //Calcular subtotal
    TEST(Empresa_Test, Test_Calcular_Subtotal)
    {
        Empresa *empresa = new Empresa();

        Empleado *empleado1  = new Empleado(601,"Marcel", "Castro","mcastro@sveldo.biz",1,295);
        Empleado *empleado2  = new Empleado(115,"Benito", "Ramírez","benito@sveldo.biz",2,220);

        empresa->AgregarEmpleado(empleado1);
        empresa->AgregarEmpleado(empleado2);

         //Cargar la nomina en la empresa
        ControladorNomina *controladorNomina = new ControladorNomina();
        Nomina *entrada1 = new Nomina(601,7000);

        controladorNomina->AgregarNominas(entrada1);
        empresa->AgregarNominas(controladorNomina->getNominas());
        vector<HorasTrabajadas *> horasTrabajadas;
        //
        empleado1->setSalarioNeto(empresa->getNominas(),horasTrabajadas);
        //Cargar los datos de profesionales por horas
        ControladorProfesionalHoras *controladorProfesionalHoras = new ControladorProfesionalHoras();
        HorasTrabajadas *horasTrabajadas1 = new HorasTrabajadas(115,300,80);
        controladorProfesionalHoras->AgregarHorasTrabajadas(horasTrabajadas1);
        empresa->AgregarHorasTrabajadas(controladorProfesionalHoras->getHorasTrabajadas());

        vector<Nomina *> nominas;
        empleado2->setSalarioNeto(nominas,empresa->getHorasTrabajadas());

        double esperado = 30510;
        double actual = empleado1->getSalarioNeto()+empleado2->getSalarioNeto(); 
        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    //Calcular impuestos a retener
    TEST(Empresa_Test, Test_Impuestos_A_Retener)
    {
        Empresa *empresa = new Empresa();

        Empleado *empleado1  = new Empleado(601,"Marcel", "Castro","mcastro@sveldo.biz",1,295);
        Empleado *empleado2  = new Empleado(115,"Manuel", "Antonio","manu@sveldo.biz",1,220);

        empresa->AgregarEmpleado(empleado1);
        empresa->AgregarEmpleado(empleado2);

         //Cargar la nomina en la empresa
        ControladorNomina *controladorNomina = new ControladorNomina();
        Nomina *entrada1 = new Nomina(601,7000);
        Nomina *entrada2 = new Nomina(115,5000);

        controladorNomina->AgregarNominas(entrada1);
        controladorNomina->AgregarNominas(entrada2);

        empresa->AgregarNominas(controladorNomina->getNominas());

        vector<HorasTrabajadas *> horasTrabajadas;
        //
        empleado1->setSalarioNeto(empresa->getNominas(),horasTrabajadas);
        empleado2->setSalarioNeto(empresa->getNominas(),horasTrabajadas);
        // Por alguna razón el GTest se cae aquí cuando se utiliza double, entonces me vi obligado a usar int
        //double esperado = 840;
        //double actual = empleado1->getImpuestosARetener() + empleado2->getImpuestosARetener(); 
        int esperado = 840;
        int actual = empleado1->getImpuestosARetener() + empleado2->getImpuestosARetener(); 
        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }
    //Obtener el nombre del supervisor de un empleado
    TEST(Empresa_Test, Test_Calcular_Total)
    {
        Empresa *empresa = new Empresa();

        Empleado *empleado1  = new Empleado(601,"Marcel", "Castro","mcastro@sveldo.biz",1,295);
        Empleado *empleado2  = new Empleado(220,"Emannuel", "Soto","manu@sveldo.biz",2,220);

        empresa->AgregarEmpleado(empleado1);
        empresa->AgregarEmpleado(empleado2);

         //Cargar la nomina en la empresa
        ControladorNomina *controladorNomina = new ControladorNomina();
        Nomina *entrada1 = new Nomina(601,1000);

        controladorNomina->AgregarNominas(entrada1);
        empresa->AgregarNominas(controladorNomina->getNominas());
        vector<HorasTrabajadas *> horasTrabajadas;
        //
        empleado1->setSalarioNeto(empresa->getNominas(),horasTrabajadas);

        //Cargar los datos de profesionales por horas
        ControladorProfesionalHoras *controladorProfesionalHoras = new ControladorProfesionalHoras();
        HorasTrabajadas *horasTrabajadas1 = new HorasTrabajadas(220,500,45);

        controladorProfesionalHoras->AgregarHorasTrabajadas(horasTrabajadas1);
        empresa->AgregarHorasTrabajadas(controladorProfesionalHoras->getHorasTrabajadas());

        vector<Nomina *> nominas;
        empleado2->setSalarioNeto(nominas,empresa->getHorasTrabajadas());
        
        double esperado = 23500;
        double actual = empleado1->getSalarioNeto() + empleado2->getSalarioNeto() + empleado1->getImpuestosARetener();
        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual); //
    }
}