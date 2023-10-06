#pragma once
#include <string>
#include <iostream>

using namespace std;

class Software {
#include "Usuario.h"
private:
    string nombre;
    string developer;
    string clasificacionEdad;
    int precio;
    //ListaUsuario* listaUsuario;
    int cantUsuarios;

public:
    Software(string, string, string, int);
    ~Software();
    string getNombre();
    string getDeveloper();
    string getClasificacion();
    int getPrecio();
    virtual string tipo();
};

//Constructor
Software::Software(string nombre,string developer,string clasificacionEdad,int precio){
    this->nombre=nombre;
    this->developer=developer;
    this->clasificacionEdad=clasificacionEdad;
    this->precio=precio;
    this->cantUsuarios=0;
    //this->listaUsuario= new ListaUsuario();
}
//Destructor
Software::~Software(){

}
//obtener el nombre
string Software::getNombre(){
    return this->nombre;
}
//obtener el desarrollador
string Software::getDeveloper(){
    return this->developer;
}
//obtener la clasificacion
string Software::getClasificacion(){
    return this->clasificacionEdad;
}
//obtener el precio
int Software::getPrecio(){
    return this->precio;
}
string Software::tipo(){
    return "Software generico";
}