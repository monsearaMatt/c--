#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Software.h"
#include "Usuario.h"

using namespace std;
class Social:public Software{
    
    private:
    vector<Usuario*> amigos;
    vector<Usuario*> userList;
    //Metodos del software social
    public:
    Social(string nombre,string Developer,string tipo, int edad, int Precio) : Software(nombre,Developer,tipo,edad,Precio){

    };
    ~Social(){};
    vector<Usuario*> getAmigos(){
        return this->amigos;
    };
    vector<Usuario*> getListaDeUsuariosDelPrograma(){
            return this -> userList;
        };
};
