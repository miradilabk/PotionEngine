#include "BreakOutScene.h"
#include "GameWindow.h"
#include "SpriteRenderer.h"
#include "PaddleController.h"
#include <string.h>
#include <time.h>
#include "Rotator.h"

char level[20][20] = {
	"555555555555555",
	"555555555555555",
	"444440000044444",
	"414140010041414",
	"333330000033333",
	"331333333333133",
	"222222222222222",
	"222222222222222"
};

int GetBrickWidth() {
	return GameWindow::width / strlen(level[0]);
}

int GetNum(char ch) {
	if ('0' <= ch && ch <= '9') return ch - '0';
	else if ('A' <= ch && ch <= 'F') return ch - 'A' + 10;
	else if ('a' <= ch && ch <= 'f') return ch - 'a' + 10;
}

glm::vec3 GetColorByString(std::string color) {
	float r = (GetNum(color[1]) * 10 + GetNum(color[2])) / 255.0;
	float g = (GetNum(color[3]) * 10 + GetNum(color[4])) / 255.0;
	float b = (GetNum(color[5]) * 10 + GetNum(color[6])) / 255.0;
	return glm::vec3(r, g, b);
}

void BreakOutScene::AddBrick(glm::vec2 size, glm::vec2 position, glm::vec3 color) {
	GameObject *brick = new GameObject(Transform2D(position, size));
	SpriteRenderer* renderer = brick->AddComponent<SpriteRenderer>();
	renderer->Init("block.png", glm::vec2(0), color);
	AddGameObject(brick);
}

void BreakOutScene::LoadLevel() {
	int width = GetBrickWidth(), height = 50;
	std::string colors[5][3] = {
		"#ec407a", "#e91e63", "#d81b60",
		"#ab47bc", "#9c27b0", "#8e24aa",
		"#5c6bc0", "#3f51b5", "#3949ab",
		"#ffee58", "#ffeb3b", "#fdd835",
		"#ff7043", "#ff5722", "#f4511e"
	};
	srand(time(0));
	for (int i = 0; level[i][0]; i++) {
		int k = rand() % 5;
		for (int j = 0; level[i][j]; j++) {
			int num = level[i][j] - '0';
			if (0 < num && num < 10)
				AddBrick(
					glm::vec2(width, height),
					glm::vec2(j*width, i*height),
					GetColorByString(colors[k][num % 3])
				);
		}
	}
}

void BreakOutScene::LoadBackground() {
	GameObject *background = new GameObject(
		Transform2D(
			glm::vec2(0, 0),
			glm::vec2(GameWindow::width, GameWindow::height)
		), -1
	);
	SpriteRenderer *renderer = background->AddComponent<SpriteRenderer>();
	renderer->Init("background.jpg");
	AddGameObject(background);
}

void BreakOutScene::LoadPaddle() {
	GameObject *paddle = new GameObject(
		Transform2D(
			glm::vec2(GameWindow::width / 2, GameWindow::height),
			glm::vec2(100, 25)
		)
	);
	SpriteRenderer *renderer = paddle->AddComponent<SpriteRenderer>();
	renderer->Init("paddle.png", glm::vec2(50.0f, 25));
	paddle->AddComponent<PaddleController>();
	AddGameObject(paddle);
}

BreakOutScene::BreakOutScene()
{
	LoadBackground();
	LoadLevel();
	LoadPaddle();
}

BreakOutScene::~BreakOutScene()
{
}
