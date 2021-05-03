#pragma once

#include "Engine/GameEngine.h"

class Lives : public GameObject
{
public:
	Lives(sf::Vector2f pos);

	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Text m_text;
};

typedef std::shared_ptr<Lives> LivesPtr;
