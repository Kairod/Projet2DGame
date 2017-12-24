#include <SFML/Graphics.hpp> // bibliotheque dans /usr/include/SFML/
#include <time.h>
#include <list>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argv, char **argc) {

    // creat windows
    sf::Window window;
    window.create(sf::VideoMode(1280, 800), "2DGame");
    // modify position
    window.setPosition(sf::Vector2i(400, 100));
    // modify framerate
    window.setFramerateLimit(60);

    sf::Event event;

    while(window.isOpen())
        // tester des events
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }


    return 0;
}


