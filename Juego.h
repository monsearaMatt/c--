#pragma once
#include <iostream>
#include <string>
#include "Software.h"

using namespace std;

class Juego : public Software{
    private:
        vector<Usuario*> userList;
        string Genero;
        
    public:
       Juego(string nombre,string Developer,string tipo, int edad, int Precio,string genero) : Software(nombre, Developer,tipo,edad, Precio) {
            this -> Genero=genero;
        };
        ~Juego(){
            cout<<"se elimino el objeto"<<endl;
        }
        string getGenero(){
             return this -> Genero;
        };
        void setGenero(string genero){
            this -> Genero = genero;
        };
        vector<Usuario*> getListaDeUsuariosDelPrograma(){
            return this -> userList;
        };
        
};