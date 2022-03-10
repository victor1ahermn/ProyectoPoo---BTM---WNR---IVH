#include "Mascota.h"

/// constructor por parámetros

Mascota::Mascota(){

}

Mascota::Mascota(string raza,string tipo,string tipoSangre,string nombre,string identificacion,string fechaDefuncion,bool status,int edad,double peso){
    this->raza = raza;
    this->tipo = tipo;
    this->tipoSangre = tipoSangre;
    this->nombre = nombre;
    this->identificacion = identificacion;
    this->fechaDefuncion = fechaDefuncion;
    this->status = status;
    this->edad = edad;
    this->peso = peso;
}


string Mascota::getRaza(){
    return raza;
}

string Mascota::getTipo(){
    return tipo;
}

string Mascota::getTipoSangre(){
    return tipoSangre;
}
string Mascota::getNombre(){
    return nombre;
}
string Mascota::getIdentificacion(){
    return identificacion;
}
bool Mascota::getStatus(){
    return status;
}

double Mascota::getPeso(){
    return peso;
}

int Mascota::getEdad(){
    return edad;
}

string Mascota::getFechaDefuncion(){
    return fechaDefuncion;
}


void Mascota::setRaza(string raza){
   this -> raza = raza;
}

void Mascota::setTipo(string tipo){
    this -> tipo = tipo;
}

void Mascota::setTipoSangre(string sangre){
    this -> tipoSangre = sangre;
}

void Mascota::setNombre(string nombre){
    this -> nombre = nombre;
}

void Mascota::setIdentificacion(string id){
    this -> identificacion = id;
}

void Mascota::setFechaDefuncion(string fechaDefuncion){
    this -> fechaDefuncion = fechaDefuncion;
}

void Mascota::setStatus(bool estado){
    this -> status = estado;
}

void Mascota::setEdad(int edad){
    this -> edad =edad;
}

void Mascota::setPeso(double peso){
    this -> peso = peso;
}

/// procedimiento que muestra en pantalla los datos del objeto

void Mascota::imprimirInformacion(){
    cout<<"Raza: "<<raza<<endl;
    cout<<"Tipo: "<<tipo<<endl;
    cout<<"Tipo sangre: "<<tipoSangre<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Identificacion: "<<identificacion<<endl;
    if(!status){
        cout<<"Status: viva"<<endl;
    }
    else{
        cout<<"Status: muerta"<<endl;
        cout<<"Fecha de defuncion: "<<fechaDefuncion<<endl;
    }
    cout<<"Edad: "<<edad<<endl;
    cout<<"Peso: "<<peso<<endl;



}