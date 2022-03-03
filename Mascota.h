#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>
#include <string>
#include <map>

using namespace std;
class Mascota{
    private:
        string raza,tipo,tipoSangre,nombre,identificacion,fechaDefuncion;
        bool status;//true si esta muerta, false de lo contrario
        int edad;//edad en meses
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

        void setRaza(string);
        void setTipo(string);
        void setTipoSangre(string);
        void setNombre(string);
        void setIdentificacion(string);
        void setFechaDefuncion(string);
        void setStatus(bool);
        void setEdad(int);
        void setPeso(double);

    

        void imprimirInformacion();



};

#endif