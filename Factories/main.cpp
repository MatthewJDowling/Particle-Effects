#include "sfwdraw.h"

void main()
{
	sfw::initContext();
	unsigned sprite =
		sfw::loadTextureMap("../res/particle.png");

	while (sfw::stepContext())
	{
		sfw::drawTexture(sprite, 0, 0, 100, 100);
	}

	sfw::termContext();
}