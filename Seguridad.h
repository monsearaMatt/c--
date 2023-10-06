#pragma once
#include <string>
#include <iostream>
#include "Software.h"
using namespace std;
class Seguridad : public Software{
    private:
    string tipoMalware;
    vector<Usuario*> userList;
    public:
    Seguridad(string nombre,string Developer,string tipo, int edad, int Precio, string tipoDeBicho) : 
        Software(nombre, Developer,tipo, edad, Precio) {
            this -> tipoMalware = tipoDeBicho;
        };
    ~Seguridad(){}
    string getMalwer(){
        return this -> tipoMalware;
    };
    void setMalwer(string malBicho){
        this -> tipoMalware=malBicho;
    };
    vector<Usuario*> getListaDeUsuariosDelPrograma(){
            return this -> userList;
        };
};
