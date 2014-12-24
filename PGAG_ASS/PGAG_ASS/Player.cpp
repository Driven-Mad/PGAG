
#include "Player.h"
///Constructor
Player::Player(){
	Texture::setTexture(NULL);
	pos = Vec2(0.0f, 590.0f);
	vel = Vec2(0.0f, 0.0f);
	movingL = false;
	movingR = false;
	isJumping = false;
	idle = true;
	magic = 0;
	health = 4;
}
///Destructor
Player::~Player(){
	if (Texture::getText()){
		SDL_DestroyTexture(Texture::getText());
	}
}
///////////////////////
///Getters and Setters/
///////////////////////
int Player::getHealth(){
	return health;
}
void Player::setHealth(int i){
	health = i;
}
int Player::getMagic(){
	return magic;
}
void Player::setMagic(int i){
	magic = i;
}
Vec2 Player::getPos(){
	return pos;
}
void Player::setPos(Vec2 p){
	pos = p;
}
Vec2 Player::getVel(){
	return vel;
}
void Player::setVel(Vec2 v){
	vel = v;
}
///////////////////
///update Function/
///////////////////
void Player::update(float DT)
{
	///Constantly Adding Vel to the position of the player
	pos.x = ((pos.x + (vel.x * DT)));
	pos.y = ((pos.y + (vel.y * DT)));
	///if player goes off screen
	if (pos.x < 0){
		pos.x = 0;
	}
	if (pos.x + 77 > 2048){
		pos.x = 2048 - 77;
	}
	if (pos.y < 0){
		pos.y = 0;
	}
	if (pos.y + 136 > 768){
		pos.y = 768 - 136;
	}

	///set the stance based on bool stance
	if (idle){
		stance = 0;
	}
	if (movingL){
		stance = 1;
	}
	if (movingR){
		stance = 2;
	}
	if (isJumping && onGround){
		oldPos = pos;
		stance = 3;
		onGround = false;
		idle = false;
	}
	///Jump only 100 pixels high
	if (oldPos.y - pos.y >= 100.0f){
 		isJumping = false;
		onGround = false;
		idle = true;
	}
	///if the player gets up on the blockade
	if ((pos.y > 367) &&
		(pos.y < 369) &&
		(pos.x + 30 >= 1800) &&
		(pos.x + 30 <= 2000)){
		onGround = true;
	}
	else{
		onGround = false;
	}
	///General floor
	if (pos.y >590){
		onGround = true;
	}
	///if on floor stops moving up and down
	if (onGround){
		vel.y = 0;
		isJumping = false;
	}
	///switch statment based on stances
	switch (stance){
	case 0:
		vel.x = 0.0f;
		if (isJumping == false && onGround == false){
			vel.y += 50.0f;
		}
		break;
	case 1:
		vel.x = vel.x - 20.0f;
		if (!onGround && !isJumping){
			vel.y += 50.0f;
		}
		break;
	case 2:
		vel.x = vel.x + 20.0f;
		if (!onGround && !isJumping){
			vel.y += 50.0f;
		}
		break;
	case 3:
		vel.y = vel.y - 20.0f;
		break;
	default:
		break;
	}
}

 