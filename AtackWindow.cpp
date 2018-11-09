//
// Created by gaburolo on 08/11/18.
//
#ifndef PRUEBAS22_ATACKWINDOW_H
#define PRUEBAS22_ATACKWINDOW_H
#include "iostream"

#include "FightMenu.cpp"
#include "SFML/Graphics.hpp"



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





AtackWindow::AtackWindow (){

}

AtackWindow::~AtackWindow() {}

int AtackWindow::drawAtackWindow(Sprite soldado, Sprite enemigo, int level){

    ventana = 1;

    sf::RenderWindow windowAtack(sf::VideoMode(1024,768), "ATACK");

    sf::Texture fondoTexture;
    sf::Sprite fondoSprite;

    fondoTexture.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/image/fondo.png");
    fondoSprite.setTexture(fondoTexture);

    sf::Texture digiTextureVa;
    sf::Sprite digiSpriteVa;

    sf::Texture digiTextureVi;
    sf::Sprite digiSpriteVi;

    sf::Texture digiTextureDa;
    sf::Sprite digiSpriteDa;

    digiTextureVa.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/image/omnimon.png");
    digiSpriteVa.setTexture(digiTextureVa);
    digiTextureVi.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/image/gallantmon.png");
    digiSpriteVi.setTexture(digiTextureVi);
    digiTextureDa.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/image/dynasmon.png");
    digiSpriteDa.setTexture(digiTextureDa);

    sf::Texture enemyTexture;
    sf::Sprite enemySprite;

    sf::Texture enemyTextureVa;
    sf::Sprite enemySpriteVa;

    sf::Texture enemyTextureVi;
    sf::Sprite enemySpriteVi;

    sf::Texture enemyTextureDa;
    sf::Sprite enemySpriteDa;

    enemyTexture.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/image/agumon.png");
    enemySprite.setTexture(enemyTexture);
    enemyTextureVa.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/image/greymon.png");
    enemySpriteVa.setTexture(enemyTextureVa);
    enemyTextureVi.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/image/skullgreymon.png");
    enemySpriteVi.setTexture(enemyTextureVi);
    enemyTextureDa.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/image/seadramon.png");
    enemySpriteDa.setTexture(enemyTextureDa);

    sf::RectangleShape shape1(sf::Vector2f(soldado.getStamina(),20));
    shape1.setFillColor(sf::Color::Green);
    shape1.setPosition(250,50);

    sf::RectangleShape shape2(sf::Vector2f(100, 20));
    shape2.setFillColor(sf::Color::Red);
    shape2.setPosition(250,50);

    sf::RectangleShape shape3(sf::Vector2f(enemigo.getStamina(), 20));
    shape3.setFillColor((sf::Color::Green));
    shape3.setPosition(650, 50);

    sf::RectangleShape shape4(sf::Vector2f(100, 20));
    shape4.setFillColor(sf::Color::Red);
    shape4.setPosition(650,50);

    font.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/res/font.TTF");

    staminaEnemigo.setFont(font);
    staminaEnemigo.setColor(sf::Color::White);
    staminaEnemigo.setCharacterSize(10);
    staminaEnemigo.setPosition(sf::Vector2f(690,55));

    staminaSoldado.setFont(font);
    staminaSoldado.setColor(sf::Color::White);
    staminaSoldado.setCharacterSize(10);
    staminaSoldado.setPosition(sf::Vector2f(290,55));


    FightMenu fightMenu(windowAtack.getSize().x, windowAtack.getSize().y);

    while (windowAtack.isOpen()){

        sf::Event event;

        shape1.setSize(sf::Vector2f(soldado.getStamina(),20));
        shape3.setSize(sf::Vector2f(enemigo.getStamina(),20));

        while (windowAtack.pollEvent(event)){

            switch (event.type){

                case sf::Event::KeyReleased:
                    switch (event.key.code){

                        case sf::Keyboard::Left:
                            fightMenu.Moveup();
                            break;

                        case sf::Keyboard::Right:
                            fightMenu.MoveDown(level);
                            break;

                        case sf::Keyboard::Return:
                            switch (fightMenu.GetPressedItem()){
                                case 0:
                                    std::cout<<"Atack1"<<std::endl;
                                    enemigo.atacar(1,soldado.getTipo());
                                    ventana = soldado.atacado(enemigo.getTipo());
                                    break;

                                case 1:
                                    std::cout<<"Atack2"<<std::endl;
                                    enemigo.atacar(2,soldado.getTipo());
                                    ventana = soldado.atacado(enemigo.getTipo());
                                    break;

                                case 2:
                                    std::cout<<"Atack3"<<std::endl;
                                    enemigo.atacar(3,soldado.getTipo());
                                    ventana = soldado.atacado(enemigo.getTipo());
                                    break;

                                case 3:
                                    std::cout << "Atack4" << std::endl;
                                    enemigo.atacar(4,soldado.getTipo());
                                    ventana = soldado.atacado(enemigo.getTipo());
                                    break;

                                case 4:
                                    std::cout << "Atack5" << std::endl;
                                    enemigo.atacar(5,soldado.getTipo());
                                    ventana = soldado.atacado(enemigo.getTipo());
                                    break;

                                case 5:
                                    std::cout << "Atack6" << std::endl;
                                    enemigo.atacar(6,soldado.getTipo());
                                    ventana = soldado.atacado(enemigo.getTipo());
                                    break;

                                case 6:
                                    std::cout << "Atack7" << std::endl;
                                    enemigo.atacar(7,soldado.getTipo());
                                    ventana = soldado.atacado(enemigo.getTipo());
                                    break;

                                case 7:
                                    std::cout << "Atack8" << std::endl;
                                    enemigo.atacar(8,soldado.getTipo());
                                    ventana = soldado.atacado(enemigo.getTipo());
                                    break;

                                case 8:
                                    std::cout << "Atack9" << std::endl;
                                    enemigo.atacar(9,soldado.getTipo());
                                    ventana = soldado.atacado(enemigo.getTipo());
                                    break;

                                case 9:
                                    std::cout << "Atack10" << std::endl;
                                    enemigo.atacar(10,soldado.getTipo());
                                    ventana = soldado.atacado(enemigo.getTipo());
                                    break;

                                case 10:
                                    std::cout << "Atack11" << std::endl;
                                    enemigo.atacar(11,soldado.getTipo());
                                    ventana = soldado.atacado(enemigo.getTipo());
                                    break;

                                case 11:
                                    std::cout << "Atack12" << std::endl;
                                    enemigo.atacar(12,soldado.getTipo());
                                    ventana = soldado.atacado(enemigo.getTipo());
                                    break;

                            }
                    }
                    break;

                case sf::Event::Closed:
                    windowAtack.close();
                    break;
            }
        }

        if (ventana == 0 || enemigo.getStamina() <= 0) {
            if (enemigo.getStamina() < 0) {
                enemigo.changeStamina();
            }
            if (soldado.getStamina() < 0) {
                soldado.changeStamina();
            }
            shape1.setSize(sf::Vector2f(soldado.getStamina(),20));
            shape3.setSize(sf::Vector2f(enemigo.getStamina(),20));
            windowAtack.clear();
            fondoSprite.setPosition(180,50);
            windowAtack.draw(fondoSprite);
            if (soldado.getTipo() == 'x'){
                digiSpriteVi.setPosition(300, 400);
                windowAtack.draw(digiSpriteVi);

            }
            else if (soldado.getTipo() == 'd'){
                digiSpriteDa.setPosition(300,400);
                windowAtack.draw(digiSpriteDa);

            }
            else if (soldado.getTipo() == 'v'){
                digiSpriteVa.setPosition(300,400);
                windowAtack.draw(digiSpriteVa);

            }
            fightMenu.draw(windowAtack);
            windowAtack.draw(shape2);
            windowAtack.draw(shape1);
            windowAtack.draw(shape4);
            windowAtack.draw(shape3);
            staminaSoldado.setString(std::to_string(soldado.getStamina()));
            staminaEnemigo.setString(std::to_string(enemigo.getStamina()));
            windowAtack.draw(staminaSoldado);
            windowAtack.draw(staminaEnemigo);
            windowAtack.display();

            if(ventana==0 && enemigo.getStamina() == 0){
                sf::sleep(sf::microseconds(1000000));
                enemigo.digievolucion(soldado.getTipo());
                windowAtack.close();
                return 3;
            }

            else if (ventana == 0){
                sf::sleep(sf::microseconds(1000000));
                windowAtack.close();
                return 2;
            }
            else if (enemigo.getStamina() == 0){
                sf::sleep(sf::microseconds(1000000));
                enemigo.digievolucion(soldado.getTipo());
                std::cout<<enemigo.getTipo();
                windowAtack.close();
                return 1;
            }






        } else{
            windowAtack.clear();
            fondoSprite.setPosition(180,50);
            windowAtack.draw(fondoSprite);
            if (enemigo.getTipo() == 'n'){
                enemySprite.setPosition(640, 400);
                windowAtack.draw(enemySprite);

            }
            else if (enemigo.getTipo() == 'x'){
                enemySpriteVi.setPosition(640, 400);
                windowAtack.draw(enemySpriteVi);

            }
            else if (enemigo.getTipo() == 'd'){
                enemySpriteDa.setPosition(640,400);
                windowAtack.draw(enemySpriteDa);

            }
            else if (enemigo.getTipo() == 'v'){
                enemySpriteVa.setPosition(640,400);
                windowAtack.draw(enemySpriteVa);

            }

            if (soldado.getTipo() == 'x'){
                digiSpriteVi.setPosition(300, 400);
                windowAtack.draw(digiSpriteVi);

            }
            else if (soldado.getTipo() == 'd'){
                digiSpriteDa.setPosition(300,400);
                windowAtack.draw(digiSpriteDa);

            }
            else if (soldado.getTipo() == 'v'){
                digiSpriteVa.setPosition(300,400);
                windowAtack.draw(digiSpriteVa);

            }



            fightMenu.draw(windowAtack);
            windowAtack.draw(shape2);
            windowAtack.draw(shape1);
            windowAtack.draw(shape4);
            windowAtack.draw(shape3);
            staminaSoldado.setString(std::to_string(soldado.getStamina()));
            staminaEnemigo.setString(std::to_string(enemigo.getStamina()));
            windowAtack.draw(staminaSoldado);
            windowAtack.draw(staminaEnemigo);
            windowAtack.display();

        }


    }

}
#endif //PRUEBAS22_ATACKWINDOW_H