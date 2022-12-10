#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::CircleShape shape(20);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(100, 600);
    sf::Clock timer;
    shape.setOrigin(100, 100);
    sf::Vector2i defPos = sf::Vector2i(500, 500);
    sf::Mouse::setPosition(defPos, window);
    sf::RectangleShape platform(sf::Vector2f(150,10));
    platform.setFillColor(sf::Color(0, 166, 147));
    platform.setPosition(425, 900);
    platform.setOrigin(75, 5);
    int x = 1;
    int y = 2;
    
    
    
    
    

    while (window.isOpen())
    {
        sf::Event event;
        shape.move(x, y);
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
        if (shape.getPosition().x > platform.getPosition().x - 75 && shape.getPosition().x < platform.getPosition().x + 75 && shape.getPosition().y == 800)
        {
            int newx = (shape.getPosition().x - platform.getPosition().x) + shape.getRadius() * 2;
            x = newx - platform.getPosition().x;
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
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return 0;
}