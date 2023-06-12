#include "Vector3.h"
#include <cmath>

Vector3x1::Vector3x1(float X, float Y, float Z)
{
	x = X;
	y = Y;
	z = Z;


}



Vector3x1 Vector3x1::operator+(Vector3x1 v2) const
{
	return Vector3x1(x + v2.x, y + v2.y, z + v2.z);
}

Vector3x1 Vector3x1::operator-(Vector3x1 v2) const
{
	return Vector3x1(x - v2.x, y - v2.y, z - v2.z);
}

Vector3x1 Vector3x1::operator*(float scalar) const
{
	return Vector3x1(x * scalar, y * scalar, z * scalar);
}



Vector3x1 Vector3x1::operator*(Matrix3 matrix3) const
{
	return Vector3x1((matrix3.m00 * x + matrix3.m10 * y + matrix3.m20 * z),
		(matrix3.m01 * x + matrix3.m11 * y + matrix3.m21 * z),
		(matrix3.m02 * x + matrix3.m12 * y + matrix3.m22 * z)
	);
}

float Vector3x1::Dot(Vector3x1 v)
{
	return (x * v.x + y * v.y + z * v.z);
}

Vector3x1 Vector3x1::Cross(Vector3x1 b)
{
	return Vector3x1(y * b.z - z * b.y,
					z * b.x - x * b.z,
					x * b.y - y * b.x);
}

float Vector3x1::Magnitude()
{
	return sqrt(x * x + y * y + z * z);
}

void Vector3x1::Normalize()
{
	float mag = this->Magnitude();

	x = x / mag;
	y = y / mag;
	z = z / mag;

}

void Vector3x1::Reflect(Vector3x1 normal)
{

	float dotProduct = Dot(normal);
	*this = *this - (normal * (float)2) * dotProduct;

	


}
