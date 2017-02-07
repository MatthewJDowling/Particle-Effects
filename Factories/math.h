#pragma once
#include <random>
#include <cmath>
inline float rand01()
{
	return (float)rand() / RAND_MAX;
}

inline float lerp(float s, float e, float t)
{
	return s*(t - 1) + e*t;
}
struct vec2 { float x, y; };

#define DEG2RAD 0.0174533
///////////////////////////////////////////////////////
inline vec2 operator+(const vec2 &A, const vec2 &B)
{
	return vec2{ A.x + B.x, A.y + B.y };
}

inline vec2 operator*(const vec2 &A, float B)
{
	return vec2{ A.x * B, A.y + B};
}

inline vec2 lerp(const vec2 &S, const vec2 &E, float t)
{
	return S*(t - 1) + E *t; 
}

inline vec2 randRange(const vec2 &A, const vec2 &B)
{
	return vec2{ lerp(A.x,B.x,rand01()), lerp(A.y,B.y,rand01()) };
}

inline vec2 randDir(float angle_degrees, float angle_degrees2)
{
	float deg = lerp(angle_degrees, angle_degrees2, rand01());
	float rad = DEG2RAD * deg; 

	return vec2{ cos(rad), sin(rad) }; 
}

//////////////////////////////////

union color
{
	unsigned ui_color; 
	struct { unsigned char r, g, b, a; };
};

inline color lerp(const color &S, const color &E, float t)
{
	color ret; 
	ret.r = S.r*(1 - t) + E.r *t; 
	ret.g = S.g*(1 - t) + E.g *t;
	ret.b = S.b*(1 - t) + E.b *t;
	ret.a = S.a*(1 - t) + E.a *t;
	return ret; 
}