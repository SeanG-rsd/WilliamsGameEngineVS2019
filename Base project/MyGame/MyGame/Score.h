#pragma once

#include "Engine/GameEngine.h"

class Score : public GameObject
{
public:
	//Creates the score instance
	Score(sf::Vector2f pos);

	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Text m_text;
};

typedef std::shared_ptr<Score> ScorePtr;
