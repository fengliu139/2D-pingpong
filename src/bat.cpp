#include "bat.h"


Bat::Bat(GLint d) : motionless(true)
{
//    //rand generate direction
//    srand(time(NULL));
//    direction = rand() % 360;
      direction=d;
}


Bat::Bat(const GLPosition &pos, const GLint w, const GLint h): motionless(true)
{

    srand(time(NULL));
   // direction = rand() % 360;
   direction = 180;
    
    speed = 0;
    score=0;

    position = pos;
    width=w;
    height=h;

}

Bat::~Bat()
{
}


 void Bat::draw()
 {
     if (flagDraw)
     {
 //        GLfloat TWOPI = 2.0f * 3.14159f;
 //        GLint sections = 200;
 //        
 //        glColor3f(color.posX, color.posY, color.posZ);
 //        
 //        glBegin(GL_TRIANGLE_FAN);
 //        glVertex2f(position.posX, position.posY);
 //        
 //        /** @code circle represent obstacles. */
 //        for (int i = 0; i <= sections; i++)
 //        {
 //            glVertex2f(position.posX + radius * cos(i * TWOPI / sections), position.posY + radius * sin(i * TWOPI / sections));
 //        }
 //        
 //        glEnd();
         /** @endcode */
         unsigned int rgba = 0xff0000ff;
glBegin(GL_QUADS);
glColor4f(((rgba>>24)&0xff)/255.0f,
((rgba>>16)&0xff)/255.0f, 
((rgba>>8)&0xff)/255.0f,
(rgba&0xff)/255.0f);
glVertex3f(position.posX,position.posY,0);
glVertex3f(position.posX+width,position.posY,0);
glVertex3f(position.posX+width,position.posY+height,0);
glVertex3f(position.posX,position.posY+height,0);
glEnd();
glColor4f(1, 1, 1, 1);;
        
    }
}

void Bat::setSpeed(const GLint &pps)
{
    if (pps < 0)
    {
        std::cerr << "Speed cannot be less than Zero" << endl;
        
        speed = 0;
    }
    else 
    {
        speed = pps;
    }
}

GLint Bat::getSpeed()
{
    return speed;
}

void Bat::setOrientation(const GLint &degrees)
{
    direction = degrees;// % 360
}


GLint Bat::getOrientation()
{
    return direction;
}

void Bat::move(const time_t elapsedTime)
{
    if (!motionless)
    {
        GLint distance = elapsedTime * speed;
        GLPosition nextPos =
            GLPosition(position.posX + distance * sin(direction * PI / 180), position.posY, 0);
            
        updatePosition(nextPos);
    }
    
    draw();
    
}

bool Bat::detectCollision()
{
    return false;
}


void Bat::updatePosition(const GLPosition &newPos)
{
    position = newPos;
}


void Bat::render(const glColorVec &c)
{
    oldColor = color = c;
}
