#pragma once

#include "Engine/GameEngine.h"

class Ship 
	: public GameObject
{
public:
	Ship();

	void draw();
	void update(sf::Time& elapsed);

private:
	sf::Sprite m_sprite;
	int m_fireTimer = 0;
};

typedef std::shared_ptr<Ship> ShipPtr;
