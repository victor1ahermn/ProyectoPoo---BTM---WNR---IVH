#include "Propietario.h"


/// constructor con parámetros

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

void Propietario::setIdentificacion(string id){
    this -> identificacion = id;
}

void Propietario::setNombre(string nombre){
    this -> nombre = nombre;
}

void Propietario::setTelefono(string telefono){
    this -> telefono = telefono;
}

/// agrega en el mapa de mascotas del propietario, en la posicion id un apuntador a un objeto de tipo clase Mascota
void Propietario:: agregarMascota(string id,Mascota *mascota){
    mascotas[id] = mascota;
}

/// accede al mapa y verifica que identificacion se encuentre

bool Propietario::buscarMascota(string id){
    return mascotas.count(id) > 0; /// Retorna true si la mascota si la posee la persona, si no false
}

/// elimina el apuntador que se encuentra asociado al id

void Propietario::eliminarMascota(string id){
    mascotas.erase(id);
}

/// recorre el mapa con los iteradores especiales de la libreria determinada y utiliza el metodo del objeto Mascota
/// imprimirInformacion para mostrar los datos de la mascota

void Propietario::imprimirMascotas(){
    for(map<string,Mascota*>::iterator it = mascotas.begin(); it != mascotas.end();it++){
        it->second->imprimirInformacion();
        cout<<"-------------------"<<endl;
    }

}

/// muestra en pantalla los valores de los atributos del objeto de clase Propietario

void Propietario::imprimirInformacion(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Identificacion: "<<identificacion<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Telefono: "<<telefono<<endl;
    cout<<"Mascotas:"<<endl;
    cout<<"-------------------"<<endl;
    imprimirMascotas();
    


}