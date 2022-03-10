#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

/** la clase Mascota consiste en 9 atributos privados, 1 constructor con parámetros, 9 gets, 9 sets y 1 método
 * sin retorno (procedimiento). Los atributos guardan la raza, el tipo de animal, el tipo de sangre, el nombre,
 * la identificiacion, la fecha de defuncion, el estado (vivo/muerto) de la mascota, su edad y el peso */

class Mascota{
    private:
        string raza,tipo,tipoSangre,nombre,identificacion,fechaDefuncion;
        bool status;/// true si esta muerta, false de lo contrario
        int edad;/// edad en meses
        double peso;
        
    public:
        Mascota();
        Mascota(string,string,string,string,string,string,bool,int,double);
        string getRaza();
        string getTipo();
        string getTipoSangre();
        string getNombre();
        string getIdentificacion();
        string getFechaDefuncion();
        bool getStatus();
        int getEdad();
        double getPeso();

        void setRaza(string raza);
        void setTipo(string tipo);
        void setTipoSangre(string sangre);
        void setNombre(string nombre);
        void setIdentificacion(string id);
        void setFechaDefuncion(string fechaDefuncion);
        void setStatus(bool etado);
        void setEdad(int edad);
        void setPeso(double peso);

    

        void imprimirInformacion();



};

#endif