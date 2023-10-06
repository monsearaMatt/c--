#pragma once
#include <string>
#include <iostream>
#include "Usuario.h"
using namespace std;
class Nino:public Usuario{
    //atributos del usuario niño
    private:

    //Metodos del usuario niño
    public:
    Nino(string, string, int);
    ~Nino();
    string tipo()override;
};
//constructor
Nino::Nino(string nombre, string password, int edad): Usuario(nombre, password, edad){
    
}
//destructor
Nino::~Nino(){
}
string Nino::tipo(){
    return "Clase Nino";
}
