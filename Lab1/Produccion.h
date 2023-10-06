#pragma once
#include <string>
#include <iostream>
#include "Software.h"
using namespace std;

class Produccion: public Software{
    //atributos del software de produccion
    private:
    string tipoSolucion;

    //metodos del software de produccion
    public:
    Produccion(string,string,string,int,string);
    ~Produccion();
};
//Constructor
Produccion::Produccion(string nombre,string developer,string clasificacionEdad,int precio,string tipoSolucion):Software(nombre,developer,clasificacionEdad,precio){
    this->tipoSolucion=tipoSolucion;
}
//Destructor
Produccion::~Produccion(){
    
}