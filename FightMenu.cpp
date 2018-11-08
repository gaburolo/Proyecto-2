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

FightMenu::FightMenu(float windth, float height)  {

    font.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/res/font.TTF");



    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Atack1");
    menu[0].setPosition(sf::Vector2f(windth/28, 550));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Atack2");
    menu[1].setPosition(sf::Vector2f(windth/4.8, 550));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::Black);
    menu[2].setString("Atack3");
    menu[2].setPosition(sf::Vector2f(windth/2.6, 550));

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::Black);
    menu[3].setString("Atack4");
    menu[3].setPosition(sf::Vector2f(windth/1.8, 550));

    menu[4].setFont(font);
    menu[4].setColor(sf::Color::Black);
    menu[4].setString("Atack5");
    menu[4].setPosition(sf::Vector2f(windth/1.377, 550));

    menu[5].setFont(font);
    menu[5].setColor(sf::Color::Black);
    menu[5].setString("Atack6");
    menu[5].setPosition(sf::Vector2f(windth/28, 600));

    menu[6].setFont(font);
    menu[6].setColor(sf::Color::Black);
    menu[6].setString("Atack7");
    menu[6].setPosition(sf::Vector2f(windth/4.8, 600));

    menu[7].setFont(font);
    menu[7].setColor(sf::Color::Black);
    menu[7].setString("Atack8");
    menu[7].setPosition(sf::Vector2f(windth/2.6, 600));

    menu[8].setFont(font);
    menu[8].setColor(sf::Color::Black);
    menu[8].setString("Atack9");
    menu[8].setPosition(sf::Vector2f(windth/1.8, 600));

    menu[9].setFont(font);
    menu[9].setColor(sf::Color::Black);
    menu[9].setString("Atack10");
    menu[9].setPosition(sf::Vector2f(windth/1.377, 600));

    menu[10].setFont(font);
    menu[10].setColor(sf::Color::Black);
    menu[10].setString("Atack11");
    menu[10].setPosition(sf::Vector2f(windth/4, height/ (MAX_NUMBERS_OF_ITEMS + 1) * 12));

    menu[11].setFont(font);
    menu[11].setColor(sf::Color::Black);
    menu[11].setString("Atack12");
    menu[11].setPosition(sf::Vector2f(windth/2, height/ (MAX_NUMBERS_OF_ITEMS + 1) * 12));

    selectedItemIndex = 0;


}

FightMenu::~FightMenu()  {

}

void FightMenu::draw(sf::RenderWindow &window) {

    for (int i = 0; i < MAX_NUMBERS_OF_ITEMS; i++){

        window.draw(menu[i]);
    }
}

void FightMenu::Moveup() {

    if (selectedItemIndex -1 >= 0){

        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void FightMenu::MoveDown(int level) {

    if (selectedItemIndex + 1 < level*2){

        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);

    }
}
#endif //PRUEBAS22_FIGHTMENU_H