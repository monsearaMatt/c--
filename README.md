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
    //5 softwares de ofimatica
    Ofimatica* of1=new Ofimatica("Excel","Oficce","Ofimatica",0,2000,3);
    Ofimatica* of2=new Ofimatica("PowerPoint","Oficce","Ofimatica",0,5000,5);
    Ofimatica* of3=new Ofimatica("OneNote","Oficce","Ofimatica",0,10000,1);
    Ofimatica* of4=new Ofimatica("Word","Oficce","Ofimatica",0,2000,4);
    Ofimatica* of5=new Ofimatica("Acces","Oficce","Ofimatica",0,1000,7);
    //4 software de produccion
    Produccion* p1= new Produccion("Adobe Premiere Pro","Adobe","Produccion",18,8000,"Video");
    Produccion* p2= new Produccion("Avid Media Composer","Avid Technology","Produccion",18,5000,"Video");
    Produccion* p3= new Produccion("Pro Tools","Digidesign","Produccion",18,12000,"grabacion");
    Produccion* p4= new Produccion("Autodesk Maya","Autodesk","Produccion",18,8000,"Modelado 3D");
    //2 navegadores
    Navegador* nav1= new Navegador("Brave","Brave Software","Navegador", 0,0,"MichaelJackson.com","EinsteinGenius.com","MarilynIcon.com","ElvisLegend.net","DaVinciMasterpiece.org","OprahInspire.com","NelsonFreedom.net","CharlieChaplinLegacy.com","AudreyHollywood.com","WinstonLeader.org");
    Navegador* nav2= new Navegador("Microsoft Edge","Microsoft Software","Navegador", 0,0,"MickeyMouseMagic.com","SpongeBobAdventures.com","ElsaFrozenWorld.net","SimbaLionKingPride.org","BugsBunnyLaughs.com","PikachuElectricPower.biz","HomerSimpsonDoh.co","DoraExplorerQuests.us","ArielMermaidWonders.tv","WoodyToyStoryAdventure.mobi");
    // 6 softwares de seguridad(1 de cada tipo)
    Seguridad* seg1= new Seguridad("Microsoft Defender","Microsoft ","Seguridad", 18,4000,seguridadGeneros[0]);
    Seguridad* seg2= new Seguridad("Norton","NortonLifeLock ","Seguridad", 18,5000,seguridadGeneros[1]);
    Seguridad* seg3= new Seguridad("McAfee","McAfee ","Seguridad", 18,2000,seguridadGeneros[2]);
    Seguridad* seg4= new Seguridad("Kaspersky","Kaspersky  ","Seguridad", 18,6000,seguridadGeneros[3]);
    Seguridad* seg5= new Seguridad("Bitdefender","Bitdefender ","Seguridad", 18,4000,seguridadGeneros[4]);
    Seguridad* seg6= new Seguridad("Avast","Avast","Seguridad", 18,9000,seguridadGeneros[5]);
    //minimo 2 software social
    Social* so1= new Social("Facebook", "mark","Social", 18,0);
    Social* so2= new Social("furby boom", "el demonio","Social", 0,0);# c--
