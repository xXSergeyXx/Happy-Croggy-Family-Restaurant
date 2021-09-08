#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

/*
меню в мейн из-за не правильности поставления переменных.
движок не сможет работать.

-ZoRTi
*/

void menu(RenderWindow& window) {
    sf::Texture menuBackgroundTexture, menu1Texture, menu2Texture, menu3Texture;
    menu1Texture.loadFromFile("images/111.png");
    menu2Texture.loadFromFile("images/222.png");
    menu3Texture.loadFromFile("images/333.png");
    menuBackgroundTexture.loadFromFile("images/Menu_Background.jpg");
    sf::Sprite menu1(menu1Texture), menu2(menu2Texture), menu3(menu3Texture), menuBackground(menuBackgroundTexture);
    bool isMenu = 1;
    int menuNum = 0;
    menuBackground.setPosition(0, 0);
    menu1.setPosition(100, 30);
    menu2.setPosition(100, 90);
    menu3.setPosition(100, 150);

    while (isMenu)
    {
        menuNum = 0;
        window.clear(Color(129, 181, 221));

        if (sf::IntRect(100, 30, 300, 50).contains(sf::Mouse::getPosition(window))) { menu1.setColor(sf::Color::Blue); menuNum = 1; }
        if (sf::IntRect(100, 90, 300, 50).contains(sf::Mouse::getPosition(window))) { menu2.setColor(sf::Color::Blue); menuNum = 2; }
        if (sf::IntRect(100, 150, 300, 50).contains(sf::Mouse::getPosition(window))) { menu3.setColor(sf::Color::Blue); menuNum = 3; }

        if (Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (menuNum == 1) isMenu = false;
            if (menuNum == 2) { window.draw(menu1); window.display(); while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)); }
            if (menuNum == 3) { window.close(); isMenu = false; }

        }

        window.draw(menuBackground);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);

        window.display();
    };
}

int main() {
	RenderWindow window(VideoMode(1366, 786), "game");

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
