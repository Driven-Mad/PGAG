#include "Seeds.h"


Seeds::Seeds()
{
	Texture::setTexture(NULL);
	setfilename("Seed.bmp");
	pos1 = rand() % 924 +100;
	pos2 = rand() % 924 + 100;
	pos3 = rand() % 924 + 100;
	pos4 = rand() % 924 + 100;
}


Seeds::~Seeds()
{
	SDL_DestroyTexture(Texture::getText());
}
