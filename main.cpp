#include <iostream>
#include "ListaSimple.h"

#include <list>
#include "mapa.cpp"
#include "Sprite.cpp"
using namespace std;
template <class pr>
void Show2(pr &d){
    std::cout<<d<<",";
}

int main(){






    mapa mp;

    cout<<"-------------Matriz---------------"<<endl;
    mp.imprimir();
    cout<<"-------------CON OBSTACULOS---------------"<<endl;


    mp.agregarSprites();
    mp.colocarObstaculos();
    cout<<"-------------Matriz---------------"<<endl;
    mp.imprimir();

    mp.deteccionE();
    cout<<"-------------Matriz-Enemigo eliminado--------------"<<endl;
    mp.imprimir();

    return 0;
}