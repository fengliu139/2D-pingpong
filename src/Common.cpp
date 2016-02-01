/**
*@file Comm.cpp
*@brief draw obstacles avoid overlapping the robot
*/

#include "Common.h"


Object::Object() : flagDraw(true)
{
}

Object::~Object()
{
}

/*
 * @brief avoid overlapping
 * @param posLeftTop
 * @param posRightBottom
 */
bool Object::detectOverlapping(GLPosition &posLeftTop, GLPosition &posRightBottom, const GLint &radius)
{
	if (0 == position.posX && 0 == position.posY)
		return false;

	/**
	*@code arrange data of the rectangle
	*/
	float dist;
	if (posLeftTop.posX > posRightBottom.posX)
	{
		dist = posRightBottom.posX;
		posRightBottom.posX = posLeftTop.posX;
		posLeftTop.posX = dist;
	}
	if (posLeftTop.posY > posRightBottom.posY)
	{
		dist = posRightBottom.posY;
		posRightBottom.posY = posLeftTop.posY;
		posLeftTop.posY = dist;
	}
    /** @endcode */ 
    
	/**
	*@code
	* check whether inscribed square of the cirle and the rectangle cross,
	* express the inscribed square with four line which can be expressed by a number
	*/
	dist = radius / (float)1.4142136;

	float xSquare1 = position.posX - dist;
	float xSquare2 = position.posX + dist;
	float ySquare1 = position.posY - dist;
	float ySquare2 = position.posY + dist;

	if (xSquare1 <= posRightBottom.posX && xSquare2 >= posLeftTop.posX && ySquare1 <= posLeftTop.posY
		&& ySquare2 >= posRightBottom.posY)
	{
		return true;
	}
	/** @endcode */ 

	/**
	* @code check whether there is a vertex of the rectangle in the circle position of rectangle
	*/
	float xrectangle = (posLeftTop.posX + posRightBottom.posX) / 2;
	float yrectangle = (posLeftTop.posY + posRightBottom.posY) / 2;
	/**@endcode */

	/**@code rectangle is on the top left side of circle*/
	if (xrectangle <= position.posX && yrectangle <= position.posY
		&& sqrt((posRightBottom.posX - position.posX) * (posRightBottom.posX - position.posX) + (posRightBottom.posY - position.posY) *
		(posRightBottom.posY - position.posY)) <= radius)
		return true;
	else if (xrectangle > position.posX && yrectangle <= position.posY
		&& sqrt((posLeftTop.posX - position.posX) * (posLeftTop.posX - position.posX) + (posRightBottom.posY - position.posY) *
		(posRightBottom.posY - position.posY)) <= radius)
		return true;
	else if (xrectangle <= position.posX && yrectangle > position.posY
		&& sqrt((posRightBottom.posX - position.posX) * (posRightBottom.posX - position.posX) + (posLeftTop.posY - position.posY) *
		(posLeftTop.posY - position.posY)) <= radius)
		return true;
	else if (sqrt((posLeftTop.posX - position.posX) * (posLeftTop.posX - position.posX) + (posLeftTop.posY - position.posY) *
		(posLeftTop.posY - position.posY)) <= radius)
		return true;
	/** @endcode */ 	

	/**@code check whether there is one of the four points of the circle is in the rectangle*/
	if (((position.posX - radius >= posLeftTop.posX && position.posX - radius <= posRightBottom.posX) ||
		(position.posX + radius >= posLeftTop.posX && position.posX + radius <= posRightBottom.posX))
		&& position.posY >= posLeftTop.posY && position.posY <= posRightBottom.posY ||
		((position.posY - radius >= posLeftTop.posY && position.posY - radius >= posRightBottom.posY) ||
		(position.posY + radius >= posLeftTop.posY && position.posY + radius <= posRightBottom.posY)) &&
		position.posX >= posLeftTop.posX && position.posX <= posRightBottom.posX)
	{
		return true;
	}
    /** @endcode */ 
	
	/**no case match*/
	return false;

}

/*
*@brief detectWall.
*@param width the width of the window
*@param height the height of the window
*/
bool Object::detectWall(const GLint &width, const GLint &height, const GLint &radius)  const
{
	if ((position.posX + radius > width) || (position.posX < radius))
		return true;
	else if ((position.posY + radius) > height || (position.posY < radius))
		return true;
	else
		return false;
}
