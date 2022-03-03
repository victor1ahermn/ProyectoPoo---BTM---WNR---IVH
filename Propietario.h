#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include <iostream>
#include <string>
#include <map>
#include "Mascota.h"

using namespace std;
class Propietario{
    private:
        string nombre,email,identificacion,telefono;
        map<string,Mascota*> mascotas;//mascotas guardadas por propietario segun la identificacion de la mascota

    public:
        Propietario();
        Propietario(string,string,string,string);
        string getNombre();
        string getEmail();
        string getIdentificacion();
        string getTelefono();
        void setNombre(string);
        void setEmail(string);
        void setIdentificacion(string);
        void setTelefono(string);
        void agregarMascota(string, Mascota*);
        void imprimirInformacion();
        void imprimirMascotas();
        void eliminarMascota(string);
        bool buscarMascota(string);


};

#endif