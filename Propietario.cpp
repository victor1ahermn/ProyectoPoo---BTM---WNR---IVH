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

void Propietario::setEmail(string s){
    email = s;
}

void Propietario::setIdentificacion(string s){
    identificacion = s;
}

void Propietario::setNombre(string s){
    nombre = s;
}

void Propietario::setTelefono(string s){
    telefono = s;
}


void Propietario:: agregarMascota(string id,Mascota *mascota){
    mascotas[id] = mascota;
}

bool Propietario::buscarMascota(string id){
    return mascotas.count(id) > 0;//Retorna true si la mascota si la posee la persona, si no false
}

void Propietario::eliminarMascota(string id){
    mascotas.erase(id);
}

void Propietario::imprimirMascotas(){
    for(map<string,Mascota*>::iterator it = mascotas.begin(); it != mascotas.end();it++){
        it->second->imprimirInformacion();
        cout<<"-------------------"<<endl;
    }

}

void Propietario::imprimirInformacion(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Identificacion: "<<identificacion<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Telefono: "<<telefono<<endl;
    cout<<"Mascotas:"<<endl;
    cout<<"-------------------"<<endl;
    imprimirMascotas();
    


}