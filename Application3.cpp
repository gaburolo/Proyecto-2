//
// Created by Juan Pablo Martínez Brenes, Martin Calderón Blanco, Olman Castro Hernández on 9/5/18
//



#include "iostream"
#include "Application3.h"
#include <SFML/Graphics.hpp>
#include "mapa3.cpp"

class Application3 {
private:


    mapa3 mp;
    int nSol=0;
    int movimientos=0;

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



public:
    Application3() {

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
        headFont.loadFromFile(
                "/home/gaburolo/CLionProjects/TareaCorta1/res/font/font.TTF");
        headText.setFont(headFont);
        headText.setCharacterSize(40);
        headText.setColor(sf::Color::White);







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

                    if(mp.listaY[y].get_Data(x).nombre=="soldado"){
                        for(int i=0;i<mp.listaY[y].get_Nodo(x)->data.con;i++) {
                            headText.setPosition(sf::Vector2f(780, i * 50));
                            headText.setString(std::to_string(mp.listaY[y].get_Nodo(x)->data.visitados[i]));
                            window.draw(headText);
                            window.display();
                        }

                    }else{
                        mover(x,y);
                        draw();
                    }

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
        window.draw(headText);
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
                }else if(mp.listaY[i].get_Nodo(j)->data.nombre=="arbol"){
                    treeSprite.setPosition(mp.listaY[i].get_Nodo(j)->X,mp.listaY[i].get_Nodo(j)->posY);
                    window.draw(treeSprite);
                }else if(mp.listaY[i].get_Nodo(j)->data.nombre=="Enemigo" && mp.listaY[i].get_Nodo(j)->data.elemento=='v'){
                    enemySpriteVa.setPosition(mp.listaY[i].get_Nodo(j)->X,mp.listaY[i].get_Nodo(j)->posY);
                    window.draw(enemySpriteVa);
                }else if(mp.listaY[i].get_Nodo(j)->data.nombre=="Enemigo" && mp.listaY[i].get_Nodo(j)->data.elemento=='x'){
                    enemySpriteVi.setPosition(mp.listaY[i].get_Nodo(j)->X,mp.listaY[i].get_Nodo(j)->posY);
                    window.draw(enemySpriteVi);
                }else if(mp.listaY[i].get_Nodo(j)->data.nombre=="Enemigo" && mp.listaY[i].get_Nodo(j)->data.elemento=='d'){
                    enemySpriteDa.setPosition(mp.listaY[i].get_Nodo(j)->X,mp.listaY[i].get_Nodo(j)->posY);
                    window.draw(enemySpriteDa);
                }
            }
        }


        //
        // digiSpriteVa.setPosition(100,100);

      window.display();
    }mapa3& mover(int posx, int posy) {

        mp.deteccionE();
        sf::sleep(sf::milliseconds(200));

        movimientos++;
        if(nSol==15){
            nSol=0;
            return mp;
        }
        else if(movimientos!=20)
        {
                mp.Soldados.get_Nodo(nSol)->data.visitados[0]=00;
                for(int ptr=nSol-1;ptr>=0;ptr--){
                    if (nSol!=0 && mp.Soldados.get_Data(nSol).posx==mp.Soldados.get_Data(ptr).posx && mp.Soldados.get_Data(nSol).posy+1==mp.Soldados.get_Data(ptr).posy){
                        nSol++;
                        movimientos = 0;
                        return mover(posx,posy);
                    }else if (nSol!=0 && mp.Soldados.get_Data(nSol).posy==mp.Soldados.get_Data(ptr).posy && mp.Soldados.get_Data(nSol).posx+1==mp.Soldados.get_Data(ptr).posx){
                        nSol++;
                        movimientos = 0;
                        return mover(posx,posy);
                    }
                }

        }else{
            nSol++;
            movimientos = 0;
            return mover(posx,posy);
        }
        if(mp.Soldados.get_Nodo(nSol)->data.nombre!="soldado"){
            nSol++;
            movimientos = 0;
            return mover(posx,posy);
        }else if (nSol!=0 && mp.Soldados.get_Data(nSol).posx==mp.Soldados.get_Data(nSol-1).posx && mp.Soldados.get_Data(nSol).posy+1==mp.Soldados.get_Data(nSol-1).posy){
            nSol++;
            movimientos = 0;
            return mover(posx,posy);
        }else if (nSol!=0 && mp.Soldados.get_Data(nSol).posy==mp.Soldados.get_Data(nSol-1).posy && mp.Soldados.get_Data(nSol).posx+1==mp.Soldados.get_Data(nSol-1).posx){
            nSol++;
            movimientos = 0;
            return mover(posx,posy);
        }
        else if(mp.Soldados.get_Data(nSol).posx==14 && mp.Soldados.get_Data(nSol).posy==14){

            mp.vacio.posx=mp.Soldados.get_Nodo(3)->data.posx;
            mp.vacio.posy=mp.Soldados.get_Nodo(3)->data.posy;
            mp.Soldados.get_Nodo(3)->data=mp.vacio;


            mp.nivel++;
            mp.reinicio();
            if(mp.nivel==6){
                std::cout<<"your WIN"<<std::endl;
            }



        }

        else if (mp.Soldados.get_Data(nSol).posx==posx && mp.Soldados.get_Data(nSol).posy==posy) {
            nSol++;
            movimientos = 0;
            if(nSol!=15){
                return mover(posx,posy);
            }else{

            }

            /*
            cont=0;
            x=0;
            y=0;
            */
        }
        else if(mp.Soldados.get_Data(nSol).posy!=posy && mp.Soldados.get_Data(nSol).posx!=posx) {

            if(mp.listaY[mp.Soldados.get_Data(nSol).posy+1].get_Nodo(mp.Soldados.get_Data(nSol).posx+1)->data.nombre=="vacio"){
                mp.Soldados.get_Nodo(nSol)->data.posx+=1;
                mp.Soldados.get_Nodo(nSol)->data.posy+=1;
                //listaY[Soldados.get_Data(3).posx+1].get_Nodo(Soldados.get_Data(3).posy+1)->data=Soldados.get_Data(3);

                mp.Soldados.get_Nodo(nSol)->data.con++;



                mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);

                mp.agregarSprites();
                mp.actualizarXY();
                mp.imprimir();
                std::cout<<std::endl;
                draw();
                return mover(posx, posy);
            }
            else if(mp.listaY[mp.Soldados.get_Data(nSol).posy+1].get_Nodo(mp.Soldados.get_Data(nSol).posx)->data.nombre=="vacio"){
                mp.Soldados.get_Nodo(nSol)->data.posy+=1;
                mp.Soldados.get_Nodo(nSol)->data.con++;
                mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);



                mp.agregarSprites();
                mp.actualizarXY();
                mp.imprimir();
                std::cout<<std::endl;
                draw();
                return mover(posx, posy);
            }else if(mp.listaY[mp.Soldados.get_Data(nSol).posy].get_Nodo(mp.Soldados.get_Data(nSol).posx+1)->data.nombre=="vacio"){
                mp.Soldados.get_Nodo(nSol)->data.posx+=1;
                mp.Soldados.get_Nodo(nSol)->data.con++;
                mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);



                mp.agregarSprites();
                mp.actualizarXY();
                mp.imprimir();
                draw();
                std::cout<<std::endl;
                return mover(posx, posy);
            }else if(mp.Soldados.get_Data(nSol).posx==0 && mp.listaY[mp.Soldados.get_Data(nSol).posy+1].get_Nodo(mp.Soldados.get_Data(nSol).posx-1)->data.nombre=="vacio"){
                mp.Soldados.get_Nodo(nSol)->data.posy+=1;
                mp.Soldados.get_Nodo(nSol)->data.posx-=1;
                mp.Soldados.get_Nodo(nSol)->data.con++;
                mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);

                mp.agregarSprites();
                mp.actualizarXY();
                mp.imprimir();

                std::cout<<std::endl;
                draw();
                return mover(posx, posy);
            }else if(mp.Soldados.get_Data(nSol).posx==0 && mp.listaY[mp.Soldados.get_Data(nSol).posy].get_Nodo(mp.Soldados.get_Data(nSol).posx-1)->data.nombre=="vacio"){

                mp.Soldados.get_Nodo(nSol)->data.posx-=1;
                mp.Soldados.get_Nodo(nSol)->data.con++;
                mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);

                mp.agregarSprites();
                mp.actualizarXY();
                mp.imprimir();
                std::cout<<std::endl;
                draw();
                return mover(posx, posy);
            }else if(mp.Soldados.get_Data(nSol).posy==0 && mp.listaY[mp.Soldados.get_Data(nSol).posy-1].get_Nodo(mp.Soldados.get_Data(nSol).posx)->data.nombre=="vacio"){

                mp.Soldados.get_Nodo(nSol)->data.posy-=1;
                mp.Soldados.get_Nodo(nSol)->data.con++;
                mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);



                mp.agregarSprites();
                mp.actualizarXY();
                mp.imprimir();
                std::cout<<std::endl;
                draw();
                return mover(posx, posy);
            }else if(mp.Soldados.get_Data(nSol).posy==0 && mp.listaY[mp.Soldados.get_Data(nSol).posy-1].get_Nodo(mp.Soldados.get_Data(nSol).posx+1)->data.nombre=="vacio"){
                mp.Soldados.get_Nodo(nSol)->data.posx+=1;
                mp.Soldados.get_Nodo(nSol)->data.posy-=1;
                mp.Soldados.get_Nodo(nSol)->data.con++;
                mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);



                mp.agregarSprites();
                mp.actualizarXY();
                mp.imprimir();
                std::cout<<std::endl;
                draw();
                return mover(posx, posy);
            }else if(mp.Soldados.get_Data(nSol).posx==0&&mp.Soldados.get_Data(nSol).posy==0 && mp.listaY[mp.Soldados.get_Data(nSol).posy-1].get_Nodo(mp.Soldados.get_Data(nSol).posx-1)->data.nombre=="vacio"){
                mp.Soldados.get_Nodo(nSol)->data.posy-=1;
                mp.Soldados.get_Nodo(nSol)->data.posy-=1;
                mp.Soldados.get_Nodo(nSol)->data.con++;
                mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);



                mp.agregarSprites();
                mp.actualizarXY();
                mp.imprimir();
                std::cout<<std::endl;
                draw();
                return mover(posx, posy);
            }

            else {

                return goToThePast(posx,posy);
                //throw new IllegalArgumentException("NO HAY CAMINO");
            }

        }else if(mp.Soldados.get_Data(nSol).posx==posx) {
            std::cout<<"sdasdasdwasdasdas"<<std::endl;
            return moverXsiete(posx,posy);
        }else if(mp.Soldados.get_Data(nSol).posy==posy) {
            return moverYsiete(posx,posy);
        }
        else {
            throw "NEL PRRO";
        }



    }
    mapa3& moverXsiete(int posx, int posy) {
        if(mp.listaY[mp.Soldados.get_Data(nSol).posy+1].get_Nodo(mp.Soldados.get_Data(nSol).posx)->data.nombre=="vacio"){
            mp.Soldados.get_Nodo(nSol)->data.posy+=1;
            mp.Soldados.get_Nodo(nSol)->data.con++;
            mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);



            mp.agregarSprites();
            mp.actualizarXY();
            mp.imprimir();
            std::cout<<std::endl;
            draw();
            return mover(posx, posy);
        }else if(mp.listaY[mp.Soldados.get_Data(nSol).posy+1].get_Nodo(mp.Soldados.get_Data(nSol).posx-1)->data.nombre=="vacio"){
            mp.Soldados.get_Nodo(nSol)->data.posy+=1;
            mp.Soldados.get_Nodo(nSol)->data.posx-=1;
            mp.Soldados.get_Nodo(nSol)->data.con++;
            mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);

            mp.agregarSprites();
            mp.actualizarXY();
            mp.imprimir();
            std::cout<<std::endl;
            draw();
            return mover(posx, posy);
        }else if(mp.listaY[mp.Soldados.get_Data(nSol).posy].get_Nodo(mp.Soldados.get_Data(nSol).posx-1)->data.nombre=="vacio"){

            mp.Soldados.get_Nodo(nSol)->data.posx-=1;
            mp.Soldados.get_Nodo(nSol)->data.con++;
            mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);

            mp.agregarSprites();
            mp.actualizarXY();
            mp.imprimir();
            draw();
            std::cout<<std::endl;
            return mover(posx, posy);
        }else if(mp.listaY[mp.Soldados.get_Data(nSol).posy-1].get_Nodo(mp.Soldados.get_Data(nSol).posx-1)->data.nombre=="vacio"){
            mp.Soldados.get_Nodo(nSol)->data.posy-=1;
            mp.Soldados.get_Nodo(nSol)->data.posy-=1;
            mp.Soldados.get_Nodo(nSol)->data.con++;
            mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);



            mp.agregarSprites();
            mp.actualizarXY();
            mp.imprimir();
            std::cout<<std::endl;
            draw();
            return mover(posx, posy);
        }else if(mp.listaY[mp.Soldados.get_Data(nSol).posy-1].get_Nodo(mp.Soldados.get_Data(nSol).posx)->data.nombre=="vacio"){

            mp.Soldados.get_Nodo(nSol)->data.posy-=1;
            mp.Soldados.get_Nodo(nSol)->data.con++;
            mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);



            mp.agregarSprites();
            mp.actualizarXY();
            mp.imprimir();

            std::cout<<std::endl;
            draw();
            return mover(posx, posy);
        }else {

            return goToThePast(posx,posy);

        }

    }
    mapa3& moverYsiete(int posx, int posy) {
        if(mp.listaY[mp.Soldados.get_Data(nSol).posy].get_Nodo(mp.Soldados.get_Data(nSol).posx+1)->data.nombre=="vacio"){
            mp.Soldados.get_Nodo(nSol)->data.posx+=1;
            mp.Soldados.get_Nodo(nSol)->data.con++;
            mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);



            mp.agregarSprites();
            mp.actualizarXY();
            mp.imprimir();
            std::cout<<std::endl;
            draw();
            return mover(posx, posy);
        }else if(mp.Soldados.get_Data(nSol).posy==0 && mp.listaY[mp.Soldados.get_Data(nSol).posy-1].get_Nodo(mp.Soldados.get_Data(nSol).posx+1)->data.nombre=="vacio"){
            mp.Soldados.get_Nodo(nSol)->data.posx+=1;
            mp.Soldados.get_Nodo(nSol)->data.posy-=1;
            mp.Soldados.get_Nodo(nSol)->data.con++;
            mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);



            mp.agregarSprites();
            mp.actualizarXY();
            mp.imprimir();
            std::cout<<std::endl;
            draw();
            return mover(posx, posy);
        }else if(mp.Soldados.get_Data(nSol).posy==0 && mp.listaY[mp.Soldados.get_Data(nSol).posy-1].get_Nodo(mp.Soldados.get_Data(nSol).posx)->data.nombre=="vacio"){

            mp.Soldados.get_Nodo(nSol)->data.posy-=1;
            mp.Soldados.get_Nodo(nSol)->data.con++;
            mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);



            mp.agregarSprites();
            mp.actualizarXY();
            mp.imprimir();
            std::cout<<std::endl;
            draw();
            return mover(posx, posy);
        }else if(mp.listaY[mp.Soldados.get_Data(nSol).posy-1].get_Nodo(mp.Soldados.get_Data(nSol).posx)->data.nombre=="vacio"){

            mp.Soldados.get_Nodo(nSol)->data.posy-=1;
            mp.Soldados.get_Nodo(nSol)->data.con++;
            mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);



            mp.agregarSprites();
            mp.actualizarXY();
            mp.imprimir();
            std::cout<<std::endl;
            draw();
            return mover(posx, posy);
        }else if(mp.Soldados.get_Data(nSol).posx==0&&mp.Soldados.get_Data(nSol).posy==0 && mp.listaY[mp.Soldados.get_Data(nSol).posy-1].get_Nodo(mp.Soldados.get_Data(nSol).posx-1)->data.nombre=="vacio"){
            mp.Soldados.get_Nodo(nSol)->data.posy-=1;
            mp.Soldados.get_Nodo(nSol)->data.posy-=1;
            mp.Soldados.get_Nodo(nSol)->data.con++;
            mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);



            mp.agregarSprites();
            mp.actualizarXY();
            mp.imprimir();
            std::cout<<std::endl;
            draw();
            return mover(posx, posy);
        }else if(mp.Soldados.get_Data(nSol).posx==0 && mp.listaY[mp.Soldados.get_Data(nSol).posy].get_Nodo(mp.Soldados.get_Data(nSol).posx-1)->data.nombre=="vacio"){

            mp.Soldados.get_Nodo(nSol)->data.posx-=1;
            mp.Soldados.get_Nodo(nSol)->data.con++;
            mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]=(mp.Soldados.get_Nodo(nSol)->data.posx)*10+(mp.Soldados.get_Nodo(nSol)->data.posy);

            mp.agregarSprites();
            mp.actualizarXY();
            mp.imprimir();
            std::cout<<std::endl;
            draw();
            return mover(posx, posy);
        }



        else {

            return goToThePast(posx,posy);
            //throw new IllegalArgumentException("NO HAY CAMINO");
        }


    }mapa3& goToThePast(int posx,int posy) {
        if(mp.Soldados.get_Nodo(nSol)->data.con==0){
            std::cout<<"NO HAY CAMINO"<<std::endl;
        }else{

            mp.Soldados.get_Nodo(nSol)->data.posx=mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]%10;
            mp.Soldados.get_Nodo(nSol)->data.posy=mp.Soldados.get_Nodo(nSol)->data.visitados[mp.Soldados.get_Nodo(nSol)->data.con]/10;
            mp.listaY[mp.Soldados.get_Nodo(nSol)->data.posy].get_Nodo(mp.Soldados.get_Nodo(nSol)->data.posx)->data=mp.vacio;

            mp.agregarSprites();
            mp.actualizarXY();

            mp.Soldados.get_Nodo(nSol)->data.con--;
            draw();
            mp.imprimir();
            return mover(posx,posy);
        }
        //return matriz;
    }

};
