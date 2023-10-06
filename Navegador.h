#pragma once
#include <string>
#include <iostream>
#include "Software.h"
using namespace std;
class Navegador : public Software{
    //lista para guardar las 10 paginas
    private:
    string historial[10];
    vector<Usuario*> userList;

    //metodos publicos de navegacion
    public:
    Navegador(string nombre,string Developer,string tipo, int edad, int Precio, string n1, string n2, string n3, string n4, string n5, string n6 ,string n7, string n8, string n9,string n10) 
        : Software(nombre, Developer,tipo,edad, Precio) {
            this->historial[0]=n1;
            this->historial[1]=n2;
            this->historial[2]=n3;
            this->historial[3]=n4;
            this->historial[4]=n5;
            this->historial[5]=n6;
            this->historial[6]=n7;
            this->historial[7]=n8;
            this->historial[8]=n9;
        };
        ~Navegador(){}
        string getHistorial(){
            string print;
            for(int i = 0; i < 10; i ++ ){
                std::string s = std::to_string(i+1);
                print.append(s).append(") ").append(historial[i]+"\n");
        }
        return print;
        };
        void setPagina(string pagina){
            string aux = historial[9];
            for(int i = 9;i>=0;i--){
                historial[i] = historial[i-1];
            }
            historial[0]=pagina;
        };
        vector<Usuario*> getListaDeUsuariosDelPrograma(){
            return this -> userList;
        };
};