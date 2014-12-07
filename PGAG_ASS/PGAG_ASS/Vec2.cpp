#include "Vec2.h"
#include <math.h>

///Vector2 Constructors, takes 0,2,3 arg
Vec2::Vec2() : x(0.0f), y(0.0f), w(1.0f) {}
Vec2::Vec2(float a, float b) : x(a), y(b), w(1.0f){}
Vec2::Vec2(float a, float b, float c) : x(a), y(b), w(c) {}


Vec2::~Vec2()
{
}
///+= operation for Vec2
const Vec2& Vec2::operator +=(const Vec2& v)
{
	x += v.x;
	y += v.y;
	w = 1.0f;
	return *this;
}
///-= operation for Vec2
const Vec2& Vec2::operator -=(const Vec2& v)
{
	x -= v.x;
	y -= v.y;
	w = 1.0f;
	return *this;
}
///*= operation for Vec2
const Vec2& Vec2::operator *=(const Vec2& v)
{
	x *= v.x;
	y *= v.y;
	w = 1.0f;
	return *this;
}
/// /= operation for Vec2
const Vec2& Vec2::operator /=(const Vec2& v)
{
	x /= v.x;
	y /= v.y;
	w = 1.0f;
	return *this;
}
///+= operation for Vec2 + float
const Vec2& Vec2::operator +=(const float& f)
{
	x += f;
	y += f;
	w = 1.0f;
	return *this;
}
///-= operation for Vec2 + float
const Vec2& Vec2::operator -=(const float& f)
{
	x -= f;
	y -= f;
	w = 1.0f;
	return *this;
}
///*= operation for Vec2 + float
const Vec2& Vec2::operator *=(const float& f)
{
	x *= f;
	y *= f;
	w = 1.0f;
	return *this;
}
/// /= operation for Vec2 + float
const Vec2& Vec2::operator /=(const float& f)
{
	x /= f;
	y /= f;
	w = 1.0f;
	return *this;
}