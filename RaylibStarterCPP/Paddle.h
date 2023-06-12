#pragma once
#include "BoxCollider.h"
#include "SceneObject.h"
class Paddle: public SceneObject
{
public:
	BoxCollider boxCollider;
	Paddle();
	void OnStart() override;
	
};

