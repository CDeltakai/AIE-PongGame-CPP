#include "Matrix3.h"

using namespace std;

Matrix3::Matrix3()
{
    m00 = 1;
    m01 = 0;
    m02 = 0;

    m10 = 0;
    m11 = 1;
    m12 = 0;

    m20 = 0;
    m21 = 0;
    m22 = 1;

}

Matrix3::Matrix3(float M00 = 1, float M01 = 0, float M02 = 0,
                 float M10 = 0, float M11 = 1, float M12 = 0,
                 float M20 = 0, float M21 = 0, float M22 = 1)
{
    m00 = M00;
    m01 = M01;
    m02 = M02;

    m10 = M10;
    m11 = M11;
    m12 = M12;

    m20 = M20;
    m21 = M21;
    m22 = M22;

}

Matrix3::Matrix3(float uniformScale)
{
    m00 = uniformScale;
    m01 = 0;
    m02 = 0;

    m10 = 0;
    m11 = uniformScale;
    m12 = 0;

    m20 = 0;
    m21 = 0;
    m22 = uniformScale;
}


Matrix3 Matrix3::operator*(Matrix3 b)
{
    return Matrix3((m00 * b.m00 + m10 * b.m01 + m20 * b.m02), (m01 * b.m00 + m11 * b.m01 + m21 * b.m02), (m02 * b.m00 + m12 * b.m01 + m22 * b.m02),

                    (m00 * b.m10 + m10 * b.m11 + m20 * b.m12), (m01 * b.m10 + m11 * b.m11 + m21 * b.m12), (m02 * b.m10 + m12 * b.m11 + m22 * b.m12),

                    (m00 * b.m20 + m10 * b.m21 + m20 * b.m22), (m01 * b.m20 + m11 * b.m21 + m21 * b.m22), (m02 * b.m20 + m12 * b.m21 + m22 * b.m22)

                    );
}


void Matrix3::SetTranslation(float x, float y)
{
    m20 = x;
    m21 = y;
}

void Matrix3::Translate(float x, float y)
{
    m20 += x;
    m21 += y;


}