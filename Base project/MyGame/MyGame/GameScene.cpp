#include "GameScene.h"

#include "Ship.h"
#include "MeteorSpawner.h"
#include "Score.h"
#include "GameOverScene.h"

GameScene::GameScene()
{
	ShipPtr ship = std::make_shared<Ship>();
	addGameObject(ship);

	MeteorSpawnerPtr meteorSpawner = std::make_shared<MeteorSpawner>();
	addGameObject(meteorSpawner);

	ScorePtr score = std::make_shared<Score>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(score);
}

int GameScene::getScore()
{
	return m_score;
}

void GameScene::increaseScore()
{
	m_score++;
}

int GameScene::getLives()
{
	return m_lives;
}

void GameScene::decreaseLives()
{
	m_lives--;
}

void GameScene::gameOverMessage()
{
	GameOverScenePtr gameOver = std::make_shared<GameOverScene>(m_score);
	
}
