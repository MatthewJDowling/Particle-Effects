#pragma once

struct vec2 { float x, y; };

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

//////////////////////////////////

union color
{
	unsigned ui_color; 
	struct { char r, g, b, a; };
};

inline color lerp(const color &S, const color &E, float t)
{
	color ret; 
	ret.r = S.r*(t - 1) + E.r *t; 
	ret.g = S.r*(t - 1) + E.r *t;
	ret.b = S.r*(t - 1) + E.r *t;
	ret.a = S.r*(t - 1) + E.r *t;
	return ret; 
}