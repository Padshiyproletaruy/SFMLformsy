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
    sf::Text fieldMm;
    sf::Text fieldSm;
    sf::Text fieldDm;
    sf::Text fieldM;
    sf::Text fieldKm;
    
    vector<sf::RectangleShape> btns;
    vector<sf::Text> btntext;
    vector<sf::Text> fileds[5];
    vector<sf::RectangleShape> filedback[5];
    vector<sf::Text> filedsname[5];
    vector<sf::String> names = { "Mm","Sm","Dm","M","Km" };
    bool filedsstatus[5]{0};
    const sf::Vector2f size_btf{ 50.f,30.f };
    const sf::Vector2f size_filed{ 300.f,30.f };
    for (int i{ 0 }; i < 5; i++)
    {
        sf::RectangleShape back(size_filed);
        sf::Text textname;
        text.setFont(font);
        text.setCharacterSize(10);
        text.setString("0");
        text.setFillColor(sf::Color::Black);
        text.setFont(font);
        text.setCharacterSize(10);
        text.setString("0");
        text.setFillColor(sf::Color::Black);
  
        sf::RectangleShape back(sf::Vector2f{ 50.f,30.f });
        back.setPosition(sf::Vector2f{ float(i) * 60,110 });
        filedback.push_back(back);


    }


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

            for (int i{ 0 }; i < fields.size(); i++)
            {
                if (mousePosition.x >= fields[i].getPosition().x &&
                    mousePosition.x <= fields[i].getPosition().x + size_btf.x &&
                    mousePosition.y >= fields[i].getPosition().y &&
                    mousePosition.y <= fields[i].getPosition().y + size_btf.y)
                {
                    for (int i = 0; i < fields.size(); i++) {
                        filedsstatus[i] = 0;
                    }
                    filedsstatus[i] = 1;
                }
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