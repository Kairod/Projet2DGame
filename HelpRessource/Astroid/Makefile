all: astroid-app

astroid-app: main.o
	g++ main.o -o astroid-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -std=c++11 -c main.cpp
