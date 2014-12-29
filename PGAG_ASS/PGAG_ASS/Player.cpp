
#include "Player.h"
///Constructor
Player::Player(){
	Texture::setTexture(NULL);
	pos = Vec2(0.0f, 590.0f);
	vel = Vec2(0.0f, 0.0f);
	isJumping = movingL = movingR = hittingAWall = onPlatform = casting = inRange = canClimb = false;
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
bool Player::update(float DT){
	///Looks after player user input from the keyboard, and uses boolians to set actions
	SDL_Event incoming;
	while (SDL_PollEvent(&incoming)){
		switch (incoming.type){
		case SDL_QUIT:
			return false;
			break;
		case SDL_KEYDOWN:
			switch (incoming.key.keysym.sym){
			case SDLK_LEFT:
				movingL = true;
				break;
			case SDLK_RIGHT:
				movingR = true;
				break;
			case SDLK_UP:
				isJumping = true;
				if (canClimb){
					isJumping = false;
					pos.y -= 10;
				}
				break;
			case SDLK_SPACE:
				if (magic == 4 && inRange ){
					casting = true;
				}
				break;
			default:
				idle = true;
				break;
			}
			break;
		case SDL_KEYUP:
			idle = true;
			movingL = false;
			movingR = false;
			isJumping = false;
			casting = false;
			break;
		}
	}
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
	///if the player dies, then the game ends.
	if (health < 0){
		return false;
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
	if (isJumping && (onGround  || onPlatform)){
		oldPos = pos;
		stance = 3;
		onGround = false;
		idle = false;
	}
	///Jump only 100 pixels high
	if (isJumping){
		if (oldPos.y - pos.y >= 100.0f){
			isJumping = false;
			onGround = false;
			idle = true;
		}
	}
	
	///General floor
	if (pos.y > 590){
		onGround = true;
	}
	///if the player is hitting a wall, will remove all the velocity and take it positions back a place.
	if (hittingAWall && !onPlatform && !onGround){
			vel.x = 0;
			pos.x -= 1;
			isJumping = false;
	}
	///if on floor or Platform stops moving up and down, would have used an onGround || onPlatform, however this did not work
	if (onGround){
		vel.y = 0;
		isJumping = false;
	}
	if (onPlatform){
		vel.y = 0;
		isJumping = false;
	}
	
	///switch statment based on stances
	switch (stance){
	case 0:
		vel.x = 0.0f;
		if (isJumping == false && onGround == false && !onPlatform){
			vel.y += 50.0f;
		}
		break;
	case 1:
		vel.x = vel.x - 20.0f;
		if (!onGround && !isJumping && !onPlatform){
			vel.y += 50.0f;
		}
		break;
	case 2:
		vel.x = vel.x + 20.0f;
		if (!onGround && !isJumping && !onPlatform){
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

 