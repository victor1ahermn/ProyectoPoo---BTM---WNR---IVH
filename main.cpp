#include <iostream>
#include "Propietario.h"
#include "Mascota.h"
#include "Sistema.h"
using namespace std;


int main(){
    Sistema *s = new Sistema();
    s->menu();
    
    return 0;
}