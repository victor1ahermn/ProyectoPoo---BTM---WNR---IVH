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


void Mascota::setRaza(string s){
    raza = s;
}

void Mascota::setTipo(string s){
    tipo = s;
}

void Mascota::setTipoSangre(string s){
    tipoSangre = s;
}

void Mascota::setNombre(string s){
    nombre = s;
}

void Mascota::setIdentificacion(string s){
    identificacion = s;
}

void Mascota::setFechaDefuncion(string s){
    fechaDefuncion = s;
}

void Mascota::setStatus(bool b){
    status = b;
}

void Mascota::setEdad(int i){
    edad =i;
}

void Mascota::setPeso(double d){
    peso = d;
}



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