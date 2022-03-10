#include "Sistema.h"

/// constructor por defecto

Sistema::Sistema(){

}

/** Se declaran variables locales para guardar los datos consultados por consola, se asignan a un objeto de tipo
 * propietario, se verifica con la llave y la funcion predeterminada count que no exista un usuario igual, de no
 * estar en el directorio se agrega el objeto y se retorna el apuntador al objeto*/

Propietario * Sistema::agregarPropietario(map<string,Propietario*> &directorio,bool modificacion){
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
/** Se declara variable local para guardar la llave consultada por consola, se verefica que exista en el
 * diccionario, en caso positivo, se borra con funcion predeterminada erase y se imprime un mensaje de éxito,
 * en caso contrario, se imprime un mensaje informando que no existe el propietario */

void Sistema::eliminarPropietario(map<string,Propietario*> &directorio){
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

/** Se declara variable local para guardar la llave consultada por consola, se verefica que exista en el
 * diccionario, en caso positivo, se asigna valor True a la funcion agregarPropietario, con el fin de que
 * repita la función, pero sobrescriba los valores de los atributos previos en el objeto, en caso contrario,
 * se imprime un mensaje informando que no existe el propietario */

void Sistema::modificarPropietario(map<string,Propietario*> &directorio){
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
/** procedimiento que recorre el mapa de propietarios con un for usando los iteradores especiales de la libreria;
 * los iteradores consisten en la instanciación de una variable a través de la funcion .begin() que devuelve la
 * primera posicion del directorio, y la función .end() que devuelve la posición ulterior al último elemento de
 * la estructura -así accedemos a través del operador -> al objeto (puesto que es una direccion de memoria) y
 * utilizamos el metodo imprimirInformacion del objeto, imprime una línea vacía al finalizar */

void Sistema::mostrarPropietarios(map<string,Propietario*> directorio){
    for(map<string,Propietario*>::iterator it = directorio.begin();it != directorio.end();it++){
        it->second->imprimirInformacion();
        cout<<endl;
    }

}

/** procedimiento que recorre el mapa de objetos clase Mascota con un for usando nuevamente los iteradores
 * especiales de la libreria; sigue el mismo algoritmo que el procedimiento explciado con anterioridad */

void Sistema::mostrarMascotas(map<string,Mascota*> mascotas){
     for(map<string,Mascota*>::iterator it = mascotas.begin();it != mascotas.end();it++){
        it->second->imprimirInformacion();
        cout<<endl;
    }
}

/** procedimiento que recorre el mapa de objetos clase Propietario con un for usando los iteradores
 * especiales de la libreria; compara cada posicion del mapa con el mapped value (por eso se utiliza el ->second)
 * utiliza el metodo de buscarMascota con la llave (identificacion de la mascota asociada al
 * propietario) y, si la encuentra, sigue el mismo algoritmo que el procedimiento explciado con anterioridad,
 * imprime los datos de la mascota y luego una línea vacia, si no retorna False */

void Sistema::buscarPropietariosMascota(map<string,Propietario*> directorio){
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

/** procedimiento que consulta por consola la llave (identificacion del propietario) y luego recorre el
 * directorio de mascotas para imprimir aquellas asociadas a la identificacion del propietario*/

void Sistema::buscarMascotasPropietario(map<string,Propietario*> directorio){
    string identificacion;
    cout<<"Ingrese identificacion"<<endl;
    getline(cin>>ws,identificacion);
    if(directorio.count(identificacion) > 0){
        cout<<"Las mascotas de este propietario son"<<endl;
        directorio[identificacion]->imprimirMascotas();
    }
}

/** Se declaran variables locales para guardar los datos consultados por consola, se asignan a un objeto de tipo
 * Mascota, se verifica con la llave y la funcion predeterminada count que no exista una mascota igual, de no
 * estar en el directorio se agrega el objeto y se retorna el apuntador al objeto presente en la posicion de la
 * identificacion*/

Mascota* Sistema::agregarMascota(map<string,Mascota*> &mascotas){
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

/** Se consulta por consola identificacion del propietario, si se encuentra la identificacion se instancia un
 * apuntador a un objeto de tipo mascota instanciado por la funcion agregarMascota (guardará la direccion de
 * memoria del objeto), si m es distinto de Nulo (no hubo problemas al darle espacio a la mascota), entonces
 * accede al directorio en la posicion de la identificacion (un apuntador) y a través del operador -> accede
 * al metodo agregarMascota que se añade a la identificacion del objeto (añade a la estructura un nuevo objeto
 * de tipo Mascota). Si la identificacion del propietario no se encuentra se imprime un mensaje informando de esto */

void Sistema::asociarNuevaMascotaAPropietario(map<string,Propietario*> &directorio,map<string,Mascota*> &mascotas){
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

/** procedimiento que consulta la identificacion de la mascota, si la encuentra en el directorio inicializa una
 * variable que recopila los datos a través de la función agregarPropietario, si no hay problema para asignar
 * espacio a esta variable, entonces se dirige al directorio de propietario y en la identificacion ingresada por
 * consola, agrega un nuevo objeto de tipo Propietario a la mascota. De no encontrar se informa al usuario */

void Sistema::asociarNuevoPropietarioAMascota(map<string,Propietario*> &directorio,map<string,Mascota*> &mascotas){
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

/** Se declaran variables locales para guardar los datos consultados por consola, se verifica que en el
 * directorio exista la identificacion de la mascota, de ser así, se solicita la fecha de defuncion, se accede al
 * objeto de la posicion de la identificacion en el directorio mascostas y se cambian mediante sets los valores
 * predeterminados del objeto*/

void Sistema::cambiarStatusMascota(map<string,Mascota*> &mascotas){
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

/** se declaran variables locales para guardar los datos consultados por consola, se verifica que exista la
 * identificacion del usuario en el directorio, de ser así se solicita el id de la mascota y se accede al objeto
 * para verificar que exista la mascota asociada, de ser así, se llama a la funcion eliminar mascota, la cual,
 * mediante la funcion predeterminada erase(), elimina lo que está ubicado en el id de la mascota. Si no se
 * encuentra la mascota asociada al propietario, se informa de esto, y si no se encuentra el propietario,
 * igualmente se informa */

void Sistema::eliminarPropietarioDeMascota(map<string,Propietario*> &directorio){
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

/// Declaracion de los mapas directorio de mascotas y propietarios e implementacion switch para menu

void Sistema::menu(){
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
        switch (opc){
            case 0:
                break;
            case 1:  
                agregarPropietario(directorio,false);
            break;

            case 2:
                modificarPropietario(directorio);
            break;
            
            case 3:
                eliminarPropietario(directorio);
            break;

            case 4:
                cout<<"El directorio contiene "<<directorio.size()<<" propietario(s)"<<endl;
            break;

            case 5:
                mostrarPropietarios(directorio);
            break;

            case 6:
                mostrarMascotas(mascotas);
            break;

            case 7:
                buscarPropietariosMascota(directorio);
            break;

            case 8:
                buscarMascotasPropietario(directorio);
            break;

            case 9:
                asociarNuevaMascotaAPropietario(directorio,mascotas);
            break;

            case 10:
                asociarNuevoPropietarioAMascota(directorio,mascotas);
            break;

            case 11:
                cambiarStatusMascota(mascotas);
            break;

            case 12:
                eliminarPropietarioDeMascota(directorio);
            break;

            default:
                cout << "Opcion no valida"<<endl;
            break;
        }
    }
}

