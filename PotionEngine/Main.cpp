#include "GameWindow.h"
#include "SpriteRenderer.h"
#include "Rotator.h"
#include <glm/vec2.hpp>
#include <cstdlib>

int main() {
	GameWindow game(800, 600);
	Scene scene;
	GameObject background(Transform2D(glm::vec2(0, 0), glm::vec2(800, 600)), -1);
	GameObject gameObject(Transform2D(glm::vec2(200, 200)));
	GameObject block(Transform2D(glm::vec2(300, 400)));

	SpriteRenderer renderer("face.png");
	SpriteRenderer bgRenderer("background.jpg");
	SpriteRenderer blockRenderer("block.png");
	Rotator rotator, r2;

	background.AddComponent(&bgRenderer);

	gameObject.AddComponent(&rotator);
	gameObject.AddComponent(&renderer);
	
	block.AddComponent(&blockRenderer);
	block.AddComponent(&r2);

	scene.AddGameObject(background);
	scene.AddGameObject(gameObject);
	scene.AddGameObject(block);
	
	game.AddScene(scene);
	game.currentSceneIndex = 0;

	game.Start();
}
