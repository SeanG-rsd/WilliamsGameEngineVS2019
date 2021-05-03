#include "Meteor.h"

const float SPEED = 0.25f;

Meteor::Meteor(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	sprite_.setPosition(pos);
	setCollisionCheckEnabled(true);
	assignTag("meteor");
}

void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Meteor::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		makeDead();
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		if (scene.getLives() > 0)
		{
			scene.decreaseLives();
		}
		if (scene.getLives() == 0)
		{
			scene.gameOver();
		}
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}

sf::FloatRect Meteor::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}

void Meteor::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("laser"))
	{
		otherGameObject.makeDead();
	}
	sf::Vector2f pos = sprite_.getPosition();
	makeDead();
	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	scene.increaseScore();
	playAnimation(pos);
}

void Meteor::playAnimation(sf::Vector2f pos)
{
	ExplosionPtr explosion = std::make_shared<Explosion>(pos);
	GAME.getCurrentScene().addGameObject(explosion);
}