//------------------------------------------------------------------
/// \file    Vec2.h
/// \author  Lloyd Phillips
/// \brief   This is the Vec2 class
//------------------------------------------------------------------
#ifndef VEC2_H
#define VEC2_H
#include <math.h>
class Vec2{
public:
	/// \brief Vector2 Constructors, takes 0,2,3 arg
	Vec2();
	Vec2(float a, float b);
	Vec2(float a, float b, float c);
	~Vec2();
	/// \brief Vector Co-ords x,y, (sometimes w)
	float x;
	float y;
	float w;
	/// \brief += operator
	const Vec2& operator +=(const Vec2& v);
	/// \brief -= operator
	const Vec2& operator -=(const Vec2& v);
	/// \brief *= operator
	const Vec2& operator *=(const Vec2& v);
	/// \brief /= operator
	const Vec2& operator /=(const Vec2& v);
	/// \brief += operator with floats
	const Vec2& operator +=(const float& f);
	/// \brief -= operator with floats
	const Vec2& operator -=(const float& f);
	/// \brief *= operator with floats
	const Vec2& operator *=(const float& f);
	/// \brief /= operator with floats
	const Vec2& operator /=(const float& f);
	/// \brief == operator
	const bool operator ==(const Vec2& v);
	/// \brief dot product calculations
	const float dot(Vec2 a, Vec2 b);
	/// \brief cross product calculations
	const Vec2 cross(Vec2 a, Vec2 b);
	/// \brief Magnitude product calculations
	const float magnitude(Vec2 v);
	/// \brief Normalize product calculations
	const Vec2 normalize(Vec2 v);
private:
};
/// \brief Addition Operations for Vec 2's
inline const Vec2 operator + (const Vec2 &a, const Vec2 &b){
	Vec2 temp;
	temp.x = a.x + b.x;
	temp.y = a.y + b.y;
	temp.w = 1.0f;
	return temp;
}
/// \brief Addition Operations for Floats
inline const Vec2 operator + (const Vec2 &v, const float &f){
	Vec2 temp;
	temp.x = v.x + f;
	temp.y = v.y + f;
	temp.w = 1.0f;
	return temp;
}
/// \brief Subtraction Operations for Vec 2's
inline const Vec2 operator - (const Vec2 &a, const Vec2 &b){
	Vec2 temp;
	temp.x = a.x + -b.x;
	temp.y = a.y + -b.y;
	temp.w = 1.0f;
	return temp;
}
/// \brief Subtraction Operations for Floats
inline const Vec2 operator - (const Vec2 &v, const float &f){
	Vec2 temp;
	temp.x = v.x + -f;
	temp.y = v.y + -f;
	temp.w = 1.0f;
	return temp;
}
/// \brief Multiplication Operations for Vec 2's
inline const Vec2 operator * (const Vec2 &a, const Vec2 &b){
	Vec2 temp;
	temp.x = a.x * b.x;
	temp.y = a.y * b.y;
	temp.w = 1.0f;
	return temp;
}
/// \brief Multiplication Operations for Floats
inline const Vec2 operator * (const Vec2 &v, const float &f){
	Vec2 temp;
	temp.x = v.x * f;
	temp.y = v.y * f;
	temp.w = 1.0f;
	return temp;
}
/// \brief Divide Operations for Vec 2's
inline const Vec2 operator / (const Vec2 &a, const Vec2 &b){
	Vec2 temp;
	temp.x = a.x / b.x;
	temp.y = a.y / b.y;
	temp.w = 1.0f;
	return temp;
}
/// \brief Divide operator with floats and Vec2's
inline const Vec2 operator / (const Vec2 &v, const float &f){
	Vec2 temp;
	temp.x = v.x / f;
	temp.y = v.y / f;
	temp.w = 1.0f;
	return temp;
}
/// \brief Negate Operations for Vec 2's
inline const Vec2 operator -(const Vec2 v){
	Vec2 temp;
	temp.x = -v.x;
	temp.y = -v.y;
	return temp;
}
#endif ///!VEC2_H