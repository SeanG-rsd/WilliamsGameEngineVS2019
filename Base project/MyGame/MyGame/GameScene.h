#pragma once

#include "Engine/GameEngine.h"

class GameScene : public Scene {
 public:
  // Creates our Scene.
  GameScene();

  //Get the current score
  int getScore();

  //Increase the score
  void increaseScore();

  int getLives();

  void decreaseLives();

  void gameOverMessage();
private:
	int m_score = 0;
	int m_lives = 3;
};

typedef std::shared_ptr<GameScene> GameScenePtr;
