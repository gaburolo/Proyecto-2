#ifndef PRUEBAS22_MAPA
#define PRUEBAS22_MAPA



#include <iostream>

#include "AtackWindow.cpp"

#include "ListaSimple.h"
#include "Sprite.cpp"

#include <SFML/Graphics.hpp>

class mapa {
public:
    Sprite vacio = Sprite("vacio", 'N', 0, 0);
    Lista<Sprite> *listaY = new Lista<Sprite>[15];
    Lista<Sprite> Soldados;
    int nivel=1;
    int nSol=0;
private:
    AtackWindow atackWindow;

    int con = 0;

    Lista<Sprite> listaX;
    Lista<Sprite> listaX2;
    Lista<Sprite> listaX3;
    Lista<Sprite> listaX4;
    Lista<Sprite> listaX5;
    Lista<Sprite> listaX6;
    Lista<Sprite> listaX7;
    Lista<Sprite> listaX8;
    Lista<Sprite> listaX9;
    Lista<Sprite> listaX10;
    Lista<Sprite> listaX11;
    Lista<Sprite> listaX12;
    Lista<Sprite> listaX13;
    Lista<Sprite> listaX14;
    Lista<Sprite> listaX15;


    Lista<Sprite> Enemigos;
    Lista<Sprite> Enemigos2;
    Lista<Sprite> Enemigos3;
    Lista<Sprite> Enemigos4;
    Lista<Sprite> Enemigos5;
    Lista<Sprite> Enemigos6;

    Lista<Sprite> *EnemigosT = new Lista<Sprite>[6];


    Sprite obstaculo=Sprite("arbol",'N',0,0);


    //CAmbiar aqui
    Sprite s1=Sprite("soldado",'d',2,3);
    Sprite s2=Sprite("soldado",'d',1,3);
    Sprite s3=Sprite("soldado",'d',0,3);
    Sprite s4=Sprite("soldado",'d',3,2);
    Sprite s5=Sprite("soldado",'v',2,2);
    Sprite s6=Sprite("soldado",'v',1,2);
    Sprite s7=Sprite("soldado",'v',0,2);
    Sprite s8=Sprite("soldado",'v',3,1);
    Sprite s9=Sprite("soldado",'v',2,1);
    Sprite s10=Sprite("soldado",'x',1,1);

    Sprite s11=Sprite("soldado",'x',0,1);
    Sprite s12=Sprite("soldado",'x',3,0);
    Sprite s13=Sprite("soldado",'x',2,0);
    Sprite s14=Sprite("soldado",'x',1,0);
    Sprite s15=Sprite("soldado",'d',0,0);

    Sprite ene1=Sprite("Enemigo",'n',0,1);
    Sprite ene2=Sprite("Enemigo",'n',1,0);
    Sprite ene3=Sprite("Enemigo",'n',7,2);
    Sprite ene4=Sprite("Enemigo",'n',7,1);
    Sprite ene5=Sprite("Enemigo",'n',7,0);
    Sprite ene6=Sprite("Enemigo",'n',7,1);
    Sprite ene7=Sprite("Enemigo",'n',7,2);
    Sprite ene8=Sprite("Enemigo",'n',7,1);
    Sprite ene9=Sprite("Enemigo",'n',7,0);
    Sprite ene10=Sprite("Enemigo",'n',7,1);
    Sprite ene11=Sprite("Enemigo",'n',7,2);
    Sprite ene12=Sprite("Enemigo",'n',7,1);
    Sprite ene13=Sprite("Enemigo",'n',7,0);
    Sprite ene14=Sprite("Enemigo",'n',7,1);
    Sprite ene15=Sprite("Enemigo",'n',7,2);
    Sprite ene16=Sprite("Enemigo",'n',7,1);
    Sprite ene17=Sprite("Enemigo",'n',7,0);
    Sprite ene18=Sprite("Enemigo",'n',7,1);
    Sprite ene19=Sprite("Enemigo",'n',7,2);
    Sprite ene20=Sprite("Enemigo",'n',7,1);
public:
    mapa(){
        crearLista();

        insertarSoldados();
        insertarEnemigos();
        agregarSprites();
        agregarSpritesE();
        colocarObstaculos();
        actualizarXY();
    }

    void reinicio(){

        s1=Sprite("soldado",'d',2,3);
        s2=Sprite("soldado",'d',1,3);
        s3=Sprite("soldado",'d',0,3);
        s4=Sprite("soldado",'d',3,2);
        s5=Sprite("soldado",'v',2,2);
        s6=Sprite("soldado",'v',1,2);
        s7=Sprite("soldado",'v',0,2);
        s8=Sprite("soldado",'v',3,1);
        s9=Sprite("soldado",'v',2,1);
        s10=Sprite("soldado",'x',1,1);

        s11=Sprite("soldado",'x',0,1);
        s12=Sprite("soldado",'x',3,0);
        s13=Sprite("soldado",'x',2,0);
        s14=Sprite("soldado",'x',1,0);
        s15=Sprite("soldado",'d',0,0);

        Soldados.ChangeDataPos(s1,0);
        Soldados.ChangeDataPos(s2,1);
        Soldados.ChangeDataPos(s3,2);
        Soldados.ChangeDataPos(s4,3);
        Soldados.ChangeDataPos(s5,4);
        Soldados.ChangeDataPos(s6,5);
        Soldados.ChangeDataPos(s7,6);
        Soldados.ChangeDataPos(s8,7);
        Soldados.ChangeDataPos(s9,8);
        Soldados.ChangeDataPos(s10,9);
        Soldados.ChangeDataPos(s11,10);
        Soldados.ChangeDataPos(s12,11);
        Soldados.ChangeDataPos(s13,12);
        Soldados.ChangeDataPos(s14,13);
        Soldados.ChangeDataPos(s15,14);




        agregarSprites();
        agregarSpritesE();
        //agregarSpritesE();
        //colocarObstaculos();
        actualizarXY();
    }

private:
    void insertarEnemigos(){
        EnemigosT[0]=Enemigos;
        EnemigosT[1]=Enemigos2;
        EnemigosT[2]=Enemigos3;
        EnemigosT[3]=Enemigos4;
        EnemigosT[4]=Enemigos5;
        EnemigosT[5]=Enemigos6;

        for(int c=0;c<6;c++){
            EnemigosT[c].FinalInsert(ene1);
            EnemigosT[c].FinalInsert(ene2);
            EnemigosT[c].FinalInsert(ene3);
            EnemigosT[c].FinalInsert(ene4);
            EnemigosT[c].FinalInsert(ene5);
            EnemigosT[c].FinalInsert(ene6);
            EnemigosT[c].FinalInsert(ene7);
            EnemigosT[c].FinalInsert(ene8);
            EnemigosT[c].FinalInsert(ene9);
            EnemigosT[c].FinalInsert(ene10);
            EnemigosT[c].FinalInsert(ene11);
            EnemigosT[c].FinalInsert(ene12);
            EnemigosT[c].FinalInsert(ene13);
            EnemigosT[c].FinalInsert(ene14);
            EnemigosT[c].FinalInsert(ene15);
            EnemigosT[c].FinalInsert(ene16);
            EnemigosT[c].FinalInsert(ene17);
            EnemigosT[c].FinalInsert(ene18);
            EnemigosT[c].FinalInsert(ene19);
            EnemigosT[c].FinalInsert(ene20);

        }

    }
    void crearLista(){
        for(int i=0; i<15;i++){

            listaX.FinalInsert(vacio);
            listaX2.FinalInsert(vacio);
            listaX3.FinalInsert(vacio);
            listaX4.FinalInsert(vacio);
            listaX5.FinalInsert(vacio);
            listaX6.FinalInsert(vacio);
            listaX7.FinalInsert(vacio);
            listaX8.FinalInsert(vacio);
            listaX9.FinalInsert(vacio);
            listaX10.FinalInsert(vacio);
            listaX11.FinalInsert(vacio);
            listaX12.FinalInsert(vacio);
            listaX13.FinalInsert(vacio);
            listaX14.FinalInsert(vacio);
            listaX15.FinalInsert(vacio);

        }
        listaY[0]=listaX;
        listaY[1]=listaX2;
        listaY[2]=listaX3;
        listaY[3]=listaX4;
        listaY[4]=listaX5;
        listaY[5]=listaX6;
        listaY[6]=listaX7;
        listaY[7]=listaX8;
        listaY[8]=listaX9;
        listaY[9]=listaX10;
        listaY[10]=listaX11;
        listaY[11]=listaX12;
        listaY[12]=listaX13;
        listaY[13]=listaX14;
        listaY[14]=listaX15;
    }
    void insertarSoldados(){
        Soldados.FinalInsert(s1);
        Soldados.FinalInsert(s2);
        Soldados.FinalInsert(s3);
        Soldados.FinalInsert(s4);
        Soldados.FinalInsert(s5);
        Soldados.FinalInsert(s6);
        Soldados.FinalInsert(s7);
        Soldados.FinalInsert(s8);
        Soldados.FinalInsert(s9);
        Soldados.FinalInsert(s10);
        Soldados.FinalInsert(s11);
        Soldados.FinalInsert(s12);
        Soldados.FinalInsert(s13);
        Soldados.FinalInsert(s14);
        Soldados.FinalInsert(s15);
    }

public:
    void actualizarXY(){

        for(int i=0;i<15;i++){
            for (int j = 0; j <15 ; ++j) {
                listaY[i].get_Nodo(j)->X=j*50;
                listaY[i].get_Nodo(j)->posY=i*50;
                if(listaY[i].get_Nodo(j)->data.nombre=="vacio"){
                    listaY[i].get_Nodo(j)->data.posx=j;
                    listaY[i].get_Nodo(j)->data.posy=i;
                }else if(listaY[i].get_Nodo(j)->data.nombre=="arbol"){
                    listaY[i].get_Nodo(j)->data.posx=j;
                    listaY[i].get_Nodo(j)->data.posy=i;
                }
            }
        }
    }
    void colocarObstaculos(){
        while(con<30){
            int z=rand()%15;
            int z2=rand()%15;
            if((z!=0 && z2!=0) &&(z!=14 && z2!=14) ){
                if(listaY[z].get_Nodo(z2)->data.nombre=="vacio"){
                    listaY[z].get_Nodo(z2)->data=obstaculo;

                    listaY[z].get_Nodo(z2)->peso=0;
                    con++;
                }
            }
        }
        con=0;
    }void agregarSprites() {
        for(int i1=0;i1<15;i1++){
            for(int i2=0;i2<15;i2++){
                if(listaY[i1].get_Nodo(i2)->data.nombre=="soldado"){
                    listaY[i1].get_Nodo(i2)->data=vacio;
                }
            }
        }


        for(int i=0;i<15;i++){
            listaY[Soldados.get_Data(i).posy].ChangeDataPos(Soldados.get_Data(i), Soldados.get_Data(i).posx);
        }



    }
    void agregarSpritesE(){
        int con2=0;
        for(int i1=0;i1<15;i1++){
            for(int i2=0;i2<15;i2++){
                if(listaY[i1].get_Nodo(i2)->data.nombre=="Enemigo"){
                    listaY[i1].get_Nodo(i2)->data=vacio;
                }
            }
        }
        while(con2<20){
            int z=rand()%15;
            int z2=rand()%15;

            if((z!=0 && z2!=0) &&(z!=14 && z2!=14) ){
                if(listaY[z].get_Data(z2).nombre=="vacio"){
                    EnemigosT[nivel].get_Nodo(con2)->data.posx=z;
                    EnemigosT[nivel].get_Nodo(con2)->data.posy=z2;
                    listaY[z2].get_Nodo(z)->data=EnemigosT[nivel].get_Data(con2);
                    //listaY[z2].ChangeDataPos(),z);

                    con2++;
                }
            }
        }


    }
public:

    void imprimir(){

        for(int k=0;k<15;k++) {
            for(int t=0;t<15;t++){
                std::cout<<"{"<<listaY[k].get_Data(t).nombre<<"},";
            }

            std::cout<<std::endl;
        }

    }
    void imprimirXY(){
        std::cout<<"{"<<std::endl;
        for(int i=0;i<15;i++){
            for (int j = 0; j <15 ; ++j) {
                std::cout<<"X: "<<listaY[i].get_Nodo(j)->X<<"-Y: ";
                std::cout<<listaY[i].get_Nodo(j)->posY<<"next->";

            }
            std::cout<<std::endl;
        }

    }void imprimirPeso(){

        std::cout<<"{"<<std::endl;
        for(int i=0;i<15;i++){
            for (int j = 0; j <15 ; ++j) {
                std::cout<<"{";
                std::cout<<listaY[i].get_Nodo(j)->peso;
                std::cout<<"},";

            }
            std::cout<<std::endl;
        }std::cout<<"}";
    }

    /*void mover(){

        listaY[3].get_Nodo(0)->data.posx+=1;
        listaY[4].get_Nodo(1)->data=listaY[3].get_Nodo(0)->data;
        listaY[3].get_Nodo(0)->data=vacio;

    }*/
    void obtenerXY(int X, int Y, int& p, int& q){
        for(int py=0;py<15;py++){
            for(int px=0;px<15;px++){
                if(px==14 &&py==14 && (listaY[py].get_Nodo(px)->posY<= Y)&&(listaY[py].get_Nodo(px)->X<= X)){


                    p=14;
                    q=14;
                    break;

                }
                else if(px!=14 && py!=14 && (listaY[py].get_Nodo(px)->posY<= Y)&&(Y<=listaY[py+1].get_Nodo(px)->posY)&&(listaY[py].get_Nodo(px)->X<= X)&&(X <=listaY[py].get_Nodo(px+1)->X)){


                    p=listaY[py].get_Nodo(px)->data.posx;
                    q=listaY[py].get_Nodo(px)->data.posy;
                    break;


                }else if(px==14 && (listaY[py].get_Nodo(px)->posY<= Y) && (Y <=listaY[py+1].get_Nodo(px)->posY) && (listaY[py].get_Nodo(px)->X<= X)){


                    p=listaY[py].get_Nodo(px)->data.posx;
                    q=listaY[py].get_Nodo(px)->data.posy;
                    break;

                }else if(py==14 && (listaY[py].get_Nodo(px)->posY<= Y)  && (listaY[py].get_Nodo(px)->X<= X)&&(X <=listaY[py].get_Nodo(px+1)->X)){

                    p=listaY[py].get_Nodo(px)->data.posx;
                    q=listaY[py].get_Nodo(px)->data.posy;
                    break;

                }
            }
        }
    }


        void contarArboles(){
        int csddsa=0;
        for(int k=0;k<15;k++) {
            for(int t=0;t<15;t++){
                if(listaY[k].get_Data(t).nombre=="arbol"){
                    csddsa++;
                }
            }


        }std::cout<<csddsa<<std::endl;
        int csdds=0;
        for(int ka=0;ka<15;ka++) {
            for(int ta=0;ta<15;ta++){
                if(listaY[ka].get_Data(ta).nombre=="Enemigo"){
                    csdds++;
                }
            }


        }std::cout<<csdds<<std::endl;


    }


    void deteccionE(){




        int contador=0;
        while(contador<20){
            if(EnemigosT[nivel].get_Data(contador).posy!=0 &&EnemigosT[nivel].get_Data(contador).nombre=="Enemigo" &&listaY[(EnemigosT[nivel].get_Data(contador).posy-1)].get_Nodo(EnemigosT[nivel].get_Data(contador).posx)->data.nombre=="soldado"){
                for(int j=0;j<15;j++){
                    if(Soldados.get_Data(j).posy==EnemigosT[nivel].get_Data(contador).posy-1 && Soldados.get_Data(j).posx==EnemigosT[nivel].get_Data(contador).posx){
                        std::cout<<"ATACANDO ENEMIGO Arriba"<<std::endl;
                        int value;

                        value = atackWindow.drawAtackWindow(Soldados.get_Nodo(j)->data,EnemigosT[nivel].get_Nodo(contador)->data,nivel);

                        EnemigosT[nivel].get_Nodo(contador)->data.digievolucion(Soldados.get_Nodo(j)->data.elemento);
                        if(value==1){
                            EnemigosT[nivel+1].get_Nodo(contador)->data=EnemigosT[nivel].get_Nodo(contador)->data;
                            std::cout<<"EVOLUCIONO A : "<<EnemigosT[nivel].get_Nodo(contador)->data.elemento<<std::endl;
                            listaY[EnemigosT[nivel].get_Nodo(contador)->data.posy].get_Nodo(EnemigosT[nivel].get_Nodo(contador)->data.posx)->data=vacio;
                            EnemigosT[nivel].get_Nodo(contador)->data=vacio;
                            std::cout<<"EVOLUCIONO A : "<<EnemigosT[nivel+1].get_Nodo(contador)->data.elemento<<std::endl;

                        }else if(value==2){
                            vacio.posx=Soldados.get_Nodo(j)->data.posx;
                            vacio.posy=Soldados.get_Nodo(j)->data.posy;
                            Soldados.get_Nodo(j)->data=vacio;
                            agregarSprites();
                        }else if(value==3){
                            EnemigosT[nivel+1].get_Nodo(contador)->data=EnemigosT[nivel].get_Nodo(contador)->data;
                            listaY[EnemigosT[nivel].get_Nodo(contador)->data.posy].get_Nodo(EnemigosT[nivel].get_Nodo(contador)->data.posx)->data=vacio;
                            EnemigosT[nivel].get_Nodo(contador)->data=vacio;
                            std::cout<<EnemigosT[nivel+1].get_Nodo(contador)->data.elemento<<std::endl;
                            vacio.posx=Soldados.get_Nodo(j)->data.posx;
                            vacio.posy=Soldados.get_Nodo(j)->data.posy;
                            Soldados.get_Nodo(j)->data=vacio;
                            agregarSprites();
                        }

                    }
                }
            }
            else if(EnemigosT[nivel].get_Data(contador).posx!=14  &&EnemigosT[nivel].get_Data(contador).nombre=="Enemigo"&& listaY[(EnemigosT[nivel].get_Data(contador).posy)].get_Nodo(EnemigosT[nivel].get_Data(contador).posx+1)->data.nombre=="soldado"){
                for(int j=0;j<15;j++){
                    if(Soldados.get_Data(j).posy==EnemigosT[nivel].get_Data(contador).posy && Soldados.get_Data(j).posx==EnemigosT[nivel].get_Data(contador).posx+1){
                        std::cout<<"ATACANDO ENEMIGO Derecha"<<std::endl;
                        int value;

                        value = atackWindow.drawAtackWindow(Soldados.get_Nodo(j)->data,EnemigosT[nivel].get_Nodo(contador)->data,nivel);
                        std::cout<<"el valor retornado"<<value<<std::endl;
                        EnemigosT[nivel].get_Nodo(contador)->data.digievolucion(Soldados.get_Nodo(j)->data.elemento);
                        if(value==1){
                            EnemigosT[nivel+1].get_Nodo(contador)->data=EnemigosT[nivel].get_Nodo(contador)->data;
                            listaY[EnemigosT[nivel].get_Nodo(contador)->data.posy].get_Nodo(EnemigosT[nivel].get_Nodo(contador)->data.posx)->data=vacio;
                            EnemigosT[nivel].get_Nodo(contador)->data=vacio;
                            std::cout<<EnemigosT[nivel+1].get_Nodo(contador)->data.elemento<<std::endl;

                        }else if(value==2){

                            vacio.posx=Soldados.get_Nodo(j)->data.posx;
                            vacio.posy=Soldados.get_Nodo(j)->data.posy;
                            Soldados.get_Nodo(j)->data=vacio;
                            agregarSprites();
                        }else if(value==3){
                            EnemigosT[nivel+1].get_Nodo(contador)->data=EnemigosT[nivel].get_Nodo(contador)->data;
                            listaY[EnemigosT[nivel].get_Nodo(contador)->data.posy].get_Nodo(EnemigosT[nivel].get_Nodo(contador)->data.posx)->data=vacio;
                            EnemigosT[nivel].get_Nodo(contador)->data=vacio;
                            std::cout<<EnemigosT[nivel+1].get_Nodo(contador)->data.elemento<<std::endl;
                            vacio.posx=Soldados.get_Nodo(j)->data.posx;
                            vacio.posy=Soldados.get_Nodo(j)->data.posy;
                            Soldados.get_Nodo(j)->data=vacio;
                            agregarSprites();
                        }
                    }
                }



            }else if(EnemigosT[nivel].get_Data(contador).posy!=14  && EnemigosT[nivel].get_Data(contador).nombre=="Enemigo"&& listaY[(EnemigosT[nivel].get_Data(contador).posy+1)].get_Nodo(EnemigosT[nivel].get_Data(contador).posx)->data.nombre=="soldado"){

                for(int j=0;j<15;j++){
                    if(Soldados.get_Data(j).posy==EnemigosT[nivel].get_Data(contador).posy+1 && Soldados.get_Data(j).posx==EnemigosT[nivel].get_Data(contador).posx){
                        std::cout<<"ATACANDO ENEMIGO Abajo"<<std::endl;
                        int value;

                        value = atackWindow.drawAtackWindow(Soldados.get_Nodo(j)->data,EnemigosT[nivel].get_Nodo(contador)->data,nivel);
                        std::cout<<"el valor retornado"<<value<<std::endl;
                        EnemigosT[nivel].get_Nodo(contador)->data.digievolucion(Soldados.get_Nodo(j)->data.elemento);
                        if(value==1){
                            EnemigosT[nivel+1].get_Nodo(contador)->data=EnemigosT[nivel].get_Nodo(contador)->data;
                            listaY[EnemigosT[nivel].get_Nodo(contador)->data.posy].get_Nodo(EnemigosT[nivel].get_Nodo(contador)->data.posx)->data=vacio;
                            EnemigosT[nivel].get_Nodo(contador)->data=vacio;
                            std::cout<<EnemigosT[nivel+1].get_Nodo(contador)->data.elemento<<std::endl;

                        }else if(value==2){
                            vacio.posx=Soldados.get_Nodo(j)->data.posx;
                            vacio.posy=Soldados.get_Nodo(j)->data.posy;
                            Soldados.get_Nodo(j)->data=vacio;

                            agregarSprites();
                            std::cout<<listaY[14].get_Nodo(14)->data.nombre<<std::endl;
                        }else if(value==3){
                            EnemigosT[nivel+1].get_Nodo(contador)->data=EnemigosT[nivel].get_Nodo(contador)->data;
                            listaY[EnemigosT[nivel].get_Nodo(contador)->data.posy].get_Nodo(EnemigosT[nivel].get_Nodo(contador)->data.posx)->data=vacio;
                            EnemigosT[nivel].get_Nodo(contador)->data=vacio;
                            std::cout<<EnemigosT[nivel+1].get_Nodo(contador)->data.elemento<<std::endl;
                            vacio.posx=Soldados.get_Nodo(j)->data.posx;
                            vacio.posy=Soldados.get_Nodo(j)->data.posy;
                            Soldados.get_Nodo(j)->data=vacio;
                            agregarSprites();
                        }
                    }

                }
            }
            else if(EnemigosT[nivel].get_Data(contador).posy!=0 &&EnemigosT[nivel].get_Data(contador).nombre=="Enemigo" &&listaY[(EnemigosT[nivel].get_Data(contador).posy)].get_Nodo(EnemigosT[nivel].get_Data(contador).posx-1)->data.nombre=="soldado"){
                for(int j=0;j<15;j++){
                    if(Soldados.get_Data(j).posy==EnemigosT[nivel].get_Data(contador).posy && Soldados.get_Data(j).posx==EnemigosT[nivel].get_Data(contador).posx-1){
                        std::cout<<"ATACANDO ENEMIGO IZQ"<<std::endl;
                        int value;

                        value = atackWindow.drawAtackWindow(Soldados.get_Nodo(j)->data,EnemigosT[nivel].get_Nodo(contador)->data,nivel);
                        std::cout<<"el valor retornado"<<value<<std::endl;
                        EnemigosT[nivel].get_Nodo(contador)->data.digievolucion(Soldados.get_Nodo(j)->data.elemento);
                        if(value==1){
                            EnemigosT[nivel+1].get_Nodo(contador)->data=EnemigosT[nivel].get_Nodo(contador)->data;
                            listaY[EnemigosT[nivel].get_Nodo(contador)->data.posy].get_Nodo(EnemigosT[nivel].get_Nodo(contador)->data.posx)->data=vacio;
                            EnemigosT[nivel].get_Nodo(contador)->data=vacio;
                            std::cout<<EnemigosT[nivel+1].get_Nodo(contador)->data.elemento<<std::endl;

                        }else if(value==2){
                            vacio.posx=Soldados.get_Nodo(j)->data.posx;
                            vacio.posy=Soldados.get_Nodo(j)->data.posy;
                            Soldados.get_Nodo(j)->data=vacio;
                            agregarSprites();
                        }else if(value==3){
                            EnemigosT[nivel+1].get_Nodo(contador)->data=EnemigosT[nivel].get_Nodo(contador)->data;
                            listaY[EnemigosT[nivel].get_Nodo(contador)->data.posy].get_Nodo(EnemigosT[nivel].get_Nodo(contador)->data.posx)->data=vacio;
                            EnemigosT[nivel].get_Nodo(contador)->data=vacio;
                            std::cout<<EnemigosT[nivel+1].get_Nodo(contador)->data.elemento<<std::endl;
                            vacio.posx=Soldados.get_Nodo(j)->data.posx;
                            vacio.posy=Soldados.get_Nodo(j)->data.posy;
                            Soldados.get_Nodo(j)->data=vacio;
                            agregarSprites();
                        }
                    }

                }

            }else{
                contador++;

            }





        }

    }
};


#endif //PRUEBAS22_MAPA_H