#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <windows.h>

#include "HCFR/HCFR/Menu.h"

/*
меню в мейн из-за не правильности поставления переменных.
движок не сможет работать.

-ZoRTi

Пофикшено, правда функции не в классе, ну и фиг с ним.

-XSergeyX
*/

using namespace sf;

int main() {
	RenderWindow window(VideoMode(1385, 750), "Happy Croggie's Family Diner");
    Image icon;
    if (!icon.loadFromFile("D:/Happy-Croggy-Family-Restaurant/HCFR/Release/images/icon.jpg"))
    {
        return 1;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			    window.close();
		}
		window.clear();
        intro(window);
		menu(window);

		window.display();
	}
}
