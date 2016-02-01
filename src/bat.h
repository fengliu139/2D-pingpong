/**@file Obstacle.h
 * @brief draw obstacles avoid overlapping the robot
*/

#ifndef BAT_H
#define BAT_H

#include "Common.h"


/**
 * @brief obstacle with circul
 */
class Bat: public Object
{
public:
	Bat(GLint d);
	Bat(const GLPosition &pos, const GLint w, const GLint h);

	virtual ~Bat();

public:
    /** @brief go on a pleasure trip this obstacle */
    	void setOrientation(const GLint &degrees);
        GLint getOrientation();
  void setSpeed(const GLint &pps);
  GLint getSpeed();
	virtual void move(const time_t elapsedTime);
 
	virtual void render(const glColorVec &c);

  
  virtual bool detectCollision();
    /** @brief update position with @newPos */
	virtual void updatePosition(const GLPosition &newPos);

public:
    /** @brief get the radius */
	//GLint getRadius() const;
  //detectWall
  

protected:
    /** @brief draw a circle obstacle by defined color */
	virtual void draw();

public:	
	GLint width;
  GLint height;       
	GLint speed;
	GLint direction;
  GLPosition position;

	bool motionless;
   int score;//The scores the player has got;
	glColorVec color;
};
#endif
