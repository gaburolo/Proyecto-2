//
// Created by gaburolo on 31/10/18.
//

#ifndef PRUEBAS22_SPRITE_H
#define PRUEBAS22_SPRITE_H

#include "iostream"

class Sprite{
public:
    int  stamina;
    int posx;
    int posy;
    std::string nombre;
    char elemento;

public:

    Sprite(std::string name, char power, int x, int y){
        stamina = 100;
        posx = x;
        posy = y;
        nombre = name;
        elemento = power;



    }



};


#endif //PRUEBAS22_SPRITE_H
