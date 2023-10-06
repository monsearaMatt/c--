#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
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
    string User;
    string Password;
    cout<<"-------------ingreso al sistema-------------\n";
    while(true){
        cout<<"User: ";
        cin>> User;
        for(int i=0;i<u.size();i++){
            if(u[i]->getNombre()==User){
                while(true){
                    cout<<"Password: ";
                    cin>> Password;
                    if(u[i]->getPassword()==Password){
                        return u[i];
                    }
                    cout<<"\nincorrect password\n";
                }
            }
        }
        cout<<"\nincorrect User\n";
    }
    cout<<"";
    return NULL;
}

string printList(vector<Software*> u){
    string printea;
    string tipo=u[0]->getTipo();

    for(int i =0;i<u.size();i++){
        if(tipo==u[i]->getTipo()){
            std::string s = std::to_string(i+1);
            string r = u[i]->getNombre();
            printea=printea+s+")"+r+"\n";
        }else if(tipo!=u[i]->getTipo()){
            tipo=u[i]->getTipo();
            printea=printea+tipo+"\n";
            std::string s = std::to_string(i+1);
            string r = u[i]->getNombre();
            printea=printea+s+")"+r+"\n";

    }
    }
    return printea;
}


static void menuAdmin(vector<Usuario*> Usuarios,vector<Software*> Softwares,Usuario* u){
    string option;
    while(option!="6"){
        cout<<"-----------Menu-----------\n1.Agregar software\n2.Softwares Descargados\n3.Cambiar Datos\n4.Eliminar Software del usuario\n5.Ingresar al software\n6.Salir\n-----------------------\nSeleccione una Opcion: ";
        cin>>option;
        while(option!="1" and option!="2" and option!="3" and option!="4" and option!="5"and option!="6"){
            cout<<"An error has occurred, the selected option was not found\nOptions ";
            cin>>option;
        }
        //Agregar software
        if(option=="1"){
            //Mostrar todos los softwares
            cout<<printList(Softwares);

            //Elegir cual de los softwares mostrados agregar al usuario
            string soft;
            cout<<"Software: ";
            cin>>soft;
            for(int i=0;i<Softwares.size();i++){
                if(Softwares[i]->getNombre()==soft){
                        //u->agregarSoftware(Softwares[i]);
                    break;
                }
            }
            
        //Softwares descargados 
        }else if(option=="2"){
            for(int i=0;i<u->getBiblioteca().size();i++){
                cout<<printList(u->getBiblioteca());
            }
        //cambiar datos
        }else if(option=="3"){
            cout<<"------------Cambiar datos------------\n";
            string opiropi;
            string name;
            string pasword;
            int edad;
            string correo;
            int puede=2;
            //Modificar datos de administrador
                cout<<"1. Nombre\n2. clave\n3. Edad\n4. Correo\n5. volver\nOpcion: ";
                cin>>opiropi;
                while(opiropi!="1" and opiropi!="2" and opiropi!="3" and opiropi!="4" and opiropi!="5"){
                    cout<<"An error has occurred, the selected option was not found\nIngresa otra opcion: ";
                    cin>>opiropi;
                }
                //Cambiar nombre de un administrador
                if(opiropi=="1"){
                    cout<<"----------User name----------\nNew User name: ";
                    cin>>name;
                    if(u->getNombre()==name){
                        cout<<"El User name se mantiene es el mismo\n";
                    }else{
                        for(int i=0;i<Usuarios.size();i++){
                            if(Usuarios[i]->getNombre()==name){
                                puede=0;
                                cout<<"No se pudo cambiar el nombre porque ya existe en la lista de usuarios";
                            }
                        }
                    }
                    if(puede==2){
                        u->setNombre(name);
                    }
                //Cambiar clave del administrador
                } else if(opiropi=="2"){
                    cout<<"----------Clave----------\nNew Password ";
                    cin>>pasword;
                    u->setPassword(pasword);
                //Cambiar edad
                } else if(opiropi=="3"){
                    cout<<"----------Edad-----------\nNew Age";
                    cin>>edad;
                    while(edad<=0){
                        cout<<"An error has occurred, invalid age\nNueva Edad: ";
                        cin>>edad;
                    }
                    u->setEdad(edad);
                //Cambiar Correo
                } else if(opiropi=="4"){
                    cout<<"-----------Correo-----------\nNuevo Correo (ingresando el codigo de dominio ejemplo @gmail.com o @hotmail.com): ";
                    cin>>correo;
                    u->setCorreo(correo);
                }
        //desinstalar software
        }else if(option=="4"){
            string cambio;
            cout<<"-----------Quitar Software del usuario-----------\nName software: ";
            cin>>cambio;
            //u->desinstalarSoftware(cambio);
            

        }else if(option=="5"){
            cout<<printList(u->getBiblioteca());
            string eleccion;
            

        }

    }

}


int main(){
    vector<Usuario*> listaUsuarios;
    vector<Software*> listaSoftware;
    string juegosGeneros[10]={"FPS", "MMO", "PUZZLE", "RPG", "MUNDO ABIERTO", "SHUTER", "CARRERA", "BATLE ROYAL", "MMORPG", "SIN INTERNET"};
    string seguridadGeneros[6]={"Ransomware","Spyware","Botnets","rootKits","Gusanos","troyanos"};
    //15 usuarios(1 administrador, 4 Niños, 10 Normales)
    //el admin
    Usuario* admin= new Usuario("almendra","1234",20,"mueroYrevivo@gmail.com",2);
    listaUsuarios.push_back(admin);
    //los niños
    Usuario* n1= new Usuario("carlos","cojo",8,"",0);
    Usuario* n2= new Usuario("perro","rar",12,"",0);
    Usuario* n3= new Usuario("maxuca","karate",15,"",0);
    Usuario* n4= new Usuario("seba","score",10,"",0);
    listaUsuarios.push_back(n1);
    listaUsuarios.push_back(n2);
    listaUsuarios.push_back(n3);
    listaUsuarios.push_back(n4);
    //10 usuarios normales
    Usuario* normal1= new Usuario("Dragón","rojo",35,"Dragón.rojo@gmail.com",0);
    Usuario* normal2= new Usuario("Minotauro","marrón",50,"Minotauro.marrón@gmail.com",0);
    Usuario* normal3= new Usuario("Sirena","azul",42,"Sirena.azul@gmail.com",0);
    Usuario* normal4= new Usuario("Unicornio","blanco",73,"Unicornio.blanco@gmail.com",0);
    Usuario* normal5= new Usuario("Fénix","dorado",60,"Fénix.dorado@gmail.com",0);
    Usuario* normal6= new Usuario("Kraken","negro",27,"Kraken.negro@gmail.com",0);
    Usuario* normal7= new Usuario("Quimera","verde",65,"Quimera.verde@gmail.com",0);
    Usuario* normal8= new Usuario("Harpía","plata",55,"Harpía.plata@gmail.com",0);
    Usuario* normal9= new Usuario("Esfinge","rosa",40,"Esfinge.rosa@gmail.com",0);
    Usuario* normal10= new Usuario("Centauro","gris",78,"Centauro.gris@gmail.com",0);
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
    //20 juegos(2 de cada genero y minimo 5 para +18) 4 y 6 son generos mas 18 y mi dragon mistico
    Juego* juego1= new Juego("Dragón Místico","MythoGames","juego",18,19990,juegosGeneros[1]);
    Juego* juego2=new Juego("Laberinto Minotauro","Fantasy Studios","juego",12,24990,juegosGeneros[2]);
    Juego* juego3=new Juego("Simulador de Sirenas","OceanGames","juego",8,15990,juegosGeneros[3]);
    Juego* juego4=new Juego("Unicornio Encantado","Magic World","juego",18,9990,juegosGeneros[4]);
    Juego* juego5=new Juego("Fénix Renacido","FireBreath Games","juego",14,29990,juegosGeneros[5]);
    Juego* juego6=new Juego("Aventuras Kraken","SeaQuest Inc.","juego",18,34990,juegosGeneros[6]);
    Juego* juego7=new Juego("Batalla de Centauros","Mythical Battles","juego",12,24990,juegosGeneros[7]);
    Juego* juego8=new Juego("Harpía en el Cielo","Mythology Adventures","juego",10,19990,juegosGeneros[8]);
    Juego* juego9=new Juego("Medusa's Revenge","StoneCold Studios","juego",16,34990,juegosGeneros[9]);
    Juego* juego10=new Juego("Desafío de Quimeras","Legendary Games","juego",14,29990,juegosGeneros[10]);
    Juego* juego11=new Juego("Dragón Místico","MythoGames","juego",10,19990,juegosGeneros[1]);
    Juego* juego12=new Juego("Laberinto Minotauro","Fantasy Studios","juego",12,24990,juegosGeneros[2]);
    Juego* juego13=new Juego("Simulador de Sirenas","OceanGames","juego",8,15990,juegosGeneros[3]);
    Juego* juego14=new Juego("Unicornio Encantado","Magic World","juego",18,9990,juegosGeneros[4]);
    Juego* juego15=new Juego("Fénix Renacido","FireBreath Games","juego",14,29990,juegosGeneros[5]);
    Juego* juego16=new Juego("Aventuras Kraken","SeaQuest Inc.","juego",18,34990,juegosGeneros[6]);
    Juego* juego17=new Juego("Batalla de Centauros","Mythical Battles","juego",12,24990,juegosGeneros[7]);
    Juego* juego18=new Juego("Harpía en el Cielo","Mythology Adventures","juego",10,19990,juegosGeneros[8]);
    Juego* juego19=new Juego("Medusa's Revenge","StoneCold Studios","juego",16,34990,juegosGeneros[9]);
    Juego* juego20=new Juego("Desafío de Quimeras","Legendary Games","juego",14,29990,juegosGeneros[10]);
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
    //5 softwares de ofimatica
    Ofimatica* of1=new Ofimatica("Excel","Oficce","Ofimatica",0,2000,3);
    Ofimatica* of2=new Ofimatica("PowerPoint","Oficce","Ofimatica",0,5000,5);
    Ofimatica* of3=new Ofimatica("OneNote","Oficce","Ofimatica",0,10000,1);
    Ofimatica* of4=new Ofimatica("Word","Oficce","Ofimatica",0,2000,4);
    Ofimatica* of5=new Ofimatica("Acces","Oficce","Ofimatica",0,1000,7);
    listaSoftware.push_back(of1);
    listaSoftware.push_back(of2);
    listaSoftware.push_back(of3);
    listaSoftware.push_back(of4);
    listaSoftware.push_back(of5);
    //4 software de produccion
    Produccion* p1= new Produccion("Adobe Premiere Pro","Adobe","Produccion",18,8000,"Video");
    Produccion* p2= new Produccion("Avid Media Composer","Avid Technology","Produccion",18,5000,"Video");
    Produccion* p3= new Produccion("Pro Tools","Digidesign","Produccion",18,12000,"grabacion");
    Produccion* p4= new Produccion("Autodesk Maya","Autodesk","Produccion",18,8000,"Modelado 3D");
    listaSoftware.push_back(p1);
    listaSoftware.push_back(p2);
    listaSoftware.push_back(p3);
    listaSoftware.push_back(p4);
    //2 navegadores
    Navegador* nav1= new Navegador("Brave","Brave Software","Navegador", 0,0,"MichaelJackson.com","EinsteinGenius.com","MarilynIcon.com","ElvisLegend.net","DaVinciMasterpiece.org","OprahInspire.com","NelsonFreedom.net","CharlieChaplinLegacy.com","AudreyHollywood.com","WinstonLeader.org");
    Navegador* nav2= new Navegador("Microsoft Edge","Microsoft Software","Navegador", 0,0,"MickeyMouseMagic.com","SpongeBobAdventures.com","ElsaFrozenWorld.net","SimbaLionKingPride.org","BugsBunnyLaughs.com","PikachuElectricPower.biz","HomerSimpsonDoh.co","DoraExplorerQuests.us","ArielMermaidWonders.tv","WoodyToyStoryAdventure.mobi");
    listaSoftware.push_back(nav1);
    listaSoftware.push_back(nav2);
    // 6 softwares de seguridad(1 de cada tipo)
    Seguridad* seg1= new Seguridad("Microsoft Defender","Microsoft ","Seguridad", 18,4000,seguridadGeneros[0]);
    Seguridad* seg2= new Seguridad("Norton","NortonLifeLock ","Seguridad", 18,5000,seguridadGeneros[1]);
    Seguridad* seg3= new Seguridad("McAfee","McAfee ","Seguridad", 18,2000,seguridadGeneros[2]);
    Seguridad* seg4= new Seguridad("Kaspersky","Kaspersky  ","Seguridad", 18,6000,seguridadGeneros[3]);
    Seguridad* seg5= new Seguridad("Bitdefender","Bitdefender ","Seguridad", 18,4000,seguridadGeneros[4]);
    Seguridad* seg6= new Seguridad("Avast","Avast","Seguridad", 18,9000,seguridadGeneros[5]);
    listaSoftware.push_back(seg1);
    listaSoftware.push_back(seg2);
    listaSoftware.push_back(seg3);
    listaSoftware.push_back(seg4);
    listaSoftware.push_back(seg5);
    listaSoftware.push_back(seg6);
    //minimo 2 software social
    Social* so1= new Social("Facebook", "mark","Social", 18,0);
    Social* so2= new Social("furby boom", "el demonio","Social", 0,0);
    listaSoftware.push_back(so1);
    listaSoftware.push_back(so2);
    while(true){
        //Login
        Usuario* user=login(listaUsuarios);
        //Mostrar el menu
        menuAdmin(listaUsuarios,listaSoftware,user);
        
        string option;
        //relogin o salir por completo
        cout<<"-------Salir-------\n1)Login\n2)Salir\nOpcion: ";
        cin>>option;
        //salir por completo del programa
        if(option=="2"){
            break;
        }
        if(option!="2"&&option!="1"){
            cout<<"An error has occurred, the selected option was not found\nIngresa otra opcion:";
            }
        }
        return 0;
    };
    
    
