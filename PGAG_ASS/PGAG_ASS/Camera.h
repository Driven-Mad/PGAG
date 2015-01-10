#ifndef CAMERA_H
#define CAMERA_H
//------------------------------------------------------------------
/// \file    Camera.h
/// \author  Lloyd Phillips
/// \brief   This is the Camera class
//------------------------------------------------------------------
#include "Vec2.h"
class Camera{
public:
	/// \brief Constructor
	Camera();
	/// \brief destructor
	~Camera();

	/// \brief Updates the camera
	/// \brief Update Function based on position
	void update(Vec2 P);
	/// \brief Draw Function
	/// \brief Draws Camera to the screen
	void draw();
	/// \brief gets the position of the camera
	/// \returns a Vec2 of position of the camera, returns x, y
	Vec2 getPos();
private:
	Vec2 position; ///<Position of the Camera in form of X, Y
	int levelWid , levelLen, winWid; /// <Level/Window sizes
};
#endif ///!CAMERA_H
