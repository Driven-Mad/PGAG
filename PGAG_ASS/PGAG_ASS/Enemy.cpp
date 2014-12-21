#include "Enemy.h"


Enemy::Enemy()
{
	Texture::setTexture(NULL);
	setfilename("Enemy.bmp");
	idle = true;
	attackL = attackR = movingL = movingR = recentlyAttacked = false;
	Position = Vec2(900, 650);
	timer = 0;
	startTimer = false;
}

Enemy::~Enemy()
{
}

int Enemy::update(float pos, float DT, int health){
	//updating position
	Position.x = ((Position.x + (Vel.x * DT)));
	Position.y = ((Position.y + (Vel.y * DT)));
	if (Position.x < 0){
		Position.x = 0;
	}
	if (Position.x + 77 > 2048){
		Position.x = 2048 - 100;
	}
	if (Position.y < 0){
		Position.y = 0;
	}
	if (Position.y + 136 > 1536){
		Position.y = 1536 - 70;
	}

	//start a timer
	if (startTimer == true){
		idle = true;
		attackL = attackR = movingL = movingR = false;
		timer++;
	}
		
	if (timer == 1000){
		startTimer = false;
		timer = 0;
		recentlyAttacked = false;
	}
	if (pos <= Position.x && recentlyAttacked==false){
		Vel.x -= 20;
		movingL = true;
		attackL = attackR = idle = movingR = false;
	}
	if (pos >= Position.x && recentlyAttacked == false){
		Vel.x += 20;
		movingR = true;
		attackL = attackR = movingL = idle = false;
	}
	if (pos + 30 >= (Position.x - 5) &&
		pos + 30 <= (Position.x + 5) && 
		recentlyAttacked == false){
		Vel.x = 0;
		//health -= 1;
		recentlyAttacked = true;
		startTimer = true;
	}
	return health;
}