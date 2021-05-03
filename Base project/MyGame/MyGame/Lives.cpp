#include "Lives.h"
#include "GameScene.h"
#include <sstream>

Lives::Lives(sf::Vector2f pos)
{
	m_text.setFont(GAME.getFont("Resources/Courneuf-Regular.ttf"));
	m_text.setPosition(pos);
	m_text.setCharacterSize(24);
	assignTag("lives");
}

void Lives::draw()
{
	GAME.getRenderWindow().draw(m_text);
}

void Lives::update(sf::Time& elapsed)
{
	GameScene& scene = (GameScene&)GAME.getCurrentScene();

	std::stringstream stream;
	stream << "Lives: " << scene.getLives();

	m_text.setString(stream.str());
}