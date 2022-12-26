<<<<<<< HEAD
#include <SFML/Graphics.hpp>
#pragma once
namespace ib
{
	class ball
	{
	private:
		float m_radius;
		sf::Vector2f m_pos;
		sf::Vector2f m_speed;
		sf::CircleShape* m_ball;
	public:
		ball(float radius, sf::Vector2f pos, int r, int g, int b);
		void move();
		void collisionX();
		void collisionY();

		sf::Vector2f getpos();

		float getrad();
		sf::CircleShape* get();
		~ball();
	};
=======
#include <SFML/Graphics.hpp>
#pragma once
namespace ib
{
	class ball
	{
	private:
		float m_radius;
		sf::Vector2f m_pos;
		sf::Vector2f m_speed;
		sf::CircleShape* m_ball;
	public:
		ball(float radius, sf::Vector2f pos, int r, int g, int b);
		void move();
		void collisionX();
		void collisionY();

		sf::Vector2f getpos();

		float getrad();
		sf::CircleShape* get();
		~ball();
	};
>>>>>>> 47f0855 (Project is donegit add --allgit add --allgit add --all)
}