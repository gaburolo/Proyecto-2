#ifndef PRUEBAS22_MAPA_H
#define PRUEBAS22_MAPA_H
#include <iostream>
#include "ListaSimple.h"
#include "Sprite.cpp"
#include <list>
using namespace std;



template <class pr>
void Show(pr &d){
    std::cout<<d<<",";
}


class mapa {
private:
    int con=0;
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
    Lista<Sprite> *listaY=new Lista<Sprite>[10];
    Sprite *Soldados=new Sprite[15];
    Lista<Sprite> Enemigos;

    Sprite *EnemigosNvl2=new Sprite[20];
    Sprite vacio=Sprite("vacio",'N',0,0);
    Sprite obstaculo=Sprite("arbol",'N',0,0);
    Sprite s1=Sprite("soldado",'Va',1,1);
    Sprite ene1=Sprite("Enemigo",'Vi',1,0);
    Sprite ene2=Sprite("Enemigo",'Vi',2,1);
    Sprite ene3=Sprite("Enemigo",'Vi',1,2);
    Sprite ene4=Sprite("Enemigo",'Vi',0,1);
public:
    mapa(){


        for(int i=0; i<10;i++){

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

        }
        Soldados[0]=s1;
        Enemigos.FinalInsert(ene1);
        Enemigos.FinalInsert(ene2);
        Enemigos.FinalInsert(ene3);
        Enemigos.FinalInsert(ene4);


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
        actualizarXY();


    }

    void imprimir(){
        for(int k=0;k<10;k++) {
            for(int t=0;t<10;t++){
                cout<<"{"<<listaY[k].get_Data(t).nombre<<"},";
            }

            cout<<endl;
        }
    }
    void actualizarXY(){

        for(int i=0;i<10;i++){
            for (int j = 0; j <10 ; ++j) {
                listaY[i].get_Nodo(j)->X=j*50;
                listaY[i].get_Nodo(j)->posY=i*50;

            }
        }
    }void imprimirXY(){
        cout<<"{"<<endl;
        for(int i=0;i<10;i++){
            for (int j = 0; j <10 ; ++j) {
                cout<<"X: "<<listaY[i].get_Nodo(j)->X<<"-Y: ";
                cout<<listaY[i].get_Nodo(j)->posY<<"next->";

            }
            cout<<endl;
        }

    }void imprimirPeso(){

        cout<<"{"<<endl;
        for(int i=0;i<10;i++){
            for (int j = 0; j <10 ; ++j) {
                cout<<"{";
                cout<<listaY[i].get_Nodo(j)->peso;
                cout<<"},";

            }
            cout<<endl;
        }cout<<"}";
    }void colocarObstaculos(){
        while(con<30){
            int z=rand()%10;
            int z2=rand()%10;
            if((z!=0 && z2!=0) &&(z!=9 && z2!=9) ){
                listaY[z].ChangeDataPos(obstaculo,z2);
                listaY[z].get_Nodo(z2)->peso=0;
            }else{
                return colocarObstaculos();
            }

            con++;
        }
        con=0;
    }void agregarSprites() {
        listaY[1].ChangeDataPos(s1, Soldados[0].posx);
        listaY[Enemigos.get_Data(0).posy].ChangeDataPos(Enemigos.get_Data(0),Enemigos.get_Data(0).posx);
        listaY[Enemigos.get_Data(1).posy].ChangeDataPos(Enemigos.get_Data(1),Enemigos.get_Data(1).posx);
        listaY[Enemigos.get_Data(2).posy].ChangeDataPos(Enemigos.get_Data(2),Enemigos.get_Data(2).posx);
        listaY[Enemigos.get_Data(3).posy].ChangeDataPos(Enemigos.get_Data(3),Enemigos.get_Data(3).posx);

    }void deteccionE(){

        cout<<Enemigos.get_Data(3).nombre<<endl;


        int contador=0;
        while(contador<1){
            if(Soldados[0].posy!=0 &&listaY[(Soldados[0].posy-1)].get_Nodo(Soldados[0].posx)->data.nombre=="Enemigo"){
                listaY[(Soldados[0].posy-1)].get_Nodo(Soldados[0].posx)->data=vacio;
                if(Enemigos.get_Data(0).posy==Soldados[0].posy-1 && Enemigos.get_Data(0).posx==Soldados[0].posx){
                    EnemigosNvl2[0]=Enemigos.get_Data(0);
                    Enemigos.Delete_Pos(0);

                }
                cout<<"ATACANDO ENEMIGO Arriba"<<endl;
            }
            else if(Soldados[0].posx!=9 && listaY[(Soldados[0].posy)].get_Nodo(Soldados[0].posx+1)->data.nombre=="Enemigo"){
                cout<<"ATACANDO ENEMIGO Derecha"<<endl;
                listaY[(Soldados[0].posy)].get_Nodo(Soldados[0].posx+1)->data=vacio;

            }else if(Soldados[0].posy!=0 &&listaY[(Soldados[0].posy+1)].get_Nodo(Soldados[0].posx)->data.nombre=="Enemigo"){
                listaY[(Soldados[0].posy+1)].get_Nodo(Soldados[0].posx)->data=vacio;
                cout<<"ATACANDO ENEMIGO Abajo"<<endl;
            }else if(Soldados[0].posy!=0 &&listaY[(Soldados[0].posy)].get_Nodo(Soldados[0].posx-1)->data.nombre=="Enemigo"){
                listaY[(Soldados[0].posy)].get_Nodo(Soldados[0].posx-1)->data=vacio;
                cout<<"ATACANDO ENEMIGO Izquierda"<<endl;
            }
            else{
                cout<<"No hay enemigo"<<endl;
            }
            contador++;
        }
    }

    //
};


#endif //PRUEBAS22_MAPA_H