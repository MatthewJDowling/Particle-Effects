#pragma once
#include "sfwdraw.h"
#include "math.h"

struct particle
{
	unsigned sprite; 
	vec2 pos, vel; 
	vec2 sDim, eDim;
	color sColor, eColor;
	
	float lifetime, lifespan; 

	bool refresh(float dt)
	{
		lifetime += dt; 

		float alpha = lifetime / lifespan;

		vec2 dim = lerp(sDim, eDim, alpha);
		color color = lerp(sColor, eColor, alpha);

		pos = pos + vel * dt;

		sfw::drawTexture(sprite, pos.x, pos.y, dim.x, dim.y, 0, true, 0, color.ui_color);

		return alpha < 1; 
	}
};