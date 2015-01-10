//------------------------------------------------------------------
/// \file    Camera.h
/// \author  Lloyd Phillips
/// \brief   This is the camera class
//------------------------------------------------------------------
#ifndef CAMERA_H
#define CAMERA_H
#include "Vec2.h"
class Camera{
public:
	/// \brief Constructor
	Camera();
	/// \brief destructor
	~Camera();
	/// \brief Updates the camera
	/// \Update Function based on position
	void update(Vec2 P);
	/// \brief Draw Function
	/// \Draws camera to the screen
	void draw();
	/// \brief gets the position of the camera
	/// \returns a vec2 of position of the camera, returns x,y
	Vec2 getPos();
private:
	Vec2 position; ///<Position of the camera in form of X,Y
	int levelWid , levelLen, winWid; /// <Level/Window sizes
};
#endif ///!CAMERA_H
