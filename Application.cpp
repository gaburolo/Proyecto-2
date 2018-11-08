//
// Created by Juan Pablo Martínez Brenes, Martin Calderón Blanco, Olman Castro Hernández on 9/5/18
//



#include "iostream"
#include "Application.h"
#include <SFML/Graphics.hpp>
#include "mapa.cpp"

class Application {
private:


    mapa mp;

    //Application* app=this;
    int i = 0;
    sf::RenderWindow window;




    //Textura y Spride del Fondo
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    //Fuente
    sf::Font headFont;
    sf::Text headText;

    //Texture and Sprite soldier
    sf::Texture digiTextureVa;
    sf::Sprite digiSpriteVa;

    sf::Texture digiTextureVi;
    sf::Sprite digiSpriteVi;

    sf::Texture digiTextureDa;
    sf::Sprite digiSpriteDa;
    //Texture and sprite ENEMY
    sf::Texture enemyTexture;
    sf::Sprite enemySprite;

    sf::Texture enemyTextureVa;
    sf::Sprite enemySpriteVa;

    sf::Texture enemyTextureVi;
    sf::Sprite enemySpriteVi;

    sf::Texture enemyTextureDa;
    sf::Sprite enemySpriteDa;

    //Texture and Sprite Arbol

    sf::Texture treeTexture;
    sf::Sprite treeSprite;




    sf::Text digiText;

    //Textura y Sprite de la Pizza Hawaiiana
    sf::Texture hawaiianTexture;
    sf::Sprite hawaiianSprite;
    sf::Text hawaiianText;

    //Textura Y Sprite de la Pizza Vegetariana
    sf::Texture vegTexture;
    sf::Sprite vegSprite;
    sf::Text vegText;

    //Textura y Sprites de las bandas
    sf::Texture bandTexture;
    sf::Sprite band1Sprite;
    sf::Sprite band2Sprite;


    //Pepperoni
    sf::Texture pepperoniTexture1;



public:
    Application() {

        //mp.imprimir();

        //Creacion de la ventana
        window.create(sf::VideoMode(1024, 768), "DIGIMUNDO",sf::Style::Fullscreen);
        //window.create(sf::VideoMode(1024, 768), "DIGIMUNDO");
        window.setPosition(sf::Vector2<int>(0.0f,0.0f));

        //Carga de texturas para las pizzas, y se les da la posicion
        // background image
        backgroundTexture.loadFromFile(
                "/home/gaburolo/CLionProjects/pruebas22/image/mp2.png");
        backgroundSprite.setTexture(backgroundTexture);

/*        sf::RectangleShape hawaiianButton;
        hawaiianButton.setSize(sf::Vector2f(300.0f, 300.0f));
        hawaiianButton.setPosition(50.0f, 600.0f);*/

        digiTextureVa.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/image/omnimon.png");
        digiSpriteVa.setTexture(digiTextureVa);
        digiTextureVi.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/image/gallantmon.png");
        digiSpriteVi.setTexture(digiTextureVi);
        digiTextureDa.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/image/dynasmon.png");
        digiSpriteDa.setTexture(digiTextureDa);

        enemyTexture.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/image/agumon.png");
        enemySprite.setTexture(enemyTexture);
        enemyTextureVa.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/image/greymon.png");
        enemySpriteVa.setTexture(enemyTextureVa);
        enemyTextureVi.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/image/skullgreymon.png");
        enemySpriteVi.setTexture(enemyTextureVi);
        enemyTextureDa.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/image/seadramon.png");
        enemySpriteDa.setTexture(enemyTextureDa);

        treeTexture.loadFromFile("/home/gaburolo/CLionProjects/pruebas22/image/arbol.png");
        treeSprite.setTexture(treeTexture);

        sf::RectangleShape vegButton;
        vegButton.setSize(sf::Vector2f(300.0f, 300.0f));
        vegButton.setPosition(50.0f, 1000.0f);

        // text and fonts
        /*headFont.loadFromFile(
                "/home/gaburolo/CLionProjects/TareaCorta1/res/font/font.TTF");
        headText.setFont(headFont);
        headText.setString("PRESS A PIZZA\nTO COOK IT");
        headText.setCharacterSize(40);
        headText.setColor(sf::Color::White);
        headText.setPosition(50, 50);
*/





        //Ciclo del juego
        while (window.isOpen()) {
            sf::Event event{};


            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::KeyPressed:
                        if(event.key.code==sf::Keyboard::Escape){
                            window.close();
                        }

                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {

                    int num,num2;

                    int x,y=0;
                    num=sf::Mouse::getPosition().x;
                    num2=sf::Mouse::getPosition().y;
                    mp.obtenerXY(num, num2, x, y);
                    std::cout<<mp.listaY[y].get_Data(x).nombre<<std::endl;
                    mp.mover(x,y);
                    draw();
                    ////mp.deteccionE();
                    //std::cout<<"PRESIONANDO X: "<<sf::Mouse::getPosition().x<<" Y: "<<sf::Mouse::getPosition().y<<std::endl;


                }

            }




            loopApp();

                sf::sleep(sf::milliseconds(200));
        }

    }

    /*
     * Llama al metodo draw para pintar los sprites
     */
    void loopApp() {
        draw();
    }
    /*
     * Limpia la pantalla
     * Pinta cada uno de los Sprites
     * Muestra la pantalla
     */

    void moveDigi(){
        int t=0;
        int o=3;
        while(o<14){
            mp.listaY[t].get_Nodo(o)->data.posx+=1;
            mp.listaY[0].get_Nodo(o+1)->data=mp.listaY[0].get_Nodo(o)->data;
            mp.listaY[0].get_Nodo(o)->data=mp.vacio;
            mp.actualizarXY();
            sf::sleep(sf::milliseconds(200));
            draw();
            o++;
        }
    }

public:
    void draw() {

        window.clear();
        window.draw(backgroundSprite);
        for(int i=0;i<15;i++){
            for(int j=0;j<15;j++){
                if(mp.listaY[i].get_Nodo(j)->data.nombre=="soldado" && mp.listaY[i].get_Nodo(j)->data.elemento=='v'){
                    digiSpriteVa.setPosition(mp.listaY[i].get_Nodo(j)->X,mp.listaY[i].get_Nodo(j)->posY);
                    window.draw(digiSpriteVa);
                }else if(mp.listaY[i].get_Nodo(j)->data.nombre=="soldado" && mp.listaY[i].get_Nodo(j)->data.elemento=='d'){
                    digiSpriteDa.setPosition(mp.listaY[i].get_Nodo(j)->X,mp.listaY[i].get_Nodo(j)->posY);
                    window.draw(digiSpriteDa);
                }else if(mp.listaY[i].get_Nodo(j)->data.nombre=="soldado" && mp.listaY[i].get_Nodo(j)->data.elemento=='x'){
                    digiSpriteVi.setPosition(mp.listaY[i].get_Nodo(j)->X,mp.listaY[i].get_Nodo(j)->posY);
                    window.draw(digiSpriteVi);
                }else if(mp.listaY[i].get_Nodo(j)->data.nombre=="Enemigo" && mp.listaY[i].get_Nodo(j)->data.elemento=='n'){
                    enemySprite.setPosition(mp.listaY[i].get_Nodo(j)->X,mp.listaY[i].get_Nodo(j)->posY);
                    window.draw(enemySprite);
                }if(mp.listaY[i].get_Nodo(j)->data.nombre=="arbol"){
                    treeSprite.setPosition(mp.listaY[i].get_Nodo(j)->X,mp.listaY[i].get_Nodo(j)->posY);
                    window.draw(treeSprite);
                }
            }
        }


        //
        // digiSpriteVa.setPosition(100,100);

      window.display();
    }

};
