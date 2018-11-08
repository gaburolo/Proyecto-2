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
    void digievolucion(char type){

        if (type == 'x'){
            elemento = 'v';
            stamina = 100;
        }
        else if (type == 'd'){
            elemento = 'x';
            stamina = 100;
        }
        else if (type =='v'){
            elemento = 'd';
            stamina = 100;
        }else {
            elemento = type;
            stamina=100;

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
        else if (elemento == 'n'){
            if (tipo == 'x'){
                stamina = stamina - 25;
                if (stamina <= 0){
                    return 0;
                }
                else{
                    return stamina;
                }
            }
            else if (tipo == 'd'){
                stamina = stamina - 25;
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
                if (elemento == 'n'){
                    stamina = 0;
                    break;
                }
                switch (type){
                    case 'v':
                        stamina = stamina - (5*5);
                        std::cout<<stamina;
                        break;

                    case 'x':
                        stamina = stamina - 5*3;
                        std::cout<<stamina;
                        break;

                    case 'd':
                        stamina = stamina - 5*3;
                        std::cout<<stamina;
                        break;

                    case 'n':
                        stamina = stamina - 100;
                        std::cout<<stamina;
                        break;

                }
                break;


            case 2:
                if (elemento == 'n'){
                    stamina = 0;
                    break;
                }
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

                    case 'n':
                        stamina = stamina - 100;
                        break;
                }
                break;

            case 3:
                if (elemento == 'n'){
                    stamina = 0;
                    break;
                }
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

                    case 'n':
                        stamina = stamina - 100;
                        break;
                }
                break;

            case 4:
                if (elemento == 'n'){
                    stamina = 0;
                    break;
                }
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

                    case 'n':
                        stamina = stamina - 100;
                        std::cout<<stamina;
                        break;

                }
                break;

            case 5:
                if (elemento == 'n'){
                    stamina = 0;
                    break;
                }
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

                    case 'n':
                        stamina = stamina - 100;
                        std::cout<<stamina;
                        break;

                }
                break;

            case 6:
                if (elemento == 'n'){
                    stamina = 0;
                    break;
                }
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

                    case 'n':
                        stamina = stamina - 100;
                        std::cout<<stamina;
                        break;

                }
                break;

            case 7:
                if (elemento == 'n'){
                    stamina = 0;
                    break;
                }
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

                    case 'n':
                        stamina = stamina - 100;
                        std::cout<<stamina;
                        break;

                }
                break;

            case 8:
                if (elemento == 'n'){
                    stamina = 0;
                    break;
                }
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

                    case 'n':
                        stamina = stamina - 100;
                        std::cout<<stamina;
                        break;

                }
                break;

            case 9:
                if (elemento == 'n'){
                    stamina = 0;
                    break;
                }
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

                    case 'n':
                        stamina = stamina - 100;
                        std::cout<<stamina;
                        break;

                }
                break;

            case 10:
                if (elemento == 'n'){
                    stamina = 0;
                    break;
                }
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

                    case 'n':
                        stamina = stamina - 100;
                        std::cout<<stamina;
                        break;
                }
                break;

            case 11:
                if (elemento == 'n'){
                    stamina = 0;
                    break;
                }
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

                    case 'n':
                        stamina = stamina - 100;
                        std::cout<<stamina;
                        break;

                }
                break;

            case 12:
                if (elemento == 'n'){
                    stamina = 0;
                    break;
                }
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

                    case 'n':
                        stamina = stamina - 100;
                        std::cout<<stamina;
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
