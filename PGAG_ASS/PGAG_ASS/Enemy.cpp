#include "Enemy.h"


Enemy::Enemy()
{
	Texture::setTexture(NULL);
	setfilename("Enemy.bmp");
	idle = true;
	attackL = attackR = movingL = movingR = recentlyAttacked = false;
	Position = Vec2(900, 650);
	timer = 0;
}

Enemy::~Enemy()
{
}

int Enemy::update(float pos, float DT, int health){
	unsigned int current = SDL_GetTicks();
	Position.x = ((Position.x + (Vel.x * DT)));
	Position.y = ((Position.y + (Vel.y * DT)));
	Uint32 tempSeconds = current / 100;
	timer = tempSeconds % 15;
	if (recentlyAttacked && timer > 0)
	{
		idle = true;
		attackL = attackR = movingL = movingR = false;
		if (timer == 14){
			timer = 0;
			recentlyAttacked = false;
		}
	}
	
	if (pos <= Position.x && !recentlyAttacked){
		Vel.x -= 20;
		movingL = true;
		attackL = attackR = idle = movingR = false;
	}
	if (pos >= Position.x && !recentlyAttacked){
		Vel.x += 20;
		movingR = true;
		attackL = attackR = movingL = idle = false;
	}
	if (pos + 30 >= (Position.x - 5) &&
		pos + 30 <= (Position.x + 5)&& !recentlyAttacked){
		Vel.x = 0;
		recentlyAttacked = true;
		health -= 1;
	}
	return health;
}