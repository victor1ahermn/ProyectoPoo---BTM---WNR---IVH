#include "Mascota.h"


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

void Mascota::setTipoSangre(string rh){
    tipoSangre = rh;
}

void Mascota::setNombre(string nombre){
    this -> nombre = nombre;
}

void Mascota::setIdentificacion(string id){
    identificacion = id;
}

void Mascota::setFechaDefuncion(string diaMuerte){
    fechaDefuncion = diaMuerte;
}

void Mascota::setStatus(bool estado){
    status = estado;
}

void Mascota::setEdad(int anios){
    edad =anios;
}

void Mascota::setPeso(double peso){
    this -> peso = peso;
}