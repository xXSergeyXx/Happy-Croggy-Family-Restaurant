#pragma once

using namespace sf;

void intro(RenderWindow & window) {
    sf::Texture introBackgroundTexture, introWarningTexture;
    introBackgroundTexture.loadFromFile("D:/Happy-Croggy-Family-Restaurant/HCFR/Release/images/Intro_Background.jpg");
    introWarningTexture.loadFromFile("D:/Happy-Croggy-Family-Restaurant/HCFR/Release/images/Intro_Warning.png");
    sf::Sprite introBackground(introBackgroundTexture), introWarning(introWarningTexture);
    introBackground.setPosition(300, 100);
    introWarning.setPosition(400, 300);

    window.clear(Color(0, 0, 0));

    window.draw(introWarning);
    window.display();

    Sleep(7500);

    window.draw(introBackground);
    window.display();

    Sleep(10000);

};

void menu(RenderWindow & window) {
    sf::Texture menuBackgroundTexture, menu1Texture, menu2Texture, menu3Texture, menu4Texture, menuChoosedcharTexture;
    menu1Texture.loadFromFile("D:/Happy-Croggy-Family-Restaurant/HCFR/Release/images/Menu_NewgameText.png");
    menu2Texture.loadFromFile("D:/Happy-Croggy-Family-Restaurant/HCFR/Release/images/Menu_ProgramText.png");
    menu3Texture.loadFromFile("D:/Happy-Croggy-Family-Restaurant/HCFR/Release/images/Menu_ExitText.png");
    menu4Texture.loadFromFile("D:/Happy-Croggy-Family-Restaurant/HCFR/Release/images/Menu_OptionsText.png");
    menuBackgroundTexture.loadFromFile("D:/Happy-Croggy-Family-Restaurant/HCFR/Release/images/Menu_background.jpg");
    menuChoosedcharTexture.loadFromFile("D:/Happy-Croggy-Family-Restaurant/HCFR/Release/images/Menu_ChoosedChar.png");

    sf::Sprite menu1(menu1Texture), menu2(menu2Texture), menu3(menu3Texture), menu4(menu4Texture), menuBackground(menuBackgroundTexture), menuChoosedchar(menuChoosedcharTexture);
    bool isMenu = 1;
    int menuNum = 0;
    menuBackground.setPosition(0, 0);
    menu1.setPosition(80, 300);
    menu2.setPosition(60, 375);
    menu3.setPosition(80, 450);
    menu4.setPosition(1180, 650);

    while (isMenu)
    {
        menuNum = 0;
        window.clear(Color(0, 0, 0));

        if (sf::IntRect(80, 300, 300, 50).contains(sf::Mouse::getPosition(window))) { menu1.setColor(sf::Color(115, 115, 115)); menuChoosedchar.setPosition(70, 300); menuNum = 1; }
        if (sf::IntRect(80, 375, 300, 50).contains(sf::Mouse::getPosition(window))) { menu2.setColor(sf::Color(115, 115, 115)); menuChoosedchar.setPosition(70, 375); menuNum = 2; }
        if (sf::IntRect(80, 450, 300, 50).contains(sf::Mouse::getPosition(window))) { menu3.setColor(sf::Color(115, 115, 115)); menuChoosedchar.setPosition(70, 450); menuNum = 3; }
        if (sf::IntRect(1180, 650, 300, 50).contains(sf::Mouse::getPosition(window))) { menu4.setColor(sf::Color(115, 115, 115)); menuChoosedchar.setPosition(1170, 650); menuNum = 4; }

        if (Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (menuNum == 1) isMenu = false;
            if (menuNum == 2) { window.draw(menu1); window.display(); while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)); }
            if (menuNum == 3) { window.close(); isMenu = false; }
            if (menuNum == 4) { window.close(); isMenu = false; }

        }

        window.draw(menuBackground);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.draw(menu4);
        window.draw(menuChoosedchar);

        window.display();

        menu1.setColor(sf::Color::White);
        menu2.setColor(sf::Color::White);
        menu3.setColor(sf::Color::White);
        menu4.setColor(sf::Color::White);

        menuChoosedchar.setPosition(2000, 2000);
    };
}