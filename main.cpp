#include <iostream>
#include "Propietario.h"
#include "Mascota.h"

using namespace std;


Propietario * agregarPropietario(map<string,Propietario*> &directorio,bool modificacion){
    string nombre,email,identificacion,telefono;
    cout<<"Ingrese nombre"<<endl;
    getline(cin>>ws,nombre); //se le pone cin>>ws para que extraiga todos los caracteres whitespace
    cout<<"Ingrese email"<<endl;
    getline(cin>>ws,email);
    cout<<"Ingrese identificacion"<<endl;
    getline(cin>>ws,identificacion);
    cout<<"Ingrese telefono"<<endl;
    getline(cin>>ws,telefono);
    
    if(directorio.count(identificacion) > 0 && !modificacion)
        cout<<"Este numero de identificacion ya esta registrado!, no se pudo agregar el propietario"<<endl;
    else{
        directorio[identificacion] = new Propietario(nombre,email,identificacion,telefono);
        cout<<"Propietario agregado con exito!"<<endl;
        return directorio[identificacion];
    }
    return NULL;
}


void eliminarPropietario(map<string,Propietario*> &directorio){
    string identificacion;
    cout<<"Ingrese identificacion"<<endl;
    getline(cin>>ws,identificacion);
    if(directorio.count(identificacion) > 0){
        directorio.erase(identificacion);
        cout<<"Propietario eliminado con exito!"<<endl;
            
    }
    else{
        cout<<"No se encontro el propietario"<<endl;

    }
    
}
void modificarPropietario(map<string,Propietario*> &directorio){
    string identificacion;
    cout<<"Ingrese identificacion"<<endl;
    getline(cin>>ws,identificacion);
    if(directorio.count(identificacion) > 0){
        cout<<"Propietario encontrado, porfavor ingrese datos de nuevo"<<endl;
        directorio.erase(identificacion);
        agregarPropietario(directorio,true);
    }
    else{
        cout<<"No se encontro el propietario!"<<endl;
    }

}

void mostrarPropietarios(map<string,Propietario*> directorio){
    for(map<string,Propietario*>::iterator it = directorio.begin();it != directorio.end();it++){
        it->second->imprimirInformacion();
        cout<<endl;
    }

}


void mostrarMascotas(map<string,Mascota*> mascotas){
     for(map<string,Mascota*>::iterator it = mascotas.begin();it != mascotas.end();it++){
        it->second->imprimirInformacion();
        cout<<endl;
    }
}


void buscarPropietariosMascota(map<string,Propietario*> directorio){
    string identificacion;
    cout<<"Ingrese identificacion de la mascota"<<endl;
    getline(cin>>ws,identificacion);
    cout<<"Los propietarios de esta mascota son:"<<endl;
    for(map<string,Propietario*>::iterator it = directorio.begin();it != directorio.end();it++){
        if(it->second->buscarMascota(identificacion)){
                it->second->imprimirInformacion();
                cout<<endl;
        }
            
    }
}

void buscarMascotasPropietario(map<string,Propietario*> directorio){
    string identificacion;
    cout<<"Ingrese identificacion"<<endl;
    getline(cin>>ws,identificacion);
    if(directorio.count(identificacion) > 0){
        cout<<"Las mascotas de este propietario son"<<endl;
        directorio[identificacion]->imprimirMascotas();
    }
}

Mascota *agregarMascota(map<string,Mascota*> &mascotas){
    string nombre,raza,identificacion,tipo,tipoSangre;
    int edad;
    double peso;
    cout<<"Ingrese nombre"<<endl;
    getline(cin>>ws,nombre); //se le pone cin>>ws para que extraiga todos los caracteres whitespace
    cout<<"Ingrese raza"<<endl;
    getline(cin>>ws,raza);
    cout<<"Ingrese identificacion"<<endl;
    getline(cin>>ws,identificacion);
    cout<<"Ingrese tipo (perro|gato|otro)"<<endl;
    getline(cin>>ws,tipo);
    
    cout<<"Ingrese tipo de sangre"<<endl;
    getline(cin>>ws,tipoSangre);
    cout<<"Ingrese edad (en meses)"<<endl;
    cin>>edad;
    cout<<"Ingrese peso (en kg)"<<endl;
    cin>>peso;
    
    
    if(mascotas.count(identificacion) > 0 )
        cout<<"Este numero de identificacion ya esta registrado!, no se pudo agregar la mascota"<<endl;
    else{
        mascotas[identificacion] = new Mascota(raza,tipo,tipoSangre,nombre,identificacion,"",false,edad,peso);
        cout<<"Mascota agregada con exito!"<<endl;
        return mascotas[identificacion];
    }
    return NULL;


    


}

void asociarNuevaMascotaAPropietario(map<string,Propietario*> &directorio,map<string,Mascota*> &mascotas){
    string identificacion;
    cout<<"Ingrese identificacion del propietario"<<endl;
    getline(cin>>ws,identificacion);
    if(directorio.count(identificacion) > 0){
        cout<<"Ingrese datos de la nueva mascota"<<endl;
        Mascota *m = agregarMascota(mascotas);
        if(m != NULL)
            directorio[identificacion]->agregarMascota(m->getIdentificacion(),m);
    }
    else{
        cout<<"No se encontró el propietario!"<<endl;
    }

}

void asociarNuevoPropietarioAMascota(map<string,Propietario*> &directorio,map<string,Mascota*> &mascotas){
    string identificacion;
    cout<<"Ingrese identificacion de la mascota"<<endl;
    getline(cin>>ws,identificacion);
    if(mascotas.count(identificacion) > 0){
        cout<<"Ingrese datos del nuevo propietario"<<endl;
        Propietario *p = agregarPropietario(directorio,false);
        if(p != NULL){
            directorio[p->getIdentificacion()]->agregarMascota(identificacion,mascotas[identificacion]);
        }
    }
    else{
        cout<<"No se encontró la mascota!"<<endl;
    }
}


void cambiarStatusMascota(map<string,Mascota*> &mascotas){
    string identificacion,fecha;
    cout<<"Ingrese identificacion de la mascota"<<endl;
    getline(cin>>ws,identificacion);
    if(mascotas.count(identificacion) > 0){
        cout<<"Ingrese fecha de defuncion (formato DD/MM/YYY)"<<endl;
        getline(cin>>ws,fecha);
        mascotas[identificacion]->setStatus(true);
        mascotas[identificacion]->setFechaDefuncion(fecha);
            
    }
    else{
        cout<<"No se encontró la mascota!"<<endl;
    }
}


void eliminarPropietarioDeMascota(map<string,Propietario*> &directorio){
    string identificacion,idMascota;
    cout<<"Ingrese identificacion del propietario"<<endl;
    getline(cin>>ws,identificacion);
    if(directorio.count(identificacion) > 0){
        cout<<"Ingrese identificacion de la mascota"<<endl;
        getline(cin>>ws,idMascota);
        if(directorio[identificacion]->buscarMascota(idMascota)){
            directorio[identificacion]->eliminarMascota(idMascota);
            cout<<"Mascota eliminada del propietario con exito"<<endl;
        }
        else{
            cout<<"No se enonctro la mascota!"<<endl;
        }


    }
    else{
        cout<<"No se encontró el propietario"<<endl;
    }
}

int main(){
    map<string,Propietario*> directorio;
    map<string,Mascota*> mascotas;
    int opc = 1;
    string s;
    while(opc != 0){

        cout<<"Ingrese 0 para salir"<<endl;
        cout<<"Ingrese 1 para agregar un propietario"<<endl;
        cout<<"Ingrese 2 para modificar un propietario"<<endl;
        cout<<"Ingrese 3 para eliminar un propietario"<<endl;
        cout<<"Ingrese 4 para mostrar cuantos propietarios hay en el directorio"<<endl;
        cout<<"Ingrese 5 para mostrar la informacion de los propietarios del directorio"<<endl;
        cout<<"Ingrese 6 para mostrar la informacion de las mascotas registradas en el directorio"<<endl;
        cout<<"Ingrese 7 para buscar los propietarios dada una mascota"<<endl;
        cout<<"Ingrese 8 para buscar las mascotas dado un propietario"<<endl;
        cout<<"Ingrese 9 para asociar una nueva mascota a un propietario"<<endl;
        cout<<"Ingrese 10 para asociar nuevo propietario a una mascota"<<endl;
        cout<<"Ingrese 11 para cambiar el status de una mascota"<<endl;
        cout<<"Ingrese 12 para eliminar un propietario de una mascota"<<endl;

        cin>>opc;
        if(opc == 1){
            agregarPropietario(directorio,false);
        }
        else if(opc == 2){
            modificarPropietario(directorio);
        }
        else if(opc == 3){
            eliminarPropietario(directorio);

        }
        else if(opc == 4){
            cout<<"El directorio contiene "<<directorio.size()<<" propietario(s)"<<endl;
        }

        else if(opc == 5){
            mostrarPropietarios(directorio);

        }
        else if(opc == 6){
            mostrarMascotas(mascotas);

        }
        else if(opc == 7){
            buscarPropietariosMascota(directorio);
        }
        else if(opc == 8){
            buscarMascotasPropietario(directorio);

        }
        else if(opc == 9){
            asociarNuevaMascotaAPropietario(directorio,mascotas);
        }
        else if(opc == 10){
            asociarNuevoPropietarioAMascota(directorio,mascotas);
        }
        else if(opc == 11){
            cambiarStatusMascota(mascotas);

        }
        else if(opc == 12){
            eliminarPropietarioDeMascota(directorio);
        }
        
    }
    return 0;
}