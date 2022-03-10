#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include "Propietario.h"
#include "Mascota.h"

/** La clase Sistema consiste en 1 constructor por defecto y 13 métodos de caracter público, de los cuales dos
 * tienen retorno -o son funciones- (uno de tipo apuntador a un objeto de clase Propietario y otro tipo apuntador
 * a un objeto de clase Mascota [direcciones de memoria]) y los otros 11 son procedimientos */

class Sistema{

    public:
        /// constructor por defecto
        Sistema();
        /** funcion agregarPropietario, recibe un mapa con key value de tipo string y mapped value de tipo apun-
         * tador a un objeto clase Propietario nombrado con su direccion de memoriao y un valor booleano; se
         * encarga de añardir un nuevo objeto de tipo propietario al mapa con su respectiva llave*/
        Propietario * agregarPropietario(map<string,Propietario*> &directorio,bool modificacion);
        /** procedimientos que reciben un mapa con key value string y mapped value apuntador de un propietario
         * nombrado con su direccion de memoria; eliminarPropietario para buscar dentro del directorio una llave y
         * borrar el objeto - modificarPropietario para buscar a un propietario y cambiar sus datos */
        void eliminarPropietario(map<string,Propietario*> &directorio);
        void modificarPropietario(map<string,Propietario*> &directorio);
        /** procedimiento que recibe la estructura mapa directorio, encargado de mostrar en pantalla a los propietarios
         * del veterinario y sus datos*/
        void mostrarPropietarios(map<string,Propietario*> directorio);
        /** procedimiento que recibe la estructura mapa de direectorio de mascotas, encargado de mostrar en pantalla
         * a las mascotas registradas en el veterinario y sus datos*/
        void mostrarMascotas(map<string,Mascota*> mascotas);
        /** procedimiento que recibe una estructura mapa directorio de propietarios con el fin de mostrar en
         * pantalla los propietarios de una mascota*/
        void buscarPropietariosMascota(map<string,Propietario*> directorio);
        /** procedimiento que recibe una estructura mapa directorio de propietarios con el fin de mostrar en
         * pantalla todas las mascotas de un propietario*/
        void buscarMascotasPropietario(map<string,Propietario*> directorio);
        /** funcion que retorna apuntador a un objeto de clase Mascota y recibe una estructura mapa directorio de
         * mascotas con el fin de preguntar los datos de una mascota y añadirlos a un objeto agregado al mapa*/
        Mascota *agregarMascota(map<string,Mascota*> &mascotas);
        /** procedimiento que recibe dos estructuras mapa que guardan objetos tipo clase Propietario y clase Mascota,
         * con el fin de interconectar ambas clases y linkear las mascotas con los propietarios */
        void asociarNuevaMascotaAPropietario(map<string,Propietario*> &directorio,map<string,Mascota*> &mascotas);
        /** procedimiento que recibe dos estructuras mapa que guardan objetos tipo clase Propietario y clase Mascota,
        * con el fin de interconectar ambas clases y linkear los propietarios con las mascotas */
        void asociarNuevoPropietarioAMascota(map<string,Propietario*> &directorio,map<string,Mascota*> &mascotas);
        /** procedimiento para cambiar el atributo status del objeto tipo clase Mascota guardado en el directorio
         * de mascotas */
        void cambiarStatusMascota(map<string,Mascota*> &mascotas);
        /// procedimiento para eliminar del directorio a un propietario asociado a una mascota
        void eliminarPropietarioDeMascota(map<string,Propietario*> &directorio);
        /// procedimiento para mostrar en pantalla las opciones de interacción disponibles con el sistema
        void menu();

};


#endif