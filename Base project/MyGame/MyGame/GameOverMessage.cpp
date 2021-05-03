#include "GameOverMessage.h"

#include "GameScene.h"
#include <sstream>

GameOverMessage::GameOverMessage(int score)
{
	m_text.setFont(GAME.getFont("Resources/Courneuf-Regular.ttf"));
	m_text.setPosition(sf::Vector2f(50.0f, 50.0f));
	m_text.setCharacterSize(48);

	std::stringstream stream;
	stream << "GAME OVER\n\nYOUR SCORE: " << score << "\n\nPRESS ENTER TO CONTINUE";
	m_text.setString(stream.str());
}

void GameOverMessage::draw()
{
	GAME.getRenderWindow().draw(m_text);
}

void GameOverMessage::update(sf::Time& time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		GameScenePtr scene = std::make_shared<GameScene>();
		GAME.setScene(scene);
		return;
	}
}