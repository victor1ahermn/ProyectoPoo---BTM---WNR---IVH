all: compilar
compilar: propietario Mascota main
	g++ -o Salida Propietario.o Mascota.o Main.o
propietario: Propietario.cpp Propietario.h Mascota.h
	g++ -c Propietario.cpp
Mascota: Mascota.cpp Mascota.h
	g++ -c Mascota.cpp
main: Main.cpp Propietario.h Mascota.h
	g++ -c main.cpp
clean: #Comando para borrar los o.
	@echo "Cleaning Compilation..."
	del *.o