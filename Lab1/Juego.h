#pragma once
#include <string>
#include <iostream>
#include "Software.h"
using namespace std;
class Juego:public Software{
    //Atributos del software Juego
    private:
    string genero;

    //Metodos del software Juego
    public:
    Juego(string,string,string,int,string);
    ~Juego();
    string tipo() override;
    
};
//constructor
Juego::Juego(string nombre,string developer,string clasificacionEdad,int precio,string genero) : Software(nombre,developer,clasificacionEdad,precio){
    this->genero=genero;
}
//destructor
Juego::~Juego(){

}
string Juego::tipo(){
    return "Clase Juego";
}