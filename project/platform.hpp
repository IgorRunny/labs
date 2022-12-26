#include <SFML/Graphics.hpp>
#pragma once

namespace ib
{
	class platform
	{
	private:
		float m_sizex;
		float m_sizey;
		int m_speed = 2;
		sf::Vector2f m_pos;
		sf::RectangleShape* m_platform;
	public:
		platform(float sizex, float sizey, sf::Vector2f pos, int r, int g, int b);
		void moveright();
		void moveleft();
		sf::RectangleShape* get();
		sf::Vector2f getpos();
		void setpos(float x);
		float getsizex();
		~platform();
	};
}