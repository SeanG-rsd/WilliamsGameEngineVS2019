#pragma once

#include "Engine/GameEngine.h"

class GameOverMessage : public GameObject
{
public:
	GameOverMessage(int score);

	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Text m_text;
};

typedef std::shared_ptr<GameOverMessage> GameOverMessagePtr;