#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Software.h"
using namespace std;

class Usuario{
    private:
    string usuario;
    string password;
    int edad;
    string correo;
    int log;
    vector<Software*> softwareList;
    
    ;public:
        Usuario(string us,string pas,int eda,string correo,int acceso){
            this -> usuario=us;
            this -> password=pas;
            this -> edad = eda;
            this -> correo = correo;
            this -> log = acceso;
        };
        ~Usuario(){}
        string getNombre(){
             return this -> usuario;
        };
        vector<Software*> getBiblioteca(){
            return this-> softwareList;
        };
        string getPassword(){
            return this -> password;
        };
        string getCorreo(){
            return this -> correo;
        };
        int getLog(){
            return this -> log;
        };
        int getEdad(){
            return this -> edad;
        };
        void setNombre(string Usuario){
            this -> usuario=Usuario;
        };
        void setCorreo(string Correo){
            this -> correo=Correo;
        };
        void setPassword(string Pasword){
            this -> password=Pasword;
        };
        void setEdad(int edad){
            this -> edad = edad;
        };
        //Agregar software 
        void agregarSoftware(Software* p){
            for(int i=0;i<softwareList.size();i++){
                if(softwareList[i]->getNombre()==p->getNombre()){
                cout<<"Este software ya existe en la lista\n";
                return;
                    }
            }
        cout<<"Agregado exitosamente\n";
        softwareList.push_back(p);
        };

        //desinstalar software
        void DesinstalarSoftware(string n){
        for(int i=0;i<softwareList.size();i++){
            if(softwareList[i]->getNombre()==n){
                softwareList.erase(softwareList.begin()+i);
                cout<<"Software eliminado del usuario exitosamente\n";
                return;
            }
        }
        cout<<"Software no encontrado\n";
        return;
        };
};