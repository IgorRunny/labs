#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include<math.h>
double PI = acos(-1);

void Angle(int& angle)
{
    angle += 30;
    if (angle >= 360)
    {
        angle -= 360;
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::CircleShape shape(20);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(10, 600);
    sf::Clock timer;
    shape.setOrigin(20, 20);
    sf::Vector2i defPos = sf::Vector2i(425, 900);
    sf::Mouse::setPosition(defPos, window);
    sf::RectangleShape platform(sf::Vector2f(150,10));
    platform.setFillColor(sf::Color(0, 166, 147));
    platform.setPosition(sf::Vector2f(defPos));
    platform.setOrigin(platform.getSize().x / 2, platform.getSize().y / 2);
    double speed = 0.5;
    int angle = 30;
    double x = 100;
    double y = 600;
    shape.setPosition(x, y);
    
    
    
    

    while (window.isOpen())
    {
        sf::Event event;
        sf::Time dt = timer.restart();
        std::cout << dt.asMicroseconds() << "\n";
        x += speed  * cosf(angle * PI / 180);
        y += speed * sinf(angle * PI / 180);
        shape.setPosition(x, y);
        if (sf::Mouse::getPosition(window).x < 0)
        {
            sf::Mouse::setPosition(sf::Vector2i(0, sf::Mouse::getPosition(window).y), window);
        }
        if (sf::Mouse::getPosition(window).x > 1000)
        {
            sf::Mouse::setPosition(sf::Vector2i(1000, sf::Mouse::getPosition(window).y), window);
        }
        if (sf::Mouse::getPosition(window).x != defPos.x)
        {
            platform.setPosition(sf::Mouse::getPosition(window).x, platform.getPosition().y);
        }
        std::cout << platform.getPosition().x << "   " << shape.getPosition().x << "\n";
        if (x + shape.getRadius() >= 1000)
        {
            Angle(angle);
        }
        if (x - shape.getRadius() <= 0)
        {
            Angle(angle);
        }
        if (y + shape.getRadius() >= 1000)
        {
            Angle(angle);
        }
        if (y - shape.getRadius() <= 0)
        {
            Angle(angle);
        }
        if ((x + shape.getRadius() >= platform.getPosition().x - platform.getSize().x / 2) && (x + shape.getRadius() <= platform.getPosition().x + platform.getSize().x / 2) && (y + shape.getRadius() >= platform.getPosition().y + platform.getSize().y / 2))
        {
            angle += 60;
        }
        while (window.pollEvent(event))
        {
           
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(platform);
        window.draw(shape);
        window.display();
        //std::this_thread::sleep_for(std::chrono::milliseconds(1) / 10);
    }

    return 0;
}