//
// Created by martinPC on 5/11/2018.
//

#ifndef PRUEBAS22_PELEA_H
#define PRUEBAS22_PELEA_H

#include "Sprite.cpp"




/*
 mapa mp;

    cout<<"-------------Matriz---------------"<<endl;
    mp.imprimir();
    mp.contarArboles();


    mp.deteccionE();
    cout<<"-------------Matriz-Enemigo eliminado--------------"<<endl;

    mp.imprimir();
    cout<<"-------------Matriz-Enemigo eliminado--------------"<<endl;

 *
 *
 *
 * */




class pelea {
public:
    pelea(Sprite soldado, Sprite Enemigo){
        int stamina = Enemigo.atacado(soldado.elemento);
        int skillNumber;
        if(stamina==0){
            std::cout<<"muerto"<<std::endl;
        }else{
            //std::cin>>skillNumber;
            /*switch (skillNumber){
                case 1:std::cout << "1";
                case 2:std::cout << "2";
                //case 3:std::cout << "1";
            }*/
        }
    }

};


#endif //PRUEBAS22_PELEA_H
