#include "Enemy.h"


///Enemy Constructor
Enemy::Enemy(){
	Texture::setTexture(NULL);
	setfilename("Enemy.bmp");
	idle = true;
	attackL = attackR = movingL = movingR = recentlyAttacked = false;
	Position = Vec2(900, 700);
	timer = 0;
	startTimer = false;
}
///Enemy Destructor
Enemy::~Enemy(){
	if (Texture::getText()){
		SDL_DestroyTexture(Texture::getText());
	}
}
///////////////////////
///Getters and Setters/
///////////////////////
Vec2 Enemy::getPos(){
	return Position;
}
///////////////////
///update Function/
///////////////////
void Enemy::update(Player *P, float DT, Diamond *d){
	///updating position constantly 
	Position.x = ((Position.x + (Vel.x * DT)));
	Position.y = ((Position.y + (Vel.y * DT)));
	///stops the player going off screen
	if (Position.x < 0){
		Position.x = 0;
	}
	if (Position.x + 100 > 2048){
		Position.x = 2048 - 100;
	}
	if (Position.y < 0){
		Position.y = 0;
	}
	if (Position.y + 70 > 700){
		Position.y = 700 - 70;
	}
	///start a timer
	if (startTimer == true){
		idle = true;
		attackL = attackR = movingL = movingR = false;
		timer++;
	}	
	///When timer is 1000 restart it
	if (timer == 1000){
		startTimer = false;
		timer = 0;
		recentlyAttacked = false;
	}
	if (!P->onPlatform && !d->collected){
		///Checks to see if the enemy can move LEFT
		if (P->getPos().x <= Position.x && recentlyAttacked == false){
			Vel.x -= 20;
			movingL = true;
			attackL = attackR = idle = movingR = false;
		}
		///Checks to see if the enemy can move RIGHT
		if (P->getPos().x >= Position.x && recentlyAttacked == false){
			Vel.x += 20;
			movingR = true;
			attackL = attackR = movingL = idle = false;
		}
		///Checks to see if the Player && Enemy are close enough to have the player be bitten AND if the player has been bitten recently
		if (P->getPos().x + 30 >= (Position.x - 5) &&
			P->getPos().x + 30 <= (Position.x + 5) &&
			Position.y >= (P->getPos().y + 20) &&
			Position.y <= (P->getPos().y + 50) &&
			recentlyAttacked == false){
			Vel.x = 0;
			P->setHealth(P->getHealth() - 1);
			recentlyAttacked = true;
			startTimer = true;
		}
	}
	else{
		Vel.x = 0;
		idle = true;
	}
}