#pragma once

#include "Engine/GameEngine.h"

class Background : public GameObject
{
public:
	Background();

	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Sprite m_sprite;
	sf::Sprite m_spriteTwo;
};

typedef std::shared_ptr<Background> BackgroundPtr;
