#pragma once
#include "Software.h"
#include <iostream>
#include <string>

using namespace std;

class Ofimatica : public Software{
    private:
        int CantidadArchivos;
        vector<Usuario*> userList;
    public:
        Ofimatica(string nombre,string Developer,string tipo, int edad, int Precio, int Archivos) 
        : Software(nombre, Developer,tipo,edad, Precio) {
            this -> CantidadArchivos=Archivos;
        };
        ~Ofimatica(){}
        int getCantidadArchivos(){
            return this -> CantidadArchivos;
        };
        void setGenero(int cantidad){
            this -> CantidadArchivos=cantidad;
        };
        vector<Usuario*> getListaDeUsuariosDelPrograma(){
            return this -> userList;
        };
};