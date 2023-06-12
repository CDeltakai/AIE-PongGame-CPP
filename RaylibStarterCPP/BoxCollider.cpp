#include "BoxCollider.h"
#include "raylib.h"
#include <iostream>

BoxCollider::BoxCollider()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	boxColor = GOLD;
	colliderShape = { 0 };
}

void BoxCollider::InitBox(float x, float y, float width, float height, Color color)
{
	std::cout << "Attempted to add box collider";
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	boxColor = color;
	colliderShape = { x, y, width, height};

		
}

void BoxCollider::OnDraw()
{
	//std::cout << "Attempting to draw with virtual function" << "\n";
	DrawRectangleRec(colliderShape, boxColor);
}

void BoxCollider::OnUpdate(float deltaTime)
{
	colliderShape.x = parent->globalTransform.m20;
	colliderShape.y = parent->globalTransform.m21;

}

