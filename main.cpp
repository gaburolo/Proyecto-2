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
    mp.contarArboles();


    mp.deteccionE();
    cout<<"-------------Matriz-Enemigo eliminado--------------"<<endl;

    mp.imprimir();
    cout<<"-------------Matriz-Enemigo eliminado--------------"<<endl;



    return 0;
}