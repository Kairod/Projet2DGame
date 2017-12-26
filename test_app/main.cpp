#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <list>
#include <cmath>
#include <cstdlib>


int main() {
    int speed = 5;
    int blockSize = 64;
    int w_window = 800;
    int h_window = 600;

    std::cout << "Hello, World!" << std::endl;

    //creation de la fenetre
    sf::RenderWindow window;
    window.create(sf::VideoMode(w_window, h_window), "Test App");
    //window.setPosition(sf::Vector2i(200,200));
    window.setFramerateLimit(60);

    // direction
    enum Direction{Up=8,Left=9,Down=10,Right=11};

    // animation
    sf::Vector2i anim(1,Down);
    bool updateFPS = false;

    // creation d'un rectangle
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(10,10);
    rect.setFillColor(sf::Color::Cyan);

    // perso texture
    sf::Texture perso;
    sf::Sprite sprite_perso;

    sf::Clock time;
    float switchFps= 50;

    // chargement des textures perso
    if(!perso.loadFromFile("/home/kairod/github/Projet2DGame/test_app/images/character_sprite.png")){
        std::cout<< "Erreur de chargement character_sprite.png";
    }
    perso.setSmooth(true);
    sprite_perso.setTexture(perso);

    //creation d'une vue
    sf::View view;

    while(window.isOpen()){

        sf::Event event;

        while (window.pollEvent(event)) {

            // event close window
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // event jouer animation
            if(event.type == sf::Event::KeyPressed){
                updateFPS=true;
            }
            else{
                updateFPS=false;
            }

        }

        // event clavier tire
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            std::cout<<"Fire!!!\n";
        }

        // event clavier deplacement
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            anim.y=Up;
            sprite_perso.move(0,-speed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            anim.y=Right;
            sprite_perso.move(speed,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            anim.y=Down;
            sprite_perso.move(0,speed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            anim.y=Left;
            sprite_perso.move(-speed,0);
        }

        // evite que le personnage sorte de l'ecran
        if(sprite_perso.getPosition().x<=0){
            sprite_perso.setPosition(sf::Vector2f(0,sprite_perso.getPosition().y));
        }
        if(sprite_perso.getPosition().y<=0){
            sprite_perso.setPosition(sf::Vector2f(sprite_perso.getPosition().x, 0));
        }

        // gestion animation
        if(updateFPS){
            if(time.getElapsedTime().asMilliseconds()>=switchFps){
                anim.x++;
                if(anim.x*blockSize >= (9*blockSize)){
                    anim.x=0;
                }
                time.restart();
            }
        }
        sprite_perso.setTextureRect(sf::Rect<int>(anim.x*blockSize, anim.y*blockSize, blockSize, blockSize));

        /* Detection des collisions entre perso et rect */
        if(std::abs((sprite_perso.getPosition().x + (blockSize/2))) - (rect.getPosition().x + (32/2)) < blockSize &&
           std::abs((sprite_perso.getPosition().y + (blockSize/2)))- (rect.getPosition().y + (32/2)) < blockSize){
            std::cout<<"Collison\n";
        }

        // creation view de la la position (0,0) de l'ecran à sa taille max
        view.reset(sf::Rect<float>(0,0,w_window, h_window));
        // definition de la position de cette view
        sf::Vector2f position_view(w_window/2, h_window/2);
        // centrage de la view sur le centre du personnage
        position_view.x = sprite_perso.getPosition().x + (blockSize/2) - (w_window/2);
        position_view.y = sprite_perso.getPosition().y + (blockSize/2) - (h_window/2);
        if(position_view.x<0){
            position_view.x=0;
        }
        if(position_view.y<0){
            position_view.y=0;
        }
        //reset de la view
        view.reset(sf::Rect<float>(position_view.x, position_view.y, w_window, h_window));
        //view.zoom(0.5f);

        //on precise que dans quelle vue active on est
        window.setView(view);

        // clear window of last frame
        window.clear();

        window.draw(rect);
        window.draw(sprite_perso);

        window.display();
    }

    return 0;
}
