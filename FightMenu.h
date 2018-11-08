//
// Created by gaburolo on 08/11/18.
//

#ifndef PRUEBAS22_FIGHTMENU_H
#define PRUEBAS22_FIGHTMENU_H


#include "SFML/Graphics.hpp"


#define MAX_NUMBERS_OF_ITEMS 12


class FightMenu {

public:

    FightMenu (float windth, float height);
    ~FightMenu();

    void draw(sf::RenderWindow &window);
    void Moveup();
    void MoveDown(int level);
    int GetPressedItem(){ return selectedItemIndex;}


private:

    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBERS_OF_ITEMS];

};



#endif //PRUEBAS22_FIGHTMENU_H
