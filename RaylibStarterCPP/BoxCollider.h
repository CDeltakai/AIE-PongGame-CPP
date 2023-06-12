#pragma once
#include "SceneObject.h"
#include "raylib.h"

class BoxCollider : public SceneObject
{
public:
	float x, y, width, height;

	Color boxColor = GOLD;

	Rectangle colliderShape;
	BoxCollider();

	void InitBox(float x, float y, float width, float height, Color color);

	void OnDraw() override;
	void OnUpdate(float deltaTime) override;


};

