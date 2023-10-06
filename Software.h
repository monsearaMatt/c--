#pragma once
#include <string>
#include <iostream>


using namespace std;

class Software {
private:
    string nombre;
    string Developer;
    int edad;
    int Precio;
    
    int cantUsuarios;
    string tipo;

    public:
        Software(string nom,string Deve,string tipo,int eda, int prec){
            this -> nombre = nom;
            this -> Developer=Deve;
            this -> edad = eda;
            this -> Precio=prec;
            this -> tipo = tipo;
        };
        ~Software(){}
        string getNombre(){
             return this -> nombre;
        };
        string getTipo(){
             return this -> tipo;
        };
        string getDeveloper(){
            return this -> Developer;
        };
        int getEdad(){
            return this -> edad;
        };
        int getPrecio(){
            return this -> Precio;
        };
        
        void setNombre(string nombre){
            this -> nombre = nombre;
        };
        void setDeveloper(string Developer){
            this -> Developer=Developer;
        };
        void setTipo(string tipo){
            this -> tipo=tipo;
        };
        void setEdad(int edad){
            this -> edad = edad;
        };
        void SetPrecio(int precio){
            this -> Precio=precio;
        };
};