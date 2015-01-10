#include "Vec2.h"

//Vector2 Constructors, takes 0,2,3 arg
Vec2::Vec2() : x(0.0f), y(0.0f), w(1.0f) {}
Vec2::Vec2(float a, float b) : x(a), y(b), w(1.0f){}
Vec2::Vec2(float a, float b, float c) : x(a), y(b), w(c) {}
Vec2::~Vec2(){
}

//== opertion for Vec2
const bool Vec2::operator ==(const Vec2& v){
	if (x == v.x && y == v.y && w == v.w)
		return true;
	else
		return false;
}
//+= operation for Vec2
const Vec2& Vec2::operator +=(const Vec2& v){
	x += v.x;
	y += v.y;
	w = 1.0f;
	return *this;
}
//-= operation for Vec2
const Vec2& Vec2::operator -=(const Vec2& v){
	x -= v.x;
	y -= v.y;
	w = 1.0f;
	return *this;
}
//*= operation for Vec2
const Vec2& Vec2::operator *=(const Vec2& v){
	x *= v.x;
	y *= v.y;
	w = 1.0f;
	return *this;
}
// /= operation for Vec2
const Vec2& Vec2::operator /=(const Vec2& v){
	x /= v.x;
	y /= v.y;
	w = 1.0f;
	return *this;
}
// += operation for Vec2 + float
const Vec2& Vec2::operator +=(const float& f){
	x += f;
	y += f;
	w = 1.0f;
	return *this;
}
// -= operation for Vec2 + float
const Vec2& Vec2::operator -=(const float& f){
	x -= f;
	y -= f;
	w = 1.0f;
	return *this;
}
// *= operation for Vec2 + float
const Vec2& Vec2::operator *=(const float& f){
	x *= f;
	y *= f;
	w = 1.0f;
	return *this;
}
// /= operation for Vec2 + float
const Vec2& Vec2::operator /=(const float& f){
	x /= f;
	y /= f;
	w = 1.0f;
	return *this;
}
// Dot product function
const float Vec2::dot(Vec2 a, Vec2 b){
	float temp;
	temp = (a.x * b.x) + (a.y * b.y);
	return temp;
}
// Cross Product function
const Vec2 Vec2::cross(Vec2 a, Vec2 b){
	Vec2 temp;
	temp.x = a.x * b.y;
	temp.y = a.y * b.x;
	return temp;
}
// Magnitude function
const float Vec2::magnitude(Vec2 v){
	float a;
	a = sqrtf(dot(v, v));
	return a;
}
// Normalizing Function
const Vec2 Vec2::normalize(Vec2 v){
	float m = magnitude(v);
	if (m != 0){
		Vec2 temp;
		temp.x = v.x / m;
		temp.y = v.y / m;
		return temp;
	}
	else{
		return Vec2(0, 0);
	}
}