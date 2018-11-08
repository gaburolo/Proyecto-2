#ifndef PRUEBAS22_MAPA
#define PRUEBAS22_MAPA



#include <iostream>

#include "AtackWindow.h"
#include "FightMenu.h"
#include "ListaSimple.h"
#include "Sprite.cpp"

#include <SFML/Graphics.hpp>





template <class pr>
void Show(pr &d){
    std::cout<<d<<",";
}


class mapa {
public:
    Sprite vacio=Sprite("vacio",'N',0,0);
    Lista<Sprite> *listaY=new Lista<Sprite>[15];
private:
    //AtackWindow atackWindow;

    int con=0;
    int con2=0;
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

    Lista<Sprite> Soldados;
    Lista<Sprite> Enemigos;

    Sprite *EnemigosNvl2=new Sprite[20];

    Sprite obstaculo=Sprite("arbol",'N',0,0);
    Sprite s1=Sprite("soldado",'d',0,0);
    //CAmbiar aqui
    Sprite s2=Sprite("soldado",'d',0,1);
    Sprite s3=Sprite("soldado",'d',0,2);
    Sprite s4=Sprite("soldado",'d',0,3);
    Sprite s5=Sprite("soldado",'d',1,0);
    Sprite s6=Sprite("soldado",'v',1,1);
    Sprite s7=Sprite("soldado",'v',1,2);
    Sprite s8=Sprite("soldado",'v',1,3);
    Sprite s9=Sprite("soldado",'v',2,0);
    Sprite s10=Sprite("soldado",'v',2,1);
    Sprite s11=Sprite("soldado",'x',2,2);

    Sprite s12=Sprite("soldado",'x',2,3);
    Sprite s13=Sprite("soldado",'x',3,0);
    Sprite s14=Sprite("soldado",'x',3,1);
    Sprite s15=Sprite("soldado",'x',3,2);
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

        s1=Sprite("soldado",'d',0,0);
        //CAmbiar aqui
        s2=Sprite("soldado",'d',0,1);
        s3=Sprite("soldado",'d',0,2);
        s4=Sprite("soldado",'d',0,3);
        s5=Sprite("soldado",'d',1,0);
        s6=Sprite("soldado",'v',1,1);
        s7=Sprite("soldado",'v',1,2);
        s8=Sprite("soldado",'v',1,3);
        s9=Sprite("soldado",'v',2,0);
        s10=Sprite("soldado",'v',2,1);
        s11=Sprite("soldado",'x',2,2);

        s12=Sprite("soldado",'x',2,3);
        s13=Sprite("soldado",'x',3,0);
        s14=Sprite("soldado",'x',3,1);
        s15=Sprite("soldado",'x',3,2);
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
        //agregarSpritesE();
        //colocarObstaculos();
        actualizarXY();
    }

private:
    void insertarEnemigos(){
        Enemigos.FinalInsert(ene1);
        Enemigos.FinalInsert(ene2);
        Enemigos.FinalInsert(ene3);
        Enemigos.FinalInsert(ene4);
        Enemigos.FinalInsert(ene5);
        Enemigos.FinalInsert(ene6);
        Enemigos.FinalInsert(ene7);
        Enemigos.FinalInsert(ene8);
        Enemigos.FinalInsert(ene9);
        Enemigos.FinalInsert(ene10);
        Enemigos.FinalInsert(ene11);
        Enemigos.FinalInsert(ene12);
        Enemigos.FinalInsert(ene13);
        Enemigos.FinalInsert(ene14);
        Enemigos.FinalInsert(ene15);
        Enemigos.FinalInsert(ene16);
        Enemigos.FinalInsert(ene17);
        Enemigos.FinalInsert(ene18);
        Enemigos.FinalInsert(ene19);
        Enemigos.FinalInsert(ene20);

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
        while(con2<19){
            int z=rand()%15;
            int z2=rand()%15;

            if((z!=0 && z2!=0) &&(z!=14 && z2!=14) ){
                if(listaY[z].get_Data(z2).nombre=="vacio"){
                    Enemigos.get_Nodo(con2)->data.posx=z;
                    Enemigos.get_Nodo(con2)->data.posy=z2;
                    listaY[z2].get_Nodo(z)->data=Enemigos.get_Data(con2);
                    //listaY[z2].ChangeDataPos(),z);

                    con2++;
                }
            }
        }
        Enemigos.get_Nodo(con2)->data.posx=10;
        Enemigos.get_Nodo(con2)->data.posy=10;
        listaY[10].get_Nodo(10)->data=Enemigos.get_Data(10);

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
            if(Enemigos.get_Data(contador).posy!=0 &&listaY[(Enemigos.get_Data(contador).posy-1)].get_Nodo(Enemigos.get_Data(contador).posx)->data.nombre=="soldado"){
                for(int j=0;j<15;j++){
                    if(Soldados.get_Data(j).posy==Enemigos.get_Data(contador).posy-1 && Soldados.get_Data(j).posx==Enemigos.get_Data(contador).posx){
                        std::cout<<"ATACANDO ENEMIGO Arriba"<<std::endl;
                        int value;

                        //value = atackWindow.drawAtackWindow(Soldados.get_Nodo(j)->data,Enemigos.get_Nodo(contador)->data,1);

                        listaY[Soldados.get_Nodo(j)->data.posy].get_Nodo(Soldados.get_Nodo(j)->data.posx)->data=vacio;
                        Soldados.get_Nodo(j)->data=vacio;
                        actualizarXY();
                    }
                }
            }
            else if(Enemigos.get_Data(contador).posx!=14 && listaY[(Enemigos.get_Data(contador).posy)].get_Nodo(Enemigos.get_Data(contador).posx+1)->data.nombre=="soldado"){
                for(int j=0;j<15;j++){
                    if(Soldados.get_Data(j).posy==Enemigos.get_Data(contador).posy && Soldados.get_Data(j).posx==Enemigos.get_Data(contador).posx+1){
                        std::cout<<"ATACANDO ENEMIGO Derecha"<<std::endl;
                        listaY[Soldados.get_Nodo(j)->data.posy].get_Nodo(Soldados.get_Nodo(j)->data.posx)->data=vacio;
                        Soldados.get_Nodo(j)->data=vacio;
                        actualizarXY();
                    }
                }



            }else if(Enemigos.get_Data(contador).posy!=14 && listaY[(Enemigos.get_Data(contador).posy+1)].get_Nodo(Enemigos.get_Data(contador).posx)->data.nombre=="soldado"){

                for(int j=0;j<15;j++){
                    if(Soldados.get_Data(j).posy==Enemigos.get_Data(contador).posy+1 && Soldados.get_Data(j).posx==Enemigos.get_Data(contador).posx){
                        std::cout<<"ATACANDO ENEMIGO Abajo"<<std::endl;
                        listaY[Soldados.get_Nodo(j)->data.posy].get_Nodo(Soldados.get_Nodo(j)->data.posx)->data=vacio;
                        Soldados.get_Nodo(j)->data=vacio;
                        actualizarXY();
                    }

                }
            }
            else if(Enemigos.get_Data(contador).posy!=0 &&listaY[(Enemigos.get_Data(contador).posy)].get_Nodo(Enemigos.get_Data(contador).posx-1)->data.nombre=="soldado"){
                for(int j=0;j<15;j++){
                    if(Soldados.get_Data(j).posy==Enemigos.get_Data(contador).posy && Soldados.get_Data(j).posx==Enemigos.get_Data(contador).posx-1){
                        std::cout<<"ATACANDO ENEMIGO IZQ"<<std::endl;
                        listaY[Soldados.get_Nodo(j)->data.posy].get_Nodo(Soldados.get_Nodo(j)->data.posx)->data=vacio;
                        Soldados.get_Nodo(j)->data=vacio;
                        Soldados.get_Nodo(j)->data=vacio;
                        actualizarXY();
                    }

                }

            }else{
                contador++;

            }




        /*


            if(Soldados.get_Data(0).posy!=0 &&listaY[(Soldados.get_Data(0).posy-1)].get_Nodo(Soldados.get_Data(0).posx)->data.nombre=="Enemigo"){
                for(int j=0;j<20;j++){
                    if(Enemigos.get_Data(j).posy==Soldados.get_Data(0).posy-1 && Enemigos.get_Data(j).posx==Soldados.get_Data(0).posx){

                        int stamina=Enemigos.get_Nodo(j)->data.atacado(Soldados.get_Data(0).elemento);
                        if(stamina==0){
                            cout<<"ATACANDO ENEMIGO Arriba"<<endl;
                            listaY[(Soldados.get_Data(0).posy-1)].get_Nodo(Soldados.get_Data(0).posx)->data=vacio;
                            EnemigosNvl2[0]=Enemigos.get_Data(0);

                            Enemigos.Delete_Pos(j);
                        }else if(stamina!=0){
                            cout<<"ATACANDO ENEMIGO Arriba"<<endl;

                            cout<<Enemigos.get_Data(j).stamina<<endl;

                        }break;


                    }
                }
            }
            else if(Soldados.get_Data(0).posx!=14 && listaY[(Soldados.get_Data(0).posy)].get_Nodo(Soldados.get_Data(0).posx+1)->data.nombre=="Enemigo"){
                for(int j=0;j<20;j++){
                    if(Enemigos.get_Data(j).posy==Soldados.get_Data(0).posy && Enemigos.get_Data(j).posx==Soldados.get_Data(0).posx+1){

                        int stamina=Enemigos.get_Nodo(j)->data.atacado(Soldados.get_Data(0).elemento);
                        if(stamina==0) {
                            cout << "ATACANDO ENEMIGO Derecha" << endl;
                            listaY[(Soldados.get_Data(0).posy)].get_Nodo(Soldados.get_Data(0).posx + 1)->data = vacio;
                            EnemigosNvl2[0] = Enemigos.get_Data(0);

                            Enemigos.Delete_Pos(j);

                        }else if(stamina!=0){
                            cout<<"ATACANDO ENEMIGO Derecha"<<endl;

                            cout<<Enemigos.get_Data(j).stamina<<endl;

                        }break;
                    }
                }



            }else if(Soldados.get_Data(0).posy!=14 && listaY[(Soldados.get_Data(0).posy+1)].get_Nodo(Soldados.get_Data(0).posx)->data.nombre=="Enemigo"){

                for(int j=0;j<20;j++){
                    cout<<Enemigos.get_Data(j).posy<<Enemigos.get_Data(j).posx<<endl;

                    if(Enemigos.get_Data(j).posy==Soldados.get_Data(0).posy+1 && Enemigos.get_Data(j).posx==Soldados.get_Data(0).posx){
                        ;
                        int stamina=Enemigos.get_Nodo(j)->data.atacado(Soldados.get_Data(0).elemento);
                        if(stamina==0){
                            cout<<"ATACANDO ENEMIGO Abajo"<<endl;
                            listaY[(Soldados.get_Data(0).posy+1)].get_Nodo(Soldados.get_Data(0).posx)->data=vacio;
                            EnemigosNvl2[0]=Enemigos.get_Data(0);
                            Enemigos.Delete_Pos(j);
                        }else if(stamina!=0){
                            cout<<"ATACANDO ENEMIGO Abajo"<<endl;

                            cout<<Enemigos.get_Data(j).stamina<<endl;
                        }break;
                    }
                }



            }else if(Soldados.get_Data(0).posy!=0 &&listaY[(Soldados.get_Data(0).posy)].get_Nodo(Soldados.get_Data(0).posx-1)->data.nombre=="Enemigo"){
                for(int j=0;j<20;j++){
                    if(Enemigos.get_Data(j).posy==Soldados.get_Data(0).posy && Enemigos.get_Data(j).posx==Soldados.get_Data(0).posx-1){

                        int stamina=Enemigos.get_Nodo(j)->data.atacado(Soldados.get_Data(0).elemento);
                        if(stamina==0){
                            cout<<"ATACANDO ENEMIGO Izquierda"<<endl;
                            listaY[(Soldados.get_Data(0).posy)].get_Nodo(Soldados.get_Data(0).posx-1)->data=vacio;
                            EnemigosNvl2[0]=Enemigos.get_Data(0);
                            Enemigos.Delete_Pos(j);
                        }else if(stamina!=0){
                            cout<<"ATACANDO ENEMIGO Izquierda"<<endl;

                            cout<<Enemigos.get_Data(j).stamina<<endl;
                        }break;
                    }
                }

            }
            else{
                cout<<"No hay enemigo"<<endl;
            }
            contador++;*/
        }

    }	mapa& mover(int posx, int posy) {
        deteccionE();
        Soldados.get_Nodo(12)->data.visitados[0]=00;
        if(Soldados.get_Data(12).posx==14 && Soldados.get_Data(12).posy==14){

            vacio.posx=Soldados.get_Nodo(3)->data.posx;
            vacio.posy=Soldados.get_Nodo(3)->data.posy;
            Soldados.get_Nodo(3)->data=vacio;

            reinicio();

            //Soldados.Delete_Pos(3);
            //Soldados.Delete_Pos(3);
            //Soldados.Delete_Pos(3);
            //Soldados.Delete_Pos(3);
            //agregarSprites();
            //actualizarXY();



        }

        else if (Soldados.get_Data(12).posx==posx && Soldados.get_Data(12).posy==posy) {

            /*
            cont=0;
            x=0;
            y=0;
            */
        }
        else if(Soldados.get_Data(12).posy!=posy && Soldados.get_Data(12).posx!=posx) {

            if(listaY[Soldados.get_Data(12).posy+1].get_Nodo(Soldados.get_Data(12).posx+1)->data.nombre=="vacio"){
                Soldados.get_Nodo(12)->data.posx+=1;
                Soldados.get_Nodo(12)->data.posy+=1;
                //listaY[Soldados.get_Data(3).posx+1].get_Nodo(Soldados.get_Data(3).posy+1)->data=Soldados.get_Data(3);

                Soldados.get_Nodo(12)->data.con++;


                con++;
                Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);

                agregarSprites();
                actualizarXY();
                imprimir();
                std::cout<<std::endl;
                return mover(posx, posy);
            }
            else if(listaY[Soldados.get_Data(12).posy+1].get_Nodo(Soldados.get_Data(12).posx)->data.nombre=="vacio"){
                Soldados.get_Nodo(12)->data.posy+=1;
                Soldados.get_Nodo(12)->data.con++;
                Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);



                agregarSprites();
                actualizarXY();
                imprimir();
                std::cout<<std::endl;
                return mover(posx, posy);
            }else if(listaY[Soldados.get_Data(12).posy].get_Nodo(Soldados.get_Data(12).posx+1)->data.nombre=="vacio"){
                Soldados.get_Nodo(12)->data.posx+=1;
                Soldados.get_Nodo(12)->data.con++;
                Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);



                agregarSprites();
                actualizarXY();
                imprimir();
                std::cout<<std::endl;
                return mover(posx, posy);
            }else if(Soldados.get_Data(12).posx==0 && listaY[Soldados.get_Data(12).posy+1].get_Nodo(Soldados.get_Data(12).posx-1)->data.nombre=="vacio"){
                Soldados.get_Nodo(12)->data.posy+=1;
                Soldados.get_Nodo(12)->data.posx-=1;
                Soldados.get_Nodo(12)->data.con++;
                Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);

                agregarSprites();
                actualizarXY();
                imprimir();
                std::cout<<std::endl;
                return mover(posx, posy);
            }else if(Soldados.get_Data(12).posx==0 && listaY[Soldados.get_Data(12).posy].get_Nodo(Soldados.get_Data(12).posx-1)->data.nombre=="vacio"){

                Soldados.get_Nodo(12)->data.posx-=1;
                Soldados.get_Nodo(12)->data.con++;
                Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);

                agregarSprites();
                actualizarXY();
                imprimir();
                std::cout<<std::endl;
                return mover(posx, posy);
            }else if(Soldados.get_Data(12).posy==0 && listaY[Soldados.get_Data(12).posy-1].get_Nodo(Soldados.get_Data(12).posx)->data.nombre=="vacio"){

                Soldados.get_Nodo(12)->data.posy-=1;
                Soldados.get_Nodo(12)->data.con++;
                Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);



                agregarSprites();
                actualizarXY();
                imprimir();
                std::cout<<std::endl;
                return mover(posx, posy);
            }else if(Soldados.get_Data(12).posy==0 && listaY[Soldados.get_Data(12).posy-1].get_Nodo(Soldados.get_Data(12).posx+1)->data.nombre=="vacio"){
                Soldados.get_Nodo(12)->data.posx+=1;
                Soldados.get_Nodo(12)->data.posy-=1;
                Soldados.get_Nodo(12)->data.con++;
                Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);



                agregarSprites();
                actualizarXY();
                imprimir();
                std::cout<<std::endl;
                return mover(posx, posy);
            }else if(Soldados.get_Data(12).posx==0&&Soldados.get_Data(12).posy==0 && listaY[Soldados.get_Data(12).posy-1].get_Nodo(Soldados.get_Data(12).posx-1)->data.nombre=="vacio"){
                Soldados.get_Nodo(12)->data.posy-=1;
                Soldados.get_Nodo(12)->data.posy-=1;
                Soldados.get_Nodo(12)->data.con++;
                Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);



                agregarSprites();
                actualizarXY();
                imprimir();
                std::cout<<std::endl;
                return mover(posx, posy);
            }

            else {

                return goToThePast(posx,posy);
                //throw new IllegalArgumentException("NO HAY CAMINO");
            }

        }else if(Soldados.get_Data(12).posx==posx) {
            std::cout<<"sdasdasdwasdasdas"<<std::endl;
            return moverXsiete(posx,posy);
        }else if(Soldados.get_Data(12).posy==posy) {
            return moverYsiete(posx,posy);
        }
        else {
            throw "NEL PRRO";
        }



    }
    mapa& moverXsiete(int posx, int posy) {
        if(listaY[Soldados.get_Data(12).posy+1].get_Nodo(Soldados.get_Data(12).posx)->data.nombre=="vacio"){
            Soldados.get_Nodo(12)->data.posy+=1;
            Soldados.get_Nodo(12)->data.con++;
            Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);



            agregarSprites();
            actualizarXY();
            imprimir();
            std::cout<<std::endl;
            return mover(posx, posy);
        }else if(listaY[Soldados.get_Data(12).posy+1].get_Nodo(Soldados.get_Data(12).posx-1)->data.nombre=="vacio"){
            Soldados.get_Nodo(12)->data.posy+=1;
            Soldados.get_Nodo(12)->data.posx-=1;
            Soldados.get_Nodo(12)->data.con++;
            Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);

            agregarSprites();
            actualizarXY();
            imprimir();
            std::cout<<std::endl;
            return mover(posx, posy);
        }else if(listaY[Soldados.get_Data(12).posy].get_Nodo(Soldados.get_Data(12).posx-1)->data.nombre=="vacio"){

            Soldados.get_Nodo(12)->data.posx-=1;
            Soldados.get_Nodo(12)->data.con++;
            Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);

            agregarSprites();
            actualizarXY();
            imprimir();
            std::cout<<std::endl;
            return mover(posx, posy);
        }else if(listaY[Soldados.get_Data(12).posy-1].get_Nodo(Soldados.get_Data(12).posx-1)->data.nombre=="vacio"){
            Soldados.get_Nodo(12)->data.posy-=1;
            Soldados.get_Nodo(12)->data.posy-=1;
            Soldados.get_Nodo(12)->data.con++;
            Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);



            agregarSprites();
            actualizarXY();
            imprimir();
            std::cout<<std::endl;
            return mover(posx, posy);
        }else if(listaY[Soldados.get_Data(12).posy-1].get_Nodo(Soldados.get_Data(12).posx)->data.nombre=="vacio"){

            Soldados.get_Nodo(12)->data.posy-=1;
            Soldados.get_Nodo(12)->data.con++;
            Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);



            agregarSprites();
            actualizarXY();
            imprimir();
            std::cout<<std::endl;
            return mover(posx, posy);
        }else {

            return goToThePast(posx,posy);

        }

    }
    mapa& moverYsiete(int posx, int posy) {
        if(listaY[Soldados.get_Data(12).posy].get_Nodo(Soldados.get_Data(12).posx+1)->data.nombre=="vacio"){
            Soldados.get_Nodo(12)->data.posx+=1;
            Soldados.get_Nodo(12)->data.con++;
            Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);



            agregarSprites();
            actualizarXY();
            imprimir();
            std::cout<<std::endl;
            return mover(posx, posy);
        }else if(Soldados.get_Data(12).posy==0 && listaY[Soldados.get_Data(12).posy-1].get_Nodo(Soldados.get_Data(12).posx+1)->data.nombre=="vacio"){
            Soldados.get_Nodo(12)->data.posx+=1;
            Soldados.get_Nodo(12)->data.posy-=1;
            Soldados.get_Nodo(12)->data.con++;
            Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);



            agregarSprites();
            actualizarXY();
            imprimir();
            std::cout<<std::endl;
            return mover(posx, posy);
        }else if(Soldados.get_Data(12).posy==0 && listaY[Soldados.get_Data(12).posy-1].get_Nodo(Soldados.get_Data(12).posx)->data.nombre=="vacio"){

            Soldados.get_Nodo(12)->data.posy-=1;
            Soldados.get_Nodo(12)->data.con++;
            Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);



            agregarSprites();
            actualizarXY();
            imprimir();
            std::cout<<std::endl;
            return mover(posx, posy);
        }else if(listaY[Soldados.get_Data(12).posy-1].get_Nodo(Soldados.get_Data(12).posx)->data.nombre=="vacio"){

            Soldados.get_Nodo(12)->data.posy-=1;
            Soldados.get_Nodo(12)->data.con++;
            Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);



            agregarSprites();
            actualizarXY();
            imprimir();
            std::cout<<std::endl;
            return mover(posx, posy);
        }else if(Soldados.get_Data(12).posx==0&&Soldados.get_Data(12).posy==0 && listaY[Soldados.get_Data(12).posy-1].get_Nodo(Soldados.get_Data(12).posx-1)->data.nombre=="vacio"){
            Soldados.get_Nodo(12)->data.posy-=1;
            Soldados.get_Nodo(12)->data.posy-=1;
            Soldados.get_Nodo(12)->data.con++;
            Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);



            agregarSprites();
            actualizarXY();
            imprimir();
            std::cout<<std::endl;
            return mover(posx, posy);
        }else if(Soldados.get_Data(12).posx==0 && listaY[Soldados.get_Data(12).posy].get_Nodo(Soldados.get_Data(12).posx-1)->data.nombre=="vacio"){

            Soldados.get_Nodo(12)->data.posx-=1;
            Soldados.get_Nodo(12)->data.con++;
            Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]=(Soldados.get_Nodo(12)->data.posx)*10+(Soldados.get_Nodo(12)->data.posy);

            agregarSprites();
            actualizarXY();
            imprimir();
            std::cout<<std::endl;
            return mover(posx, posy);
        }



        else {

            return goToThePast(posx,posy);
            //throw new IllegalArgumentException("NO HAY CAMINO");
        }


    }mapa& goToThePast(int posx,int posy) {
        if(Soldados.get_Nodo(12)->data.con==0){
            std::cout<<"NO HAY CAMINO"<<std::endl;
        }else{

            Soldados.get_Nodo(12)->data.posx=Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]%10;
            Soldados.get_Nodo(12)->data.posy=Soldados.get_Nodo(12)->data.visitados[Soldados.get_Nodo(12)->data.con]/10;
            listaY[Soldados.get_Nodo(12)->data.posy].get_Nodo(Soldados.get_Nodo(12)->data.posx)->data=vacio;

            agregarSprites();
            actualizarXY();

            Soldados.get_Nodo(12)->data.con--;
            imprimir();
            return mover(posx,posy);
        }
        //return matriz;
    }

};


#endif //PRUEBAS22_MAPA_H