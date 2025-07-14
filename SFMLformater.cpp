#include <SFML/Graphics.hpp>
#include<iostream>
#include <vector>
#include <Windows.h>
using namespace std;
int main()
{

    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML window");
    const std::string pathFront = "C:\Windows\Fonts\Arial\arialbd.ttf";
    sf::Font font;
    sf::Text text;
    vector<sf::RectangleShape> btns;
    vector<sf::Text> btntext;
    const sf::Vector2f size_btf{ 50.f,30.f };

    for (int i{ 0 }; i < 10; i++) {
        sf::RectangleShape btn(sf::Vector2f{ 50.f,30.f });
        btn.setPosition(sf::Vector2f{ float(i )* 60,110 });
        btns.push_back(btn);
       text.setFont(font);
       text.setString(sf::String(to_string(i)));
       text.setCharacterSize(24);
       text.setFillColor(sf::Color::Black);
       sf::Vector2f  position= btn.getPosition();
       text.setPosition(sf::Vector2f{ position.x+15,position.y+6 });
       btntext.push_back(text);
    }



    if (!font.loadFromFile("./fonts/arialbd.ttf"))
    {
        new exception ("не найден формат");
    }
    
    sf::Text header2;
    header2.setFont(font);
    header2.setString("Hello World"); header2.setCharacterSize(18);
    header2.setPosition(sf::Vector2f(0, 30));
    sf::RectangleShape btn({ 100.f,50.f });
    btn.setPosition(80, 120);
        

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();

        if (event.mouseButton.button==  sf::Mouse::Button::Left)
        {
            auto mousePosition = event.mouseButton;
            for (int i{ 0 }; i < btns.size();i++) 
            {
                if (mousePosition.x >= btns[i].getPosition().x &&
                    mousePosition.x <= btns[i].getPosition().x+size_btf.x &&
                    mousePosition.y >= btns[i].getPosition().y &&
                    mousePosition.y <= btns[i].getPosition().y+size_btf.y)
                {
                    btns[i].setFillColor(sf::Color::Green);
                }
            }
        }
       
        window.draw(header2);
        for (auto &btn : btns) {
            window.draw(btn);
        }
        for (auto text : btntext) {
            window.draw(text);
        }
        window.display();
    }
}