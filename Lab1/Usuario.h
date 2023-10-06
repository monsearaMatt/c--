#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Software.h"
using namespace std;
class Usuario{
    private:
    private:
    string nombre;
    string password;
    int edad;
    vector<Software*> listaSoftware;
    
    //Metodos
    public:
    Usuario(string,string,int);//Constructor
    ~Usuario();//Destructor
    string getNombre();
    int getEdad();
    void setNombre(string);
    void setEdad(int);
    void setpassword(string);
    string getPassword();
    vector<Software*> getSoftwares();
    virtual string tipo();
    void agregarSoftware(Software*);
    void desinstalarSoftware(string);
};
//Constructor
Usuario::Usuario(string nombre, string password, int edad){
    this->nombre=nombre;
    this->password=password;
    this->edad=edad;
}
//Destructor
Usuario::~Usuario(){
}
//Obtener el nombre
string Usuario::getNombre(){
    return this->nombre;
}
//Obtener la edad
int Usuario::getEdad(){
    return this->edad;
}
//Cambiar el nombre
void Usuario::setNombre(string nombre){
    this->nombre= nombre;
}
//cambiar la edad
void Usuario::setEdad(int edad){
    this->edad=edad;
}
//cambiar la contraseña
void Usuario::setpassword(string password){
    this->password=password;
}
//obtener la contraseña
string Usuario::getPassword(){
    return this->password;
}
//obtener la lista de softwares
vector<Software*> Usuario::getSoftwares(){
    return this->listaSoftware;
}
string Usuario::tipo(){
    return "Clase Usuario";
}
//Agregar software 
void Usuario::agregarSoftware(Software* p){
    for(int i=0;i<listaSoftware.size();i++){
        if(listaSoftware[i]->getNombre()==p->getNombre()){
            cout<<"Este software ya existe en la lista\n";
            return;
        }
    }
    cout<<"Agregado exitosamente\n";
    listaSoftware.push_back(p);
}

//desinstalar software
void Usuario::desinstalarSoftware(string n){
    for(int i=0;i<listaSoftware.size();i++){
        if(listaSoftware[i]->getNombre()==n){
            listaSoftware.erase(listaSoftware.begin()+i);
            cout<<"Software desinstalado exitosamente\n";
            return;
        }
    }
    cout<<"Software no encontrado\n";
    return;
}