#pragma once
#include "Software.h"
#include <iostream>
#include <string>

using namespace std;

class Produccion : public Software{
    private:
        string TipoProduccion;
        vector<Usuario*> userList;
    public:
        Produccion(string nombre,string Developer,string tipo, int edad, int Precio, string produc) : 
        Software(nombre, Developer,tipo, edad, Precio) {
            this -> TipoProduccion=produc;
        };
        ~Produccion(){
            cout<<"se elimino el objeto"<<endl;
        }
        string getTipoProduccion(){
             return this -> TipoProduccion;
        };
        void setTipoProduccion(string produc){
            this -> TipoProduccion=produc;
        };
        vector<Usuario*> getListaDeUsuariosDelPrograma(){
            return this -> userList;
        };
};