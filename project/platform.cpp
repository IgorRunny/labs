#include "platform.hpp"
namespace ib
{
	platform::platform(float sizex, float sizey, sf::Vector2f pos, int r, int g, int b)
	{
		m_sizex = sizex;
		m_sizey = sizey;
		m_platform = new sf::RectangleShape(sf::Vector2f(m_sizex, m_sizey));
		if (pos.y > 500)
		{
			m_platform->setOrigin(m_sizex / 2, 0);
		}
		else
		{
			m_platform->setOrigin(m_sizex / 2, m_sizey);
		}
		m_pos = pos;
		m_platform->setPosition(m_pos);
		m_platform->setFillColor(sf::Color(r, g, b));
	}
	void platform::moveright()
	{
		m_pos.x += m_speed;
		m_platform->setPosition(m_pos);
	}
	void platform::moveleft()
	{
		m_pos.x -= m_speed;
		m_platform->setPosition(m_pos);
	}
	sf::Vector2f platform::getpos()
	{
		return m_pos;
	}
	sf::RectangleShape* platform::get()
	{
		return m_platform;
	}
	float platform::getsizex()
	{
		return m_sizex;
	}
	void platform::setpos(float x)
	{
		m_platform->setPosition(x, m_platform->getPosition().y);
	}
	platform::~platform()
	{

	}
}