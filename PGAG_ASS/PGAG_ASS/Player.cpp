#include "Player.h"
#include "Game.h"


Player::Player(){
	Texture::setTexture(NULL);
	pos = Vec2(0.0f, 590.0f);
	vel = Vec2(0.0f, 0.0f);
	movingL = false;
	movingR = false;
	isJumping = false;
	idle = true;
}


Player::~Player(){
	if (Texture::getText()){
		SDL_DestroyTexture(Texture::getText());
	}
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
void Player::movement(float DT)
{

	pos.x = ((pos.x + (vel.x * DT)));
	pos.y = ((pos.y + (vel.y * DT)));
	if (idle){
		stance = 0;
	}
	if (movingL){
		stance = 1;
	}
	if (movingR){
		stance = 2;
	}
	if (isJumping){
		stance = 3;
		onGround = false;
	}
	if (pos.y <=500.0f){
 		isJumping = false;
		idle = true;
	}
	
	if (pos.y > 594)
	{
		pos.y = 594;
		onGround = true;
		vel.y = 0;
	}

	switch (stance)
	{
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

 