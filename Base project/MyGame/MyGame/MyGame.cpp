/*
Maintanence Log:
4-26-2021 - First Started Tutorial
*/

#include "Engine/GameEngine.h"
#include "GameScene.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const std::string WINDOW_TITLE = "Sean's Side Scrolling Shooter";

int main()
{
	// Seed the random number generator.
	srand((int)time(NULL));

	// Initialize the game.
	GAME.initialize(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

	// Create our scene.
	GameScenePtr scene = std::make_shared<GameScene>();
	GAME.setScene(scene);

	// Run the game loop.
	GAME.run();

	return 0;
}
