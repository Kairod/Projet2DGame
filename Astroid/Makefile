all: astroid-app

astroid-app: main.o
	g++ main.o -o astroid-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o: main.cpp
	g++ -std=c++11 -c main.cpp
