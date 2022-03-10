#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include <iostream>
#include <string>
#include <map>
#include "Mascota.h"

using namespace std;

/** la clase Propietario consiste en 5 atributos privados, 1 constructor con parámetros, 4 gets, 4 sets y 5 metodos
 * de los cuales solo uno es una funcion que retorna un valor booleano. Los atributos guardan el nombre del
 * propietario, su email, la identificacion y el telefono (todo en un string puesto que no realizaremos operaciones
 * con la identificacion o el telefono), el mapa es utilizado para guardar a los objetos de tipo clase Mascota
 * asociados al propietario */

class Propietario{
    private:
        string nombre,email,identificacion,telefono;
        map<string,Mascota*> mascotas;//mascotas guardadas por propietario segun la identificacion de la mascota

    public:
        Propietario();
        Propietario(string nombre,string email,string identificacion,string telefono);
        string getNombre();
        string getEmail();
        string getIdentificacion();
        string getTelefono();
        void setNombre(string nomre);
        void setEmail(string email);
        void setIdentificacion(string id);
        void setTelefono(string telefono);
        void agregarMascota(string id,Mascota *mascota);
        void imprimirInformacion();
        void imprimirMascotas();
        void eliminarMascota(string id);
        bool buscarMascota(string id);


};

#endif