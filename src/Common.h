/**
*@file Common.h
*@brief obstacles (plane or circular obstacles), GLpostion
*/


#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>
#include <memory>
#include <cassert>
#include <cmath>
#include <utility>

#include <GL/gl.h>
#include <GL/glui.h>

using namespace std;

#define PI 3.14159265

/*
 * @brief get the GLposition from the struct
*/
typedef struct GLPosition
{
public:
	GLPosition()
	{
		posX = 0;
		posY = 0;
		posZ = 0;
	}

	GLPosition(GLint x, GLint y, GLint z = 0)
	{
		posX = x;
		posY = y;
		posZ = z;
	}

public:
	GLPosition &operator = (const GLPosition &orig)
	{
		if (this != &orig)
		{
			posX = orig.posX;
			posY = orig.posY;
			posZ = orig.posZ;
		}

		return *this;
	}

	bool operator != (const GLPosition &orig)
	{
		if (this != &orig)
		{
			if (posX != orig.posX || posY != orig.posY || posZ != orig.posZ)
				return true;
		}

		return false;
	}
	
    bool operator == (const GLPosition &orig)
	{
		if (this != &orig)
		{
			if (posX != orig.posX || posY != orig.posY || posZ != orig.posZ)
				return false;
		}

		return true;
	}

public:
	GLint posX;
	GLint posY;
	GLint posZ;
} glColorVec;


/**
 * @brief base object class obstacle, robot, and any other simulate object.
*/
class Object
{
public:
	Object();
	virtual ~Object();

public:
    /**
     * @brief circular obstacle, plane obstacle, robot
     */ 
	enum Type
	{
		eCircular = 0,      
		ePlane = 1,         
		eRobot = 2,        
		eOther
	};

public:
    /** @brief drive obstacle moving */
	virtual void move(const time_t elapsedTime) = 0;

    /** @brief render this object */
	virtual void render(const glColorVec &c) = 0;

    /** @brief check if collision with any other object */
	virtual bool detectCollision() = 0;

public:
    /**@brief check if over lapped with any other object?*/
	virtual bool detectOverlapping(GLPosition &posLeftTop, GLPosition &posRightBottom, const GLint &radius);

    /** @brief check if collided with wall?*/
	virtual bool detectWall(const GLint &width, const GLint &height, const GLint &radius) const;

protected:
    /** @brief draw this object*/
	virtual void draw() = 0;	

public:
    /**
     * @code
     * current object position,type, id name
     * fraw flag if true, draw the object, otherwise, hide it.
     */
	GLPosition position;       
	Type type;                  

	bool flagDraw;				 
	int id;                    
	std::string name;	        

	glColorVec oldColor;	
	/**
	 * @endcode
	 */ 	
};
#endif




