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
    Sprite vacio=Sprite("vacio",'N',0,0);
    Sprite obstaculo=Sprite("arbol",'N',0,0);
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
    }
};


#endif //PRUEBAS22_MAPA_H