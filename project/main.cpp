<<<<<<< HEAD
﻿#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <string>
#include "ball.hpp"
#include "platform.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Project");
    sf::Clock timer;
    int count1 = 0;
    int count2 = 0;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text Count;
    Count.setFont(font);
    Count.setOrigin(Count.getScale().x / 2, Count.getScale().y / 2);
    Count.setCharacterSize(50);
    Count.setPosition(500, 500);
    Count.setStyle(sf::Text::Bold);
    Count.setColor(sf::Color::White);
    std::vector <ib::platform> Platforms;
    Platforms.push_back(ib::platform(200, 15, sf::Vector2f(500, 850), 0, 255, 0));
    Platforms.push_back(ib::platform(200, 15, sf::Vector2f(500, 150), 0, 0, 255));
    ib::ball Ball(30, sf::Vector2f(500, 500), 255,0,0);
    
    
    
    

    while (window.isOpen())
    {
        sf::Event event;
        sf::Time dt = timer.restart();
        Count.setString(std::to_string(count1) + ":" + std::to_string(count2));
        Ball.move();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Platforms[0].moveright();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            Platforms[0].moveleft();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            Platforms[1].moveright();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            Platforms[1].moveleft();
        }

        if (Platforms[0].getpos().x + Platforms[0].getsizex() / 2 >= 1000)
        {
            Platforms[0].setpos(1000 - Platforms[0].getsizex() / 2);
        }
        if (Platforms[0].getpos().x - Platforms[0].getsizex() / 2 <= 0)
        {
            Platforms[0].setpos(0 + Platforms[0].getsizex() / 2);
        }

        if (Platforms[1].getpos().x + Platforms[1].getsizex() / 2 >= 1000)
        {
            Platforms[1].setpos(1000 - Platforms[1].getsizex() / 2);
        }
        if (Platforms[1].getpos().x - Platforms[1].getsizex() / 2 <= 0)
        {
            Platforms[1].setpos(0 + Platforms[1].getsizex() / 2);
        }

        if (Ball.getpos().x + Ball.getrad() >= 1000)
        {
            Ball.collisionX();
        }
        if (Ball.getpos().x - Ball.getrad() <= 0)
        {
            Ball.collisionX();
        }
        if (Ball.getpos().y + Ball.getrad() >= 1000)
        {
            Ball.collisionY();
            count2 += 1;
        }
        if (Ball.getpos().y - Ball.getrad() <= 0)
        {
            Ball.collisionY();
            count1 += 1;
        }
        std::cout << Ball.getpos().y << "\n";
        
        if (Ball.getpos().x + Ball.getrad() >= Platforms[0].getpos().x - Platforms[0].getsizex() / 2 && Ball.getpos().x - Ball.getrad() <= Platforms[0].getpos().x + Platforms[0].getsizex() / 2 && Ball.getpos().y + Ball.getrad() >= Platforms[0].getpos().y)
        {
            Ball.collisionY();
        }
        if (Ball.getpos().x + Ball.getrad() >= Platforms[1].getpos().x - Platforms[1].getsizex() / 2 && Ball.getpos().x + Ball.getrad() <= Platforms[1].getpos().x + Platforms[1].getsizex() / 2 && Ball.getpos().y - Ball.getrad() <= Platforms[1].getpos().y)
        {
            Ball.collisionY();
        }

        while (window.pollEvent(event))
        {

           
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(*Platforms[0].get());
        window.draw(*Platforms[1].get());
        window.draw(*Ball.get());
        window.draw(Count);
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    Platforms[0].~platform();
    Platforms[1].~platform();
    Ball.~ball();

    return 0;
=======
﻿#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <string>
#include "ball.hpp"
#include "platform.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Project");
    sf::Clock timer;
    int count1 = 0;
    int count2 = 0;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text Count;
    Count.setFont(font);
    Count.setOrigin(Count.getScale().x / 2, Count.getScale().y / 2);
    Count.setCharacterSize(50);
    Count.setPosition(500, 500);
    Count.setStyle(sf::Text::Bold);
    Count.setColor(sf::Color::White);
    std::vector <ib::platform> Platforms;
    Platforms.push_back(ib::platform(200, 15, sf::Vector2f(500, 850), 0, 255, 0));
    Platforms.push_back(ib::platform(200, 15, sf::Vector2f(500, 150), 0, 0, 255));
    ib::ball Ball(30, sf::Vector2f(500, 500), 255,0,0);
    
    
    
    

    while (window.isOpen())
    {
        sf::Event event;
        sf::Time dt = timer.restart();
        Count.setString(std::to_string(count1) + ":" + std::to_string(count2));
        Ball.move();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Platforms[0].moveright();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            Platforms[0].moveleft();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            Platforms[1].moveright();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            Platforms[1].moveleft();
        }

        if (Platforms[0].getpos().x + Platforms[0].getsizex() / 2 >= 1000)
        {
            Platforms[0].setpos(1000 - Platforms[0].getsizex() / 2);
        }
        if (Platforms[0].getpos().x - Platforms[0].getsizex() / 2 <= 0)
        {
            Platforms[0].setpos(0 + Platforms[0].getsizex() / 2);
        }

        if (Platforms[1].getpos().x + Platforms[1].getsizex() / 2 >= 1000)
        {
            Platforms[1].setpos(1000 - Platforms[1].getsizex() / 2);
        }
        if (Platforms[1].getpos().x - Platforms[1].getsizex() / 2 <= 0)
        {
            Platforms[1].setpos(0 + Platforms[1].getsizex() / 2);
        }

        if (Ball.getpos().x + Ball.getrad() >= 1000)
        {
            Ball.collisionX();
        }
        if (Ball.getpos().x - Ball.getrad() <= 0)
        {
            Ball.collisionX();
        }
        if (Ball.getpos().y + Ball.getrad() >= 1000)
        {
            Ball.collisionY();
            count2 += 1;
        }
        if (Ball.getpos().y - Ball.getrad() <= 0)
        {
            Ball.collisionY();
            count1 += 1;
        }
        std::cout << Ball.getpos().y << "\n";
        
        if (Ball.getpos().x + Ball.getrad() >= Platforms[0].getpos().x - Platforms[0].getsizex() / 2 && Ball.getpos().x - Ball.getrad() <= Platforms[0].getpos().x + Platforms[0].getsizex() / 2 && Ball.getpos().y + Ball.getrad() >= Platforms[0].getpos().y)
        {
            Ball.collisionY();
        }
        if (Ball.getpos().x + Ball.getrad() >= Platforms[1].getpos().x - Platforms[1].getsizex() / 2 && Ball.getpos().x + Ball.getrad() <= Platforms[1].getpos().x + Platforms[1].getsizex() / 2 && Ball.getpos().y - Ball.getrad() <= Platforms[1].getpos().y)
        {
            Ball.collisionY();
        }

        while (window.pollEvent(event))
        {

           
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(*Platforms[0].get());
        window.draw(*Platforms[1].get());
        window.draw(*Ball.get());
        window.draw(Count);
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    Platforms[0].~platform();
    Platforms[1].~platform();
    Ball.~ball();

    return 0;
>>>>>>> 47f0855 (Project is donegit add --allgit add --allgit add --all)
}