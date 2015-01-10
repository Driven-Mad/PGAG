#include "Camera.h"

//Constructor
Camera::Camera(){
	
}
//Destructor
Camera::~Camera(){
}
//Getters and Setters
Vec2 Camera::getPos(){
	return position;
}

//update Function
void Camera::update(Vec2 P){
	int levelWid = 2048, levelLen = 768, winWid = 1024;
	//Constantly updating the position based on the player
	position.x = (P.x + 77 / 2) - winWid/2 ;
	position.y = (P.y + 132 / 2) - levelLen;
	//Stops the camera going off screen
	if (position.x < 0){
		position.x = 0;
	}
	if (position.y < 0){
		position.y = 0;
	}
	if (position.x > levelWid -winWid){
		position.x = float(levelWid - winWid);
	}
}
