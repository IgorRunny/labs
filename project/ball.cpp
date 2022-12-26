#include "ball.hpp"
namespace ib
{
	ball::ball(float radius, sf::Vector2f pos, int r, int g, int b)
	{
		m_radius = radius;
		m_ball = new sf::CircleShape(m_radius);
		m_ball->setOrigin(m_radius, m_radius);
		m_pos = pos;
		m_ball->setPosition(m_pos);
		m_ball->setFillColor(sf::Color(r, g, b));
		m_speed.x = 1;
		m_speed.y = 2;
	}
	void ball::move()
	{
		m_pos.x += m_speed.x;
		m_pos.y += m_speed.y;
		m_ball->setPosition(m_pos);
	}
	void ball::collisionX()
	{
		m_speed.x = -m_speed.x;
	}
	void ball::collisionY()
	{
		m_speed.y = -m_speed.y;
	}
	sf::CircleShape* ball::get()
	{
		return m_ball;
	}


	float ball::getrad()
	{
		return m_radius;
	}
	sf::Vector2f ball::getpos()
	{
		return m_pos;
	}
	ball::~ball()
	{

	}
}