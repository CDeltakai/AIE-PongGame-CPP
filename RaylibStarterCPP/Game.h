#pragma once

#include "raylib.h"
#include <string>
#include <list>
#include "SceneObject.h"
#include "Paddle.h"
#include "Ball.h"
#include "Stopwatch.h"
#include <ctime>
#include <chrono>


class Game
{
public:
	float paddleSpeed = 2;
	int player1Score = 0;
	int player2Score = 0;

	Stopwatch stopwatch;
	long currentTime = 0;
	long lastTime = 0;
	float timer = 0;
	int fps = 1;
	int frames;
	float deltaTime = 0.005;

	std::list<SceneObject*> activeSceneObjects;

	

	SceneObject* ballBase;
	Ball ball;

	SceneObject* paddle1Base;
	Paddle paddle1;

	SceneObject* paddle2Base;
	Paddle paddle2;

public:
	Game();

	void ResetBall();
	void Init();
	void Update();
	void Draw();

	


};

