#pragma once
#include <string>
#include <iostream>
#include "Software.h"
using namespace std;
class Navegador:public Software{
    //Atributos del software navegador
    private:
    string historialNavegacion[10];

    //Metodos del software navegador
    public:
    Navegador(string,string,string,int,string,string,string,string,string,string,string,string,string,string);
    ~Navegador();
    //string getHistorial();
};
//constructor
Navegador::Navegador(string nombre,string developer,string clasificacionEdad,int precio,string n1,string n2,string n3,string n4,string n5,string n6,string n7,string n8,string n9,string n10):Software(nombre,developer,clasificacionEdad,precio){
    this->historialNavegacion[0]=n1;
    this->historialNavegacion[1]=n2;
    this->historialNavegacion[2]=n3;
    this->historialNavegacion[3]=n4;
    this->historialNavegacion[4]=n5;
    this->historialNavegacion[5]=n6;
    this->historialNavegacion[6]=n7;
    this->historialNavegacion[7]=n8;
    this->historialNavegacion[8]=n9;
    this->historialNavegacion[9]=n10;
}
//Destructor
Navegador::~Navegador(){
    
}