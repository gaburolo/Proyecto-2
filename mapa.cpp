#ifndef PRUEBAS22_MAPA_H
#define PRUEBAS22_MAPA_H
#include <iostream>
#include "ListaSimple.h"

#include <list>
using namespace std;
class mapa {
private:
    list<Lista<int>> listY;
    Lista<int> listaX;

    std::list<Lista<int>>::iterator itr;
public:
    mapa(){

        for(int i=0; i<10;i++){
            listaX.FinalInsert(i);
        }

        for(int j=0; j<10;j++){
            listY.push_back(listaX);
        }



        actualizarXY();


    }

    void imprimir(){
        cout<<"{"<<endl;

        for (itr=listY.begin(); itr != listY.end(); itr++)
        {
            Lista<int>tl=*itr;


            for (int in=0; in<10; in++)
            {
                cout<<"{"<<listaX.get_Data(in)<<"},";
            }
            cout<<endl;

        }cout<<"}"<<endl;
    }
    void actualizarXY(){

        int temp=0;
        for (itr=listY.begin(); itr != listY.end(); itr++)
        {
            Lista<int>tl=*itr;


            for (int iny=0; iny<10; iny++)
            {

                tl.get_Nodo(iny)->X=iny*50;
                tl.get_Nodo(iny)->posY=temp;


            }
temp++;
        }
    }void imprimirXY(){
        cout<<"{dsfd"<<endl;
        for (itr=listY.begin(); itr != listY.end(); itr++)
        {
            Lista<int>tl=*itr;


            for (int ine=0; ine<10; ine++)
            {

                cout<<tl.get_Nodo(ine)->X<<" ";
                cout<<tl.get_Nodo(ine)->posY<<"-";
            }
            cout<<endl;
        }

    }
};


#endif //PRUEBAS22_MAPA_H