#ifndef VEC2_H
#define VEC2_H
#include <math.h>

class Vec2{
public:
	///Vector2 Constructors, takes 0,2,3 arg
	Vec2();
	Vec2(float a, float b);
	Vec2(float a, float b, float c);
	~Vec2();
	//Vector Co-ords x,y, (sometimes w)
	float x;
	float y;
	float w;

	const Vec2& operator +=(const Vec2& v);
	const Vec2& operator -=(const Vec2& v);
	const Vec2& operator *=(const Vec2& v);
	const Vec2& operator /=(const Vec2& v);
	const Vec2& operator +=(const float& f);
	const Vec2& operator -=(const float& f);
	const Vec2& operator *=(const float& f);
	const Vec2& operator /=(const float& f);
	const bool& operator ==(const Vec2& v);
	//couple of operations to get dot, cross, mag, and norm of vectors
	const float dot(Vec2 a, Vec2 b);
	const Vec2 cross(Vec2 a, Vec2 b);
	const float magnitude(Vec2 v);
	const Vec2 normalize(Vec2 v);

private:

};
/// Addition Operations for Vec 2's
inline const Vec2 operator + (const Vec2 &a, const Vec2 &b){
	Vec2 temp;
	temp.x = a.x + b.x;
	temp.y = a.y + b.y;
	temp.w = 1.0f;
	return temp;
}
inline const Vec2 operator + (const Vec2 &v, const float &f){
	Vec2 temp;
	temp.x = v.x + f;
	temp.y = v.y + f;
	temp.w = 1.0f;
	return temp;
}
/// Subtraction Operations for Vec 2's
inline const Vec2 operator - (const Vec2 &a, const Vec2 &b){
	Vec2 temp;
	temp.x = a.x + -b.x;
	temp.y = a.y + -b.y;
	temp.w = 1.0f;
	return temp;
}
inline const Vec2 operator - (const Vec2 &v, const float &f){
	Vec2 temp;
	temp.x = v.x + -f;
	temp.y = v.y + -f;
	temp.w = 1.0f;
	return temp;
}
/// Multiplication Operations for Vec 2's
inline const Vec2 operator * (const Vec2 &a, const Vec2 &b){
	Vec2 temp;
	temp.x = a.x * b.x;
	temp.y = a.y * b.y;
	temp.w = 1.0f;
	return temp;
}
inline const Vec2 operator * (const Vec2 &v, const float &f){
	Vec2 temp;
	temp.x = v.x * f;
	temp.y = v.y * f;
	temp.w = 1.0f;
	return temp;
}
/// Divide Operations for Vec 2's
inline const Vec2 operator / (const Vec2 &a, const Vec2 &b){
	Vec2 temp;
	temp.x = a.x / b.x;
	temp.y = a.y / b.y;
	temp.w = 1.0f;
	return temp;
}
inline const Vec2 operator / (const Vec2 &v, const float &f){
	Vec2 temp;
	temp.x = v.x / f;
	temp.y = v.y / f;
	temp.w = 1.0f;
	return temp;
}
/// Negate Operations for Vec 2's
inline const Vec2 operator -(const Vec2 v){
	Vec2 temp;
	temp.x = -v.x;
	temp.y = -v.y;
	return temp;
}
#endif