#include "Game.h"
#include "Stopwatch.h"
#include <string>
#include <iostream>
#include <list>
#include <random>

using namespace std;

Game::Game()
{
	paddleSpeed = 2.5f;
	player1Score = 0;
	player2Score = 0;

	
	//currentTime = 0;
	//lastTime = 0;
	//fps = 1;
	//frames = 0;
	//deltaTime = 0.005;

	ballBase = &ball;
	paddle1Base = &paddle1;
	paddle2Base = &paddle2;


	//stopwatch = Stopwatch();
	activeSceneObjects = std::list<SceneObject*>();
	
}

void Game::ResetBall()
{
	ballBase->SetPosition(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f);


	//Generates two random floats between -3 and 3
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(-3.0f, 3.0f);

	float num1;
	float num2;

	//Ensures that both values' absolute values do not go below 1.5f
	//Prevents the ball from going too slow or moving too close in angle to perpendicular
	do {
		num1 = dis(gen);
		num2 = dis(gen);
	} while (std::abs(num1) < 1.5f || std::abs(num2) < 1.5f);

	ball.velocity = Vector3x1(num1, num2, 0);

	paddleSpeed = 2.5f;

}

void Game::Init()
{
	//stopwatch.Start();
	//lastTime = stopwatch.ElapsedMilliseconds();

	ballBase->SetPosition(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f);
	paddle1Base->SetPosition(50, GetScreenHeight() / 2.0f - 40);
	paddle2Base->SetPosition(GetScreenWidth() - 50, GetScreenHeight() / 2.0f - 40);

	activeSceneObjects.push_back(paddle1Base);
	activeSceneObjects.push_back(paddle2Base);
	activeSceneObjects.push_back(ballBase);

	cout << "Number of objects in activeSceneObjects: " << activeSceneObjects.size() << "\n";

	for (SceneObject* obj : activeSceneObjects)
	{
		obj->OnStart();
	}

	ResetBall();


}

void Game::Update()
{

	//currentTime = (long)stopwatch.ElapsedMilliseconds();
	//deltaTime = (currentTime - lastTime) / (float)1000;

	//timer = timer + deltaTime;
	//if (timer >= 1)
	//{
	//	fps = frames;
	//	frames = (float)0;
	//	timer -= (float)1;
	//}

	if (CheckCollisionRecs(paddle1.boxCollider.colliderShape, ball.boxCollider.colliderShape))
	{
		ball.velocity.Reflect(Vector3x1(1, 0, 0));
		ball.velocity = ball.velocity * 1.1f;
		if (paddleSpeed < 5.0f)
		{
			paddleSpeed += 0.05f;
		}

	}
	if (CheckCollisionRecs(paddle2.boxCollider.colliderShape, ball.boxCollider.colliderShape))
	{
		ball.velocity.Reflect(Vector3x1(1, 0, 0));
		ball.velocity = ball.velocity * 1.1f;

		if (paddleSpeed < 5.0f)
		{
			paddleSpeed += 0.05f;
		}
	}

	if (IsKeyDown(KEY_W))
	{
		paddle1.Translate(0, -paddleSpeed);
	}

	if (IsKeyDown(KEY_S))
	{
		paddle1.Translate(0, paddleSpeed);
	}

	if (IsKeyDown(KEY_UP))
	{
		paddle2.Translate(0, -paddleSpeed);
	}

	if (IsKeyDown(KEY_DOWN))
	{
		paddle2.Translate(0, paddleSpeed);
	}

	if (ball.globalTransform.m20 <= 0)
	{
		player2Score++;
		ResetBall();
	}
	if (ball.globalTransform.m20 + ball.boxCollider.colliderShape.width >= GetScreenWidth())
	{
		player1Score++;
		ResetBall();
	}


	for (SceneObject* obj : activeSceneObjects)
	{
		obj->Update(deltaTime);
	}

	lastTime = currentTime;
}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(WHITE);

	//string fpsNum = to_string(fps);
	//const char* fpsCstring = fpsNum.c_str();

	string player1Scorestr = to_string(player1Score);
	const char* player1ScoreCstr = player1Scorestr.c_str();

	string player2Scorestr = to_string(player2Score);
	const char* player2ScoreCstr = player2Scorestr.c_str();

	//DrawText(fpsCstring, 10, 10, 12, RED);

	DrawFPS(5, 5);

	DrawText(player1ScoreCstr, 100, 10, 50, BLUE);

	DrawText(player2ScoreCstr, GetScreenWidth() - 100, 10, 50, BLUE);



	for (SceneObject* obj : activeSceneObjects)
	{
		obj->Draw();
	}


	EndDrawing();

}

