#include "Background.h"

const float SPEED = 0.25f;

Background::Background()
{
	m_sprite.setTexture(GAME.getTexture("Resources/background.png"));
	m_sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	m_spriteTwo.setTexture(GAME.getTexture("Resources/background.png"));
	m_spriteTwo.setPosition(sf::Vector2f(-m_sprite.getPosition().x, 0.0f));
}

void Background::draw()
{
	GAME.getRenderWindow().draw(m_sprite);
}

void Background::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = m_sprite.getPosition();


}