//
// Created by ocastro on 06/11/18.
//
#ifndef INTERFACE_MENUWINDOW_H
#define INTERFACE_MENUWINDOW_H





#include <iostream>
#include <SFML/Graphics.hpp>
#include "information.cpp"
#include "Application.cpp"
#include "Application2.cpp"
#include "Application3.cpp"
#include "cmake-build-debug/menu.cpp"

class MenuWindow {

public:
    /**
     * Constructor desctructor
     */
    MenuWindow();
    ~MenuWindow();
    /**
     *
     * @return
     */
    int dramMenuWindow();

};


MenuWindow::MenuWindow() {}

MenuWindow::~MenuWindow() {}

int MenuWindow::dramMenuWindow() {

    sf::RenderWindow window(sf::VideoMode(1024,768), "DIGIMON");
    


    Menu menu(window.getSize().x, window.getSize().y);


    while (window.isOpen()){

        sf::Event event;

        while (window.pollEvent(event)){

            switch (event.type){

                case sf::Event::KeyReleased:
                    switch (event.key.code){

                        case sf::Keyboard::Up:
                            menu.Moveup();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem()){
                                case 0:{
                                    std::cout<<"facil"<<std::endl;
                                    window.close();
                                    auto *app = new Application();

                                    break;
                                }
                                case 1:{
                                    std::cout<<"normal"<<std::endl;
                                    window.close();
                                    auto *app = new Application2();

                                    break;
                                }
                                case 2:{
                                    std::cout<<"dificil"<<std::endl;
                                    window.close();
                                    auto *app = new Application3();
                                    break;
                                }
                                case 3: {
                                    std::cout << "informatio" << std::endl;

                                    Information information;



                                }
                                    break;

                                case 4:
                                    window.close();
                                    break;
                            }
                    }
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        window.clear();

        menu.draw(window);

        window.display();
    }
}
#endif //INTERFACE_MENUWINDOW_H