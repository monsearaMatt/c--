#pragma once
#include <string>
#include <iostream>
#include "Software.h"
using namespace std;
class Seguridad:public Software{
    //Atributos del software de seguridad
    private:
    string tipoMalware;

    //Metodos del software de seguridad
    public:
    Seguridad(string,string,string,int,string);
    ~Seguridad();
};
//Constructor
Seguridad::Seguridad(string nombre,string developer,string clasificacionEdad,int precio,string tipoMalware):Software(nombre,developer,clasificacionEdad,precio){
    this->tipoMalware=tipoMalware;
}
//Destructor
Seguridad::~Seguridad(){
    
}