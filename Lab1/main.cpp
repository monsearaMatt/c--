#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "Administrador.h"
#include "Nino.h"
#include "Normal.h"
#include "Software.h"
#include "Usuario.h"
#include "Juego.h"
#include "Ofimatica.h"
#include "Produccion.h"
#include "Navegador.h"
#include "Seguridad.h"
#include "Social.h"

using namespace std;
Usuario* login(vector<Usuario*> u){
    string nombre;
    string contraseña;
    cout<<"**********Login**********\n";
    while(true){
        cout<<"Usuario: ";
        cin>> nombre;
        for(int i=0;i<u.size();i++){
            if(u[i]->getNombre()==nombre){
                while(true){
                    cout<<"Contrasena: ";
                    cin>> contraseña;
                    if(u[i]->getPassword()==contraseña){
                        return u[i];
                    }
                    cout<<"\nContrasena incorrecta\n";
                }
            }
        }
        cout<<"\nUsuario incorrecto\n";
    }
    cout<<"";
    return NULL;
}

static void menu(vector<Usuario*> Usuarios,vector<Software*> Softwares,Usuario* u){
    string option;
    while(option!="5"){
        cout<<"******Menu********\n1. Descargar software\n2. Softwares Descargados\n3. Cambiar Datos\n4. Desinstalar Software\n5. Salir\n*************\nOpcion: ";
        cin>>option;
        while(option!="1" and option!="2" and option!="3" and option!="4" and option!="5"){
            cout<<"Error, dato invalido\nOpcion: ";
            cin>>option;
        }
        //Descargar software
        if(option=="1"){
            //Mostrar todos los softwares
            for(int i=0;i<Softwares.size();i++){
                Juego* j=dynamic_cast<Juego*>(Softwares[i]);
                Navegador* na= dynamic_cast<Navegador*>(Softwares[i]);
                Ofimatica* of=dynamic_cast<Ofimatica*>(Softwares[i]);
                Produccion* pro= dynamic_cast<Produccion*>(Softwares[i]);
                Seguridad* seg= dynamic_cast<Seguridad*>(Softwares[i]);
                Social* so= dynamic_cast<Social*>(Softwares[i]);
                if(j){
                    cout<<"Juego: "+Softwares[i]->getNombre() + "->" + Softwares[i]->getClasificacion()+"\n";
                }else if(na){
                    cout<<"Navegador: "+Softwares[i]->getNombre() + "->" + Softwares[i]->getClasificacion()+"\n";
                }else if(of){
                    cout<<"Ofimatica: "+Softwares[i]->getNombre() + "->" + Softwares[i]->getClasificacion()+"\n";
                }else if(pro){
                    cout<<"Produccion: "+Softwares[i]->getNombre() + "->" + Softwares[i]->getClasificacion()+"\n";
                }else if(seg){
                    cout<<"Seguridad: "+Softwares[i]->getNombre() + "->" + Softwares[i]->getClasificacion()+"\n";
                }else if(so){
                    cout<<"Social: "+Softwares[i]->getNombre() + "->" + Softwares[i]->getClasificacion()+"\n";
                }
            }

            //Elegir cual de los softwares mostrados agregar al usuario
            string soft;
            cout<<"Software: ";
            cin>>soft;
            Administrador* a= dynamic_cast<Administrador*>(u);
            Nino* n= dynamic_cast<Nino*>(u);
            for(int i=0;i<Softwares.size();i++){
                if(Softwares[i]->getNombre()==soft){
                    Seguridad* segu= dynamic_cast<Seguridad*>(Softwares[i]);
                    if(segu and !a){
                        cout<<"No puedes agregar este software porque no eres administrador\n";
                    }else if(n and Softwares[i]->getClasificacion()!="+18"){
                        cout<<"No tienes la edad suficiente\n";
                    }else{
                        u->agregarSoftware(Softwares[i]);
                    }
                    break; 
                }
            }
            

        //Softwares descargados 
        }else if(option=="2"){
            for(int i=0;i<u->getSoftwares().size();i++){
                Juego* j=dynamic_cast<Juego*>(u->getSoftwares()[i]);
                Navegador* na= dynamic_cast<Navegador*>(u->getSoftwares()[i]);
                Ofimatica* of=dynamic_cast<Ofimatica*>(u->getSoftwares()[i]);
                Produccion* pro= dynamic_cast<Produccion*>(u->getSoftwares()[i]);
                Seguridad* seg= dynamic_cast<Seguridad*>(u->getSoftwares()[i]);
                Social* so= dynamic_cast<Social*>(u->getSoftwares()[i]);
                if(j){
                    cout<<"Juego: "+u->getSoftwares()[i]->getNombre() + "->" + u->getSoftwares()[i]->getClasificacion()+"\n";
                } else if(na){
                    cout<<"Navegador: "+u->getSoftwares()[i]->getNombre() + "->" + u->getSoftwares()[i]->getClasificacion()+"\n";
                } else if(of){
                    cout<<"Ofimatica: "+u->getSoftwares()[i]->getNombre() + "->" + u->getSoftwares()[i]->getClasificacion()+"\n";
                } else if(pro){
                    cout<<"Produccion: "+u->getSoftwares()[i]->getNombre() + "->" + u->getSoftwares()[i]->getClasificacion()+"\n";
                } else if(seg){
                    cout<<"Seguridad: "+u->getSoftwares()[i]->getNombre() + "->" + u->getSoftwares()[i]->getClasificacion()+"\n";
                } else if(so){
                    cout<<"Social: "+u->getSoftwares()[i]->getNombre() + "->" + u->getSoftwares()[i]->getClasificacion()+"\n";
                }


            }

        //cambiar datos
        }else if(option=="3"){
            cout<<"************Cambiar datos*************\n";
            Administrador* ad= dynamic_cast<Administrador*>(u);
            Nino* ni= dynamic_cast<Nino*>(u);
            Normal* norm= dynamic_cast<Normal*>(u);
            string seteo;
            string name;
            string clave;
            int edad;
            string correo;
            bool puede=true;
            //Modificar datos de administrador
            if(ad){
                cout<<"1. Nombre\n2. clave\n3. Edad\n4. Correo\n5. volver\nOpcion: ";
                cin>>seteo;
                while(seteo!="1" and seteo!="2" and seteo!="3" and seteo!="4" and seteo!="5"){
                    cout<<"Error, dato invalido\nIngresa otra opcion: ";
                    cin>>seteo;
                }
                //Cambiar nombre de un administrador
                if(seteo=="1"){
                    cout<<"****Nombre*****\nNuevo nombre: ";
                    cin>>name;
                    if(u->getNombre()==name){
                        cout<<"El nombre se mantiene\n";
                    }else{
                        for(int i=0;i<Usuarios.size();i++){
                            if(Usuarios[i]->getNombre()==name){
                                puede=false;
                            }
                        }
                    }
                    if(puede==true){
                        u->setNombre(name);
                    }
                //Cambiar clave del administrador
                } else if(seteo=="2"){
                    cout<<"*****Clave*****\nNueva Clave: ";
                    cin>>clave;
                    u->setpassword(clave);
                //Cambiar edad
                } else if(seteo=="3"){
                    cout<<"*****Edad******\nNueva Edad: ";
                    cin>>edad;
                    while(edad<=0){
                        cout<<"Error, edad invalida\nNueva Edad: ";
                        cin>>edad;
                    }
                    u->setEdad(edad);
                //Cambiar Correo
                } else if(seteo=="4"){
                    cout<<"********Correo********\nNuevo Correo: ";
                    cin>>correo;
                    ad->setCorreo(correo);
                }

            //Modificar datos de un niño
            }else if(ni){
                cout<<"1. Nombre\n2. clave\n3. Edad\n4. volver\nOpcion: ";
                cin>>seteo;
                while(seteo!="1" and seteo!="2" and seteo!="3" and seteo!="4"){
                    cout<<"Error, dato invalido\nIngresa otra opcion: ";
                    cin>>seteo;
                }
                //Cambiar nombre del niño
                if(seteo=="1"){
                    cout<<"****Nombre*****\nNuevo nombre: ";
                    cin>>name;
                    if(u->getNombre()==name){
                        cout<<"El nombre se mantiene\n";
                    }else{
                        for(int i=0;i<Usuarios.size();i++){
                            if(Usuarios[i]->getNombre()==name){
                                puede=false;
                            }
                        }
                    }
                    if(puede==true){
                        u->setNombre(name);
                    }
                //Cambiar clave del niño
                }else if(seteo=="2"){
                    cout<<"*****Clave*****\nNueva Clave: ";
                    cin>>clave;
                    u->setpassword(clave);
                //Cambiar edad del niño
                }else if(seteo=="3"){
                    cout<<"*****Edad******\nNueva Edad: ";
                    cin>>edad;
                    while(edad<=0 and edad>=18){
                        cout<<"Error, edad invalida\nNueva Edad: ";
                        cin>>edad;
                    }
                    u->setEdad(edad);
                }
            //Modificar datos de un usuario normal
            }else if(norm){
                cout<<"1. Nombre\n2. clave\n3. Edad\n4. Correo\n5. volver\nOpcion: ";
                cin>>seteo;
                while(seteo!="1" and seteo!="2" and seteo!="3" and seteo!="4" and seteo!="5"){
                    cout<<"Error, dato invalido\nIngresa otra opcion: ";
                    cin>>seteo;
                }
                //Cambiar nombre de un Usuario normal
                if(seteo=="1"){
                    cout<<"****Nombre*****\nNuevo nombre: ";
                    cin>>name;
                    if(u->getNombre()==name){
                        cout<<"El nombre se mantiene\n";
                    }else{
                        for(int i=0;i<Usuarios.size();i++){
                            if(Usuarios[i]->getNombre()==name){
                                puede=false;
                            }
                        }
                    }
                    if(puede==true){
                        u->setNombre(name);
                    }
                //Cambiar clave del Normal
                } else if(seteo=="2"){
                    cout<<"*****Clave*****\nNueva Clave: ";
                    cin>>clave;
                    u->setpassword(clave);
                //Cambiar edad del normal
                } else if(seteo=="3"){
                    cout<<"*****Edad******\nNueva Edad: ";
                    cin>>edad;
                    while(edad<18){
                        cout<<"Error, edad invalida\nNueva Edad: ";
                        cin>>edad;
                    }
                    u->setEdad(edad);
                //Cambiar Correo
                } else if(seteo=="4"){
                    cout<<"********Correo********\nNuevo Correo: ";
                    cin>>correo;
                    norm->setCorreo(correo);
                }
            }

        //desinstalar software
        }else if(option=="4"){
            string cambio;
            cout<<"******Desinstalar Software*******\nNombre del software: ";
            cin>>cambio;
            u->desinstalarSoftware(cambio);
            

        }
    }

}



int main(){
    vector<Usuario*> listaUsuarios;
    vector<Software*> listaSoftware;
    string juegosGeneros[10]={"FPS", "MMO", "PUZZLE", "RPG", "MUNDO ABIERTO", "SHUTER", "CARRERA", "BATLE ROYAL", "MOBA", "RETRO"};
    string seguridadGeneros[6]={"Ransomware","Spyware","Botnets","rootKits","Gusanos","troyanos"};
    //minimo15 usuarios(1 administrador, 4 Niños, 10 Normales)
    //1 administrador
    Usuario* admin= new Administrador("cristian","estructura",20,"cristian.nunez@alumnos.ucn.cl");
    listaUsuarios.push_back(admin);
    //las funciones en el main tienen que estar antes del main
    //4 niños
    Usuario* n1= new Nino("Carlos","ucn",8);
    Usuario* n2= new Nino("Eduardo","perro",12);
    Usuario* n3= new Nino("vicente","patada",15);
    Usuario* n4= new Nino("sossa","derrape",10);
    listaUsuarios.push_back(n1);
    listaUsuarios.push_back(n2);
    listaUsuarios.push_back(n3);
    listaUsuarios.push_back(n4);
    //10 usuarios normales
    Usuario* normal1= new Normal("Maxi","simpson",21,"Maximpson@gmail.com");
    Usuario* normal2= new Normal("Juan","JuaN123!",30,"juan.perez@email.com");
    Usuario* normal3= new Normal("Maria","Mari@456",28,"maria.rodriguez@email.com");
    Usuario* normal4= new Normal("Carlos","C@rlos789",35,"carlos.gonzalez@email.com");
    Usuario* normal5= new Normal("Laura","L4ura#987",25,"laura.martinez@email.com");
    Usuario* normal6= new Normal("Alejandro","Al3jandr0*",32,"alejandro.lopez@email.com");
    Usuario* normal7= new Normal("Ana","An@2023",27,"ana.sanchez@email.com");
    Usuario* normal8= new Normal("Sergio ","S3rgi0P@ss",40,"sergio.torres@email.com");
    Usuario* normal9= new Normal("Andrea ","A#ndrea567",29,"andrea.ramirez@email.com");
    Usuario* normal10= new Normal("David ","D@vid1234",33,"david.rodriguez@email.com");
    listaUsuarios.push_back(normal1);
    listaUsuarios.push_back(normal2);
    listaUsuarios.push_back(normal3);
    listaUsuarios.push_back(normal4);
    listaUsuarios.push_back(normal5);
    listaUsuarios.push_back(normal6);
    listaUsuarios.push_back(normal7);
    listaUsuarios.push_back(normal8);
    listaUsuarios.push_back(normal9);
    listaUsuarios.push_back(normal10);
    //20 juegos(2 de cada genero y minimo 5 para +18) 
    //Juego(string nombre,string developer,string clasificacionEdad,int precio,string genero)
    Software* juego1=new Juego("Minecraft","notch","+18",18000,juegosGeneros[0]);
    Software* juego2=new Juego("CyberSprint","Quantum","todas las edades",20000,juegosGeneros[0]);
    Software* juego3=new Juego("Galactic","Starforge","todas las edades",15000,juegosGeneros[1]);
    Software* juego4=new Juego("Mystic","Enchanted Realms Games","+18",12000,juegosGeneros[1]);
    Software* juego5=new Juego("Ninja","Shadowstrike Studios","todas las edades",1000,juegosGeneros[2]);
    Software* juego6=new Juego("Abyssal","Deepwater","todas las edades",30000,juegosGeneros[2]);
    Software* juego7=new Juego("Timebenders","Temporal Nexus Games","todas las edades",19000,juegosGeneros[3]);
    Software* juego8=new Juego("Pixels","RetroRevive Creations","todas las edades",18000,juegosGeneros[3]);
    Software* juego9=new Juego("Elemental","Elemental Forge","todas las edades",5000,juegosGeneros[4]);
    Software* juego10=new Juego("Skyborne","Cloudreach","todas las edades",18000,juegosGeneros[4]);
    Software* juego11=new Juego("Forgotten","Lost Lore","todas las edades",18000,juegosGeneros[5]);
    Software* juego12=new Juego("MechWarriors","MechTech","+18",25000,juegosGeneros[5]);
    Software* juego13=new Juego("Dreamscape","Lucid Dreams","todas las edades",58000,juegosGeneros[6]);
    Software* juego14=new Juego("Steampunk","Gearworks","todas las edades",13000,juegosGeneros[6]);
    Software* juego15=new Juego("Shadowrunners","Midnight Syndicate","todas las edades",14000,juegosGeneros[7]);
    Software* juego16=new Juego("Arcane","Mysticalchemy","+18",16000,juegosGeneros[7]);
    Software* juego17=new Juego("Abyss","Abyssal Dominion Games","todas las edades",18000,juegosGeneros[8]);
    Software* juego18=new Juego("BioTech","Genetix Innovations","todas las edades",8000,juegosGeneros[8]);
    Software* juego19=new Juego("Drakoria","Dragonforge","todas las edades",10000,juegosGeneros[9]);
    Software* juego20=new Juego("Alien","Extraterrestrial Games","+18",180000,juegosGeneros[9]);
    listaSoftware.push_back(juego1);
    listaSoftware.push_back(juego2);
    listaSoftware.push_back(juego3);
    listaSoftware.push_back(juego4);
    listaSoftware.push_back(juego5);
    listaSoftware.push_back(juego6);
    listaSoftware.push_back(juego7);
    listaSoftware.push_back(juego8);
    listaSoftware.push_back(juego9);
    listaSoftware.push_back(juego10);
    listaSoftware.push_back(juego11);
    listaSoftware.push_back(juego12);
    listaSoftware.push_back(juego13);
    listaSoftware.push_back(juego14);
    listaSoftware.push_back(juego15);
    listaSoftware.push_back(juego16);
    listaSoftware.push_back(juego17);
    listaSoftware.push_back(juego18);
    listaSoftware.push_back(juego19);
    listaSoftware.push_back(juego20);
    //Minimo 5 softwares de ofimatica
    //Ofimatica(string nombre,string developer,string clasificacionEdad,int precio,int cantArchivos)
    Software* of1=new Ofimatica("Excel","Oficce","todas las edades",2000,3);
    Software* of2=new Ofimatica("PowerPoint","Oficce","todas las edades",5000,5);
    Software* of3=new Ofimatica("OneNote","Oficce","todas las edades",10000,1);
    Software* of4=new Ofimatica("Word","Oficce","todas las edades",2000,4);
    Software* of5=new Ofimatica("Acces","Oficce","todas las edades",1000,7);
    listaSoftware.push_back(of1);
    listaSoftware.push_back(of2);
    listaSoftware.push_back(of3);
    listaSoftware.push_back(of4);
    listaSoftware.push_back(of5);
    //Minimo 4 software de produccion
    //Produccion(string nombre,string developer,string clasificacionEdad,int precio,string tipoSolucion)
    Software* p1= new Produccion("Adobe","Adobe","+18",8000,"Video");
    Software* p2= new Produccion("Avid","Avid Technology","+18",5000,"Video");
    Software* p3= new Produccion("ProTools","Digidesign","+18",12000,"grabacion");
    Software* p4= new Produccion("Autodesk","Autodesk","+18",8000,"Modelado 3D");
    listaSoftware.push_back(p1);
    listaSoftware.push_back(p2);
    listaSoftware.push_back(p3);
    listaSoftware.push_back(p4);
    //Minimo 2 navegadores
    //Navegador(string nombre,string developer,string clasificacionEdad,int precio,string n1,string n2,string n3,string n4,string n5,string n6,string n7,string n8,string n9,string n10)
    Software* nav1= new Navegador("Opera","Opera Software", "todas las edades",0,"Google","YouTube","Facebook","Amazon","Wikipedia","Twitter","Instagram","Netflix","LinkedIn","Yahoo");
    Software* nav2= new Navegador("Chrome","Google", "todas las edades",0,"YouTube","Facebook","Amazon","Google","Instagram","Wikipedia","Twitter","Netflix","LinkedIn","Yahoo");
    listaSoftware.push_back(nav1);
    listaSoftware.push_back(nav2);
     // 6 softwares de seguridad(1 de cada tipo)
    //Seguridad(string nombre,string developer,string clasificacionEdad,int precio,string tipoMalware)
    Software* seg1= new Seguridad("Defender","Microsoft ", "todas las edades",4000,seguridadGeneros[0]);
    Software* seg2= new Seguridad("Norton","NortonLifeLock ", "todas las edades",5000,seguridadGeneros[1]);
    Software* seg3= new Seguridad("McAfee","McAfee ", "todas las edades",2000,seguridadGeneros[2]);
    Software* seg4= new Seguridad("Kaspersky","Kaspersky  ", "todas las edades",6000,seguridadGeneros[3]);
    Software* seg5= new Seguridad("Bitdefender","Bitdefender ", "todas las edades",4000,seguridadGeneros[4]);
    Software* seg6= new Seguridad("Avast","Avast", "todas las edades",9000,seguridadGeneros[5]);
    listaSoftware.push_back(seg1);
    listaSoftware.push_back(seg2);
    listaSoftware.push_back(seg3);
    listaSoftware.push_back(seg4);
    listaSoftware.push_back(seg5);
    listaSoftware.push_back(seg6);

    //minimo 2 software social
    //Social(string nombre,string developer,string clasificacionEdad,int precio)
    Software* social1= new Social("Facebook", "mark", "todas las edades",0);
    Software* social2= new Social("Tinder", "yo", "+18",0);
    listaSoftware.push_back(social1);
    listaSoftware.push_back(social2);
    while(true){
        //Login
        Usuario* us=login(listaUsuarios);
        //Mostrar el menu
        menu(listaUsuarios,listaSoftware,us);
        string option;
        //relogin o salir por completo
        cout<<"*******Salir******\n1. Login\n2. Salir\nOpcion: ";
        cin>>option;
        //Control de errores
        while(option!="1" and option!="2"){
            cout<<"Error, dato invalido\nOpcion: ";
            cin>>option;
        }
        //salir por completo del programa
        if(option=="2"){
            break;
        }
    }
    return 0;
}