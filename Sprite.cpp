//
// Created by gaburolo on 31/10/18.
//

#ifndef PRUEBAS22_SPRITE_H
#define PRUEBAS22_SPRITE_H

#include "iostream"

class Sprite{
public:
    int  stamina=100;
    int posx;
    int posy;
    std::string nombre;
    char elemento;

public:
    Sprite(){

    }
    Sprite(std::string name, char power, int x, int y){

        posx = x;
        posy = y;
        nombre = name;
        elemento = power;
    }
    void digievolucion(char setTipo){

        if (setTipo == 'x'){
            elemento = 'v';
        }
        else if (setTipo == 'd'){
            elemento = 'x';
        }
        else{
            elemento = 'd';
        }
    }

    int atacado(char tipo){
        if(elemento=='n'){
            if (tipo == 'v'){
                    elemento = tipo;
                    stamina = 100;
                    return 0;


            }
            else if (tipo == 'x'){

                    elemento = tipo;
                    stamina = 100;
                    return 0;

            }
            else{
                    elemento = tipo;
                    stamina = 100;
                    return 0;

            }
        }
        else if (elemento == 'x'){
            if (tipo == 'v'){
                stamina = stamina-100;
                if (stamina <= 0){
                    elemento = tipo;
                    stamina = 100;
                    return 0;
                }
                else{
                    return stamina;
                }

            }
            else if (tipo == 'x'){
                stamina = stamina -50;
                if (stamina <= 0){
                    elemento = tipo;
                    stamina = 100;
                    return 0;
                }
                else{
                    return stamina;
                }
            }
            else{

                stamina = stamina -25;
                if (stamina <= 0){
                    std::cout<<"pos si"<<std::endl;
                    elemento = tipo;
                    stamina = 100;
                    return 0;
                }
                else{
                    return stamina;
                }
            }
        } else if (elemento == 'v'){
            if (tipo == 'd'){
                stamina = stamina - 100;
                if (stamina <= 0){
                    elemento = tipo;
                    stamina = 100;
                    return 0;
                }
                else{
                    return stamina;
                }
            }
            else if (tipo == 'v'){
                stamina = stamina - 50;
                if (stamina <= 0){
                    elemento = tipo;
                    stamina = 100;
                    return 0;
                }
                else{
                    return stamina;
                }
            }
            else{
                stamina = stamina -25;
                if (stamina <= 0){
                    elemento = tipo;
                    stamina = 100;
                    return 0;
                }
                else{
                    return stamina;
                }
            }
        }
        else{
            if (tipo == 'x'){
                stamina = stamina - 100;
                if (stamina <= 0){
                    elemento = tipo;
                    stamina = 100;
                    return 0;
                }
                else{
                    return stamina;
                }
            }
            else if (tipo == 'd'){
                stamina = stamina - 50;
                if (stamina <= 0){
                    elemento = tipo;
                    stamina = 100;
                    return 0;
                }
                else{
                    return stamina;
                }
            }
            else{
                stamina = stamina -25;
                if (stamina <= 0){
                    elemento = tipo;
                    stamina = 100;
                    return 0;
                }
                else{
                    return stamina;
                }

            }
        }
    }


};


#endif //PRUEBAS22_SPRITE_H
