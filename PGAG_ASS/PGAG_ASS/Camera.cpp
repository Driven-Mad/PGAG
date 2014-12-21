#include "Camera.h"


Camera::Camera()
{
	
}


Camera::~Camera()
{
}
SDL_Rect Camera::getCam(){
	return camera;
}
Vec2 Camera::getPos(){
	return position;
}

void Camera::update(Vec2 P){
	int levelx = 0, levely = 0, levelWid = 2048, levelLen = 1536;
	int winX = 100, winY = 100, winWid = 1024, winLen = 768;
	position.x = (P.x + 77 / 2) - levelWid/2 ;
	position.y = (P.y + 132 /2) - levelLen/2;

	if (position.x < 0)
	{
		position.x = 0;
	}
	if (position.y < 0)
	{
		position.y = 0;
	}
	if (position.x > levelWid -winWid)
	{
		position.x = levelWid - winWid;
	}
	if (position.y > levelLen-winLen )
	{
		position.y = levelLen - winLen;
	}
}
