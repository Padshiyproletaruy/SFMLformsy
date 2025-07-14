#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
int main()
{

    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML window");
    const std::string pathFront = "C:\Windows\Fonts\Arial\arialbd.ttf";
    sf::Font font;
    sf::Text header;
    if (!font.loadFromFile("./fonts/arialbd.ttf"))
    {
        new exception ("не найден формат");
    }
    header.setFont(font);
    header.setString("hfsldhsh");
    header.setCharacterSize(24);
    
    sf::Text header2;
    header2.setFont(font);
    header2.setString("Hello World"); header2.setCharacterSize(18);
    header2.setPosition(sf::Vector2f(0, 30));

        

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();
        window.draw(header);
        window.draw(header2);
        window.display();
    }
}