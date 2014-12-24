#ifndef CAMERA_H
#define CAMERA_H
#include "Vec2.h"
class Camera{
public:
	Camera();
	~Camera();
	///Update Function based on players position
	void update(Vec2 P);
	void draw();
	///Get position of the camera
	Vec2 getPos();
private:
	///Private Variables
	///Vec2's
	Vec2 position;
	///Int's
	int levelWid , levelLen, winWid;
};
#endif
