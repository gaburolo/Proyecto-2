//
// Created by ocastro on 06/11/18.
//

#ifndef PRUEBAS_INTERFACE_INFORMATION_H
#define PRUEBAS_INTERFACE_INFORMATION_H



#include <SFML/Graphics.hpp>


class Information {

public:
    Information();

private:

    sf::RenderWindow window2;
    sf::Texture texture;
    sf::Sprite sprite;


};


Information::Information() {

    window2.create(sf::VideoMode(860,511), "Information");
    texture.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/res/info.png");
    sprite.setTexture(texture);
    sprite.setPosition(0,0);


    while (window2.isOpen()){

        sf::Event event1;

        while (window2.pollEvent(event1)){

            switch (event1.type){

                case sf::Event::Closed:
                    window2.close();

                    break;

                case sf::Event::KeyReleased:
                    switch (event1.key.code) {

                        case sf::Keyboard::Up:
                            window2.close();
                            break;
                    }
            }
        }
        window2.clear();
        window2.draw(sprite);
        window2.display();
    }
}
#endif //PRUEBAS_INTERFACE_INFORMATION_H