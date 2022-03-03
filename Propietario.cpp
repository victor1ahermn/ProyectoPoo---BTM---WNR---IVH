#include "Propietario.h"



Propietario::Propietario(){

}

Propietario::Propietario(string nombre,string email,string identificacion,string telefono){
        this->nombre = nombre;
        this->email = email;
        this->identificacion = identificacion;
        this->telefono = telefono;

}

string Propietario::getNombre(){
    return nombre;
}

string Propietario::getEmail(){
    return email;
}

string Propietario::getIdentificacion(){
    return identificacion;
}

string Propietario::getTelefono(){
    return telefono;
}

void Propietario::setEmail(string email){
    this -> email = email;
}

void Propietario::setIdentificacion(string identificacion){
    this -> identificacion = identificacion;
}

void Propietario::setNombre(string nombre){
    this -> nombre = nombre;
}

void Propietario::setTelefono(string telefono){
    this -> telefono = telefono;
}
