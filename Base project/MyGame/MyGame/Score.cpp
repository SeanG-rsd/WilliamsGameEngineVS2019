#include "Score.h"
#include "GameScene.h"
#include <sstream>

Score::Score(sf::Vector2f pos)
{
	m_text.setFont(GAME.getFont("Resources/Courneuf-Regular.ttf"));
	m_text.setPosition(pos);
	m_text.setCharacterSize(24);
	assignTag("score");
}

void Score::draw()
{
	GAME.getRenderWindow().draw(m_text);
}

void Score::update(sf::Time& elapsed)
{
	GameScene& scene = (GameScene&)GAME.getCurrentScene();

	std::stringstream stream;
	stream << "Score: " << scene.getScore();

	m_text.setString(stream.str());
}