#pragma once
#include "BoxCollider.h"
#include "Vector3.h"
#include "SceneObject.h"

class Ball: public SceneObject
{
public:
	Vector3x1 velocity;
	BoxCollider boxCollider;

	Ball();
	void OnStart() override;
	void OnUpdate(float deltaTime) override;
	void Reflect(Vector3x1 normal);



};

