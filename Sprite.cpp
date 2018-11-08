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
    int visitados[225];
    int con = 0;

public:
    Sprite(){

    }
    Sprite(std::string name, char power, int x, int y){

        posx = x;
        posy = y;
        nombre = name;
        elemento = power;
    }
    void digievolucion(){

        if (elemento == 'x'){
            elemento = 'v';
            stamina = 100;
        }
        else if (elemento == 'd'){
            elemento = 'x';
            stamina = 100;
        }
        else{
            elemento = 'd';
            stamina = 100;
        }
    }

    int atacado(char tipo){
        if (elemento == 'x'){
            if (tipo == 'v'){
                stamina = stamina-100;
                if (stamina <= 0) {
                    return 0;
                }
                else{
                    return stamina;
                }

            }
            else if (tipo == 'x'){
                stamina = stamina -50;
                if (stamina <= 0){
                    return 0;
                }
                else{
                    return stamina;
                }
            }
            else{
                stamina = stamina -25;
                if (stamina <= 0){
                    return 0;
                }
                else{
                    return stamina;
                }
            }
        }else if (elemento == 'v'){
            if (tipo == 'd'){
                stamina = stamina - 100;
                if (stamina <= 0){
                    return 0;
                }
                else{
                    return stamina;
                }
            }
            else if (tipo == 'v'){
                stamina = stamina - 50;
                if (stamina <= 0){
                    return 0;
                }
                else{
                    return stamina;
                }
            }
            else{
                stamina = stamina -25;
                if (stamina <= 0){
                    return 0;
                }
                else{
                    return stamina;
                }
            }
        }
        else if (elemento == 'd'){
            if (tipo == 'x'){
                stamina = stamina - 100;
                if (stamina <= 0){
                    return 0;
                }
                else{
                    return stamina;
                }
            }
            else if (tipo == 'd'){
                stamina = stamina - 50;
                if (stamina <= 0){
                    return 0;
                }
                else{
                    return stamina;
                }
            }
            else{
                stamina = stamina -25;
                if (stamina <= 0){
                    return 0;
                }
                else{
                    return stamina;
                }

            }
        }
    }

    void atacar(int number, char type){
        switch (number){
            case 1:
                switch (type){
                    case 'v':
                        stamina = stamina - (5*5);
                        std::cout<<stamina;
                        break;

                    case 'x':
                        stamina = stamina - 5*3;
                        std::cout<<stamina;

                    case 'd':
                        stamina = stamina - 5*3;
                        std::cout<<stamina;

                }
                break;


            case 2:
                switch (type){
                    case 'v':
                        stamina = stamina - 5*3;
                        break;

                    case 'x':
                        stamina = stamina - 5*10;
                        break;


                    case 'd':
                        stamina = stamina - 5*3;
                        break;
                }
                break;

            case 3:
                switch (type){
                    case 'v':
                        stamina = stamina - 5*3;
                        break;

                    case 'x':
                        stamina = stamina - 5*5;
                        break;

                    case 'd':
                        stamina = stamina - 5*10;
                        break;
                }
                break;

            case 4:
                switch (type){
                    case 'v':
                        stamina = stamina - 5*5;
                        break;

                    case 'x':
                        stamina = stamina - 5*10;
                        break;

                    case 'd':
                        stamina = stamina - 5*7;
                        break;

                }
                break;

            case 5:
                switch (type){
                    case 'v':
                        stamina = stamina - 5*10;
                        break;

                    case 'x':
                        stamina = stamina - 5*5;
                        break;

                    case 'd':
                        stamina = stamina - 5*3;
                        break;

                }
                break;

            case 6:
                switch (type){
                    case 'v':
                        stamina = stamina - 5*3;
                        break;

                    case 'x':
                        stamina = stamina - 5*5;
                        break;

                    case 'd':
                        stamina = stamina - 5*5;
                        break;

                }
                break;

            case 7:
                switch (type){
                    case 'v':
                        stamina = stamina - 5*3;
                        break;

                    case 'x':
                        stamina = stamina - 5*3;
                        break;

                    case 'd':
                        stamina = stamina - 5*10;
                        break;

                }
                break;

            case 8:
                switch (type){
                    case 'v':
                        stamina = stamina - 5*15;
                        break;

                    case 'x':
                        stamina = stamina - 5*6;
                        break;

                    case 'd':
                        stamina = stamina - 5*8;
                        break;

                }
                break;

            case 9:
                switch (type){
                    case 'v':
                        stamina = stamina - 5*10;
                        break;

                    case 'x':
                        stamina = stamina - 5*15;
                        break;

                    case 'd':
                        stamina = stamina - 5*10;
                        break;

                }
                break;

            case 10:
                switch (type){
                    case 'v':
                        stamina = stamina - 5*2;
                        break;

                    case 'x':
                        stamina = stamina - 5*10;
                        break;

                    case 'd':
                        stamina = stamina - 5*10;
                        break;
                }
                break;

            case 11:
                switch (type){
                    case 'v':
                        stamina = stamina - 5*10;
                        break;

                    case 'x':
                        stamina = stamina - 5*10;
                        break;

                    case 'd':
                        stamina = stamina - 5*10;
                        break;

                }
                break;

            case 12:
                switch (type){
                    case 'v':
                        stamina = stamina - 5*15;
                        break;

                    case 'x':
                        stamina = stamina - 5*15;
                        break;

                    case 'd':
                        stamina = stamina - 5*15;
                        break;
                }
                break;


        }

    }

    int getStamina(){
        return stamina;
    }

    char getTipo(){
        return elemento;
    }
    void changeStamina(){
        stamina = 0;
    }

};


#endif //PRUEBAS22_SPRITE_H
