/**
*@file Ball.cpp
*@brief detectWall, detetObstacles, detectTarget ,draw robot with a line
*/
#include "Ball.h"

using namespace std;


/*
 *@brief initialize the position, radius, direction.
 */
Ball::Ball()
{
}

/*
 *@brief current position, radius, direction.
 *@param pos the position
 *@param r the radius
 *@param d the direction
 */
Ball::Ball(GLPosition &pos, GLint r, GLint d)
{
    position = pos;
    
    radius = r;
    direction = d;
}


Ball::~Ball()
{
}

/*
 *@brief set the orientation of robot.
 *@param degree the direction
 */
void Ball::setOrientation(const GLint &degrees)
{
    direction = degrees;// % 360
}

/*
 * @brief get orientation of robot
 */
GLint Ball::getOrientation()
{
    return direction;
}

/*
 *@brief set the speed of robot. The speed cannot be less than 0. Set the speed to null when input less that 0.
 *@param pps speed
 */
void Ball::setSpeed(const GLint &pps)
{
    if (pps < 0)
    {
        std::cerr << "Speed cannot be less than Zero" << endl;
        
        speed = 0;
    }
    else if (pps <= 100) // setting max speed, subject to change -Robin
    {
        speed = pps;
    }
}

/*
 *@brief get speed of robot
 */
GLint Ball::getSpeed()
{
    return speed;
}



/*
 *@brief draw a circle represent the robot and a line represent the direction.
 */
void Ball::draw()
{
    if (flagDraw)
    {
        GLfloat TWOPI = 2.0f * 3.14159f;
        GLint sections = 200;
        
        //glColor3f(0.0f, 80.0f, 100.0f);
        glColor3f(color.posX, color.posY, color.posZ);
        glBegin(GL_LINE_STRIP);
        
        /**
         *@code 
         *draw a circle(robot)
         *and a line for direction
         */
        for (int i = 0; i <= sections; i++)
        {
            glVertex2f(position.posX + radius * cos(i * TWOPI / sections), position.posY + radius * sin(i * TWOPI / sections));
        }
        
        glEnd();
        
//        GLint length = radius + 5;
//        
//        glColor3f(direColor.posX, direColor.posY, direColor.posZ);
//        glBegin(GL_LINE_STRIP);
//        
//        glVertex2d(position.posX, position.posY);
//        glVertex2d(position.posX + length * cos(direction * PI / 180), position.posY + length * sin(direction * PI / 180));
//        
//        glEnd();
        /** @endcode*/
    }
}
/** @code
 * setup the movement for robot
 */
void Ball::move(const time_t elapsedTime)
{
    GLint distance = elapsedTime * speed;
    GLPosition nextPos =
        GLPosition(position.posX + distance * cos(direction * PI / 180), position.posY + distance * sin(direction * PI / 180), 0);
        
    draw();
    updatePosition(nextPos);
}
/** @endcode */
GLint Ball::getRadius() const
{
    return radius;
}


//void Ball::rotate(const GLint &deg)
//{
//    direction += deg;
//    direction = direction; //% 360 // keeps orientation between 0-359 - Robin
//}

void Ball::updatePosition(const GLPosition &newPos)
{
    position = newPos;
}

	void Ball::CheackHitWall(){
  if(position.posX<=radius&&position.posY>radius&&position.posY<800-radius){
    if (direction>90&&direction<=180){
    setOrientation(90-(direction-90));}
    if (direction>180&&direction<270){
    setOrientation(270+(270-direction));    
    }
    }
    if (position.posX>=800-radius&&position.posY>radius&&position.posY<800-radius){
    if (direction>=0&&direction<=90){
    setOrientation(90+(90-direction));}
    if (direction>270&&direction<360){
    setOrientation(270-(direction-270));    
    }
    }
  };
  

//void Ball::setTarget(const int &id)
//{
//    targetId = id;
//}
//
//int Ball::target() const
//{
//    return targetId;
//}

bool Ball::detectCollision(){
return true;
}


void Ball::render(const glColorVec &c)
{
    oldColor = color = c;
}
