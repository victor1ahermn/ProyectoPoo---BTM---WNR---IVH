all: compilar
compilar: propietario Mascota Sistema main
	g++ -o Salida Propietario.o Mascota.o Sistema.o main.o
propietario: Propietario.cpp Propietario.h Mascota.h
	g++ -c Propietario.cpp
Mascota: Mascota.cpp Mascota.h
	g++ -c Mascota.cpp
Sistema: Sistema.cpp Sistema.h Propietario.h Mascota.h
	g++ -c Sistema.cpp
main: main.cpp Sistema.h Propietario.h Mascota.h
	g++ -c main.cpp
clean: #Comando para borrar los o.
	@echo "Cleaning Compilation..."
	del *.o