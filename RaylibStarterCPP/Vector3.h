#pragma once
#include "Matrix3.h"
class Vector3x1
{
public:
	float x, y, z;
	Vector3x1(float x = 0, float y = 0, float z = 0);

	Vector3x1 operator +(Vector3x1 v2) const;

	Vector3x1 operator -(Vector3x1 v2) const;

	Vector3x1 operator *(float scalar) const;


	Vector3x1 operator *(Matrix3 matrix3) const;


	float Dot(Vector3x1 v);


	Vector3x1 Cross(Vector3x1 b);


	float Magnitude();


	void Normalize();


public:
	void Reflect(Vector3x1 normal);


};

