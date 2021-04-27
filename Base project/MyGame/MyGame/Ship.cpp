#include "Ship.h"

#include <memory>
#include "Laser.h"

const float SPEED = 0.5f;
const int FIRE_DELAY = 200;

Ship::Ship()
{
	m_sprite.setTexture(GAME.getTexture("Resources/ship.png"));
	m_sprite.setPosition(sf::Vector2f(0, 0));
}

void Ship::draw()
{
	GAME.getRenderWindow().draw(m_sprite);
}

void Ship::update(sf::Time& elapsed)
{
	sf::Vector2f pos = m_sprite.getPosition();
	float x = pos.x;
	float y = pos.y;

	int msElapsed = elapsed.asMilliseconds();

	//get input from the user
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) y -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) y += SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) x -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) x += SPEED * msElapsed;

	sf::Vector2u shipSize = m_sprite.getTexture()->getSize();
	y = std::max(y, 0.0f - shipSize.y / 2);
	y = std::min(y, (float)(GAME.getRenderWindow().getSize().y - shipSize.y / 2));
	x = std::max(x, 0.0f);
	x = std::min(x, (float)(GAME.getRenderWindow().getSize().x - shipSize.x));


	//set sprite position
	m_sprite.setPosition(sf::Vector2f(x, y));

	if (m_fireTimer > 0)
	{
		m_fireTimer -= msElapsed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_fireTimer <= 0)
	{
		m_fireTimer = FIRE_DELAY;

		sf::FloatRect bounds = m_sprite.getGlobalBounds();

		float laserX = x + bounds.width;
		float laserY = y + (bounds.height / 2.0f);

		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
		GAME.getCurrentScene().addGameObject(laser);
	}
}
