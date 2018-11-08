//
// Created by gaburolo on 08/11/18.
//

#ifndef PRUEBAS22_ATACKWINDOW_H
#define PRUEBAS22_ATACKWINDOW_H

#include "Sprite.cpp"
#include "SFML/Graphics.hpp"


class AtackWindow {


public:

    AtackWindow();
    ~AtackWindow();
    int drawAtackWindow(Sprite soldado, Sprite enemigo, int level);

public:

    sf::Font font;
    sf::Text staminaSoldado;
    sf::Text staminaEnemigo;
    int ventana;


};


#endif //PRUEBAS22_ATACKWINDOW_H
