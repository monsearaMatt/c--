#pragma once
#include <string>
#include <iostream>
#include "Software.h"
using namespace std;
class Social:public Software{
    //Atributos del software social
    private:
    vector<Usuario> amigos;
    
    //Metodos del software social
    public:
    Social(string,string,string,int);
    ~Social();
    vector<Usuario> getAmigos();
};
//constructor
Social::Social(string nombre,string developer,string clasificacionEdad,int precio):Software(nombre,developer,clasificacionEdad,precio){
   
}
//destructor
Social::~Social(){
    
}
vector<Usuario> Social::getAmigos(){
    return this->amigos;
}