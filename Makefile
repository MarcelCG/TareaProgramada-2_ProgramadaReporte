FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ $(FLAGS) src/empresa.cpp -o bin/empresa.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ $(FLAGS) src/horasTrabajadas.cpp -o bin/horasTrabajadas.o
	g++ $(FLAGS) src/nomina.cpp -o bin/nomina.o
	g++ $(FLAGS) src/controladorNomina.cpp -o bin/controladorNomina.o
	g++ $(FLAGS) src/controladorProfesionalHoras.cpp -o bin/controladorProfesionalHoras.o
	cp ./personas.txt ./bin/personas.txt
	cp ./nomina.txt ./bin/nomina.txt
	cp ./horastrabajadas.txt ./bin/horastrabajadas.txt
	g++ -g -o bin/programadareporte bin/empresa.o bin/main.o bin/empleado.o bin/nomina.o bin/horasTrabajadas.o bin/controladorNomina.o bin/controladorProfesionalHoras.o

test:
	mkdir -p bin
	g++ $(FLAGS) src/empresa.cpp -o bin/empresa.o
	g++ $(FLAGS) tests/empresa_tests.cpp -o bin/empresa_tests.o
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ $(FLAGS) src/horasTrabajadas.cpp -o bin/horasTrabajadas.o
	g++ $(FLAGS) src/nomina.cpp -o bin/nomina.o
	g++ $(FLAGS) src/controladorNomina.cpp -o bin/controladorNomina.o
	g++ $(FLAGS) src/controladorProfesionalHoras.cpp -o bin/controladorProfesionalHoras.o

	g++ -g -o bin/tests bin/empresa.o bin/empresa_tests.o bin/empleado.o bin/horasTrabajadas.o bin/nomina.o bin/controladorNomina.o bin/controladorProfesionalHoras.o -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin
