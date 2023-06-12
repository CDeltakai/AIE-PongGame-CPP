#include "Ball.h"
#include "Vector3.h"
#include <iostream>


Ball::Ball()
{
	velocity = Vector3x1(1, 1, 0);
}


void Ball::OnStart()
{
	std::cout << "Attempted to use onstart";
	boxCollider.localTransform = this->globalTransform;
	BoxCollider* boxColliderptr = &boxCollider;
	boxCollider.InitBox(
		this->globalTransform.m20,
		this->globalTransform.m21,
		10,
		10,
		GOLD
	);

	this->AddChild(boxColliderptr);

}

void Ball::OnUpdate(float deltaTime)
{
	Translate(velocity.x, velocity.y);
	//Bounce ball off top and bottom wall
	if (this->globalTransform.m21 <= 0 || this->globalTransform.m21 + boxCollider.colliderShape.height >= GetScreenHeight())
	{
		velocity.Reflect(Vector3x1(0, 1, 0));
		
	}

}

void Ball::Reflect(Vector3x1 normal)
{
	velocity.Reflect(normal);
}
