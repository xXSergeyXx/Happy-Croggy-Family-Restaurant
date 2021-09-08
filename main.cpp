/*
главная функция игры.
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Library/Menu.hpp"

using namespace sf;

int main() {
	RenderWindow window(VideoMode(1366, 786), "test stand");

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		menu(window);
		window.display();
	}
}
