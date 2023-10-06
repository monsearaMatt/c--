#pragma once
#include <string>
#include <iostream>
#include "Usuario.h"
using namespace std;
class Normal:public Usuario{ 
    //Atributos del usuario normal
    private:
    string correo;
    bool acceso;
    
    //Metodos del usuario normal
    public:
    Normal(string, string, int, string);
    ~Normal();
    string getCorreo();
    bool getAcceso();
    void setCorreo(string);
    
};

//constructor
Normal::Normal(string nombre, string password, int edad, string correo) : Usuario(nombre,password,edad){
    this->correo=correo;
    this->acceso=false;
}
//destructor
Normal::~Normal(){
    
}
//obtener el correo
string Normal::getCorreo(){
    return this->correo;
}
//obtener el acceso
bool Normal::getAcceso(){
    return this->acceso;
}
void Normal::setCorreo(string c){
    this->correo=c;
}
