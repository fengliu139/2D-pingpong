/**
* @file Ball.h
* @brief header of Ball
*/
#ifndef BALL_H
#define BALL_H

#include "Common.h"


/**
 * @brief Ball.  This provides means to store and alter robot state.
 */
class Ball : public Object
{
	friend class RobotTests;

public:
	Ball();	
	Ball(GLPosition &pos, GLint r, GLint d); 

	virtual ~Ball();
/**
 *@brief orientation in degrees
 *GLint getOrientation(),speed in pixels per second
 */
public:	
	void setOrientation(const GLint &degrees);
        GLint getOrientation();

	void setSpeed(const GLint &pps);
	GLint getSpeed();


public:
	virtual void move(const time_t elapsedTime);
	virtual void render(const glColorVec &c);
 virtual bool detectCollision();

public:
	void updatePosition(const GLPosition &newPos);
	void CheackHitWall();

public:
	GLint getRadius() const;

protected:
	virtual void draw();
	
	bool detectObstacle(const Object *pObj);

public:
	glColorVec color;
  
	GLint radius;
  int collided; // stores the number of updates to occur before homing resumes

private:
  GLint direction;	
 	GLint speed;
	int targetId;
 	glColorVec direColor;
};
#endif
