#pragma once
#include <string>
#include <iostream>
#include "Usuario.h"
using namespace std;
class Administrador:public Usuario{ //Heredando metodos publicos
    //Atributos del usuario administrador
    private:
    string correo;
    bool acceso;
    
    //Metodos del usuario administrador
    public:
    Administrador(string, string, int, string);
    ~Administrador();
    string getCorreo();
    bool getAcceso();
    void setCorreo(string);
    
};

//constructor
Administrador::Administrador(string nombre, string password, int edad, string correo) : Usuario(nombre,password,edad){
    this->correo=correo;
    this->acceso=true;
}//destructor
Administrador::~Administrador(){
    
}
//obtener el correo
string Administrador::getCorreo(){
    return this->correo;
}
//obtener el acceso
bool Administrador::getAcceso(){
    return this->acceso;
}
void Administrador::setCorreo(string c){
    this->correo=c;
}