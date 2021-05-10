#include "Background.h"

const float SPEED = 0.1f;

Background::Background()
{
	m_sprite.setTexture(GAME.getTexture("Resources/background.png"));
	m_sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	m_spriteTwo.setTexture(GAME.getTexture("Resources/background.png"));
	m_spriteTwo.setPosition(sf::Vector2f(GAME.getRenderWindow().getSize().x, 0.0f));
}

void Background::draw()
{
	GAME.getRenderWindow().draw(m_sprite);
	GAME.getRenderWindow().draw(m_spriteTwo);
}

void Background::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = m_sprite.getPosition();
	sf::Vector2f posTwo = m_spriteTwo.getPosition();

	//Reset
	if (pos.x < 0)
	{
		m_sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	}
	if (posTwo.x < 0)
	{
		m_spriteTwo.setPosition(sf::Vector2f(0.0f + m_spriteTwo.getTexture()->getSize().x, 0.0f));
	}
	else
	{
		m_sprite.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
		m_spriteTwo.setPosition(sf::Vector2f(posTwo.x - SPEED * msElapsed, posTwo.y));
	}
}