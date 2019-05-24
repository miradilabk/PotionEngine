#include "GameWindow.h"
#include "SpriteRenderer.h"
#include "Rotator.h"
#include "BreakOutScene.h"
#include <glm/vec2.hpp>
#include <cstdlib>

int main() {
	GameWindow game(800, 600);
	
	BreakOutScene *scene = new BreakOutScene();

	game.AddScene(scene);
	game.currentSceneIndex = 0;

	game.Start();
	system("pause");
	return 0;
}
