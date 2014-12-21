#pragma once
#include "Vec2.h"
#include "Player.h"
class Camera
{
public:
	Camera();
	~Camera();
	void update(Vec2 P);
	Vec2 getPos();
	void draw();
	SDL_Rect getCam();
private:
	Vec2 position;
	int levelx, levely , levelWid , levelLen;
	int winX , winY ,winWid, winLen;
	SDL_Rect camera;
};

