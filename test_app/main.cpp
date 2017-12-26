#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


int main() {
    int speed = 5;
    int blockSize = 64;

    std::cout << "Hello, World!" << std::endl;

    //creation de la fenetre
    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "Test App");
    //window.setPosition(sf::Vector2i(200,200));
    window.setFramerateLimit(60);

    // direction
    enum Direction{Up=8,Left=9,Down=10,Right=11};

    // animation
    sf::Vector2i anim(1,Down);
    bool updateFPS = true;

    // creation d'un rectangle
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(10,10);
    rect.setFillColor(sf::Color::Cyan);

    // perso texture
    sf::Texture perso;
    sf::Sprite sprite_perso;

    sf::Clock time;
    float fpsCount = 0;
    float switchFps= 100;
    float fpsSpeed = 500;

    if(!perso.loadFromFile("/home/kairod/github/Projet2DGame/test_app/images/character_sprite.png")){
        std::cout<< "Erreur de chargement character_sprite.png";
    }
    perso.setSmooth(true);
    sprite_perso.setTexture(perso);

    while(window.isOpen()){

        sf::Event event;

        while (window.pollEvent(event)) {

            // event close window
            if (event.type == sf::Event::Closed) {
                window.close();
            }

        }

        // event clavier tire
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            std::cout<<"Fire!!!\n";
        }

        // event clavier deplacement
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            anim.y=Up;
            sprite_perso.move(0,-speed);
            updateFPS=true;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            anim.y=Right;
            sprite_perso.move(speed,0);
            updateFPS=true;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            anim.y=Down;
            sprite_perso.move(0,speed);
            updateFPS=true;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            anim.y=Left;
            sprite_perso.move(-speed,0);
            updateFPS=true;
        }
        else{
            updateFPS=false;
        }

        // gestion animation
        updateFPS ? (fpsCount += fpsSpeed * time.restart().asSeconds()) : (fpsCount=0);
        if(fpsCount>=switchFps){
            anim.x++;
            if(anim.x*blockSize >= (9*blockSize)){
                anim.x=0;
            }
        }
        sprite_perso.setTextureRect(sf::Rect<int>(anim.x*blockSize, anim.y*blockSize, blockSize, blockSize));

        // clear window of last frame
        window.clear();

        window.draw(rect);
        window.draw(sprite_perso);

        window.display();
    }

    return 0;
}
