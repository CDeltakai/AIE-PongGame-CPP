#pragma once
class Matrix3
{
public:
	float m00, m01, m02;
	float m10, m11, m12;
	float m20, m21, m22;

	Matrix3();

	Matrix3(float m00, float m01, float m02,
			float m10, float m11, float m12,
			float m20, float m21, float m22);

	Matrix3(float uniformScale);

	Matrix3 operator *(Matrix3 b);

	//void SetRotateX(float angle);
	//void SetRotateY(float angle);
	//void SetRotateZ(float angle);
	void SetTranslation(float x, float y);
	//void SetScaled(float width, float height, int v);
	void Translate(float x, float y);





};

