#include "EnvironmentClass.h"


std::vector<Bat *> EnvironmentClass::vecbat;
std::vector<Ball *> EnvironmentClass::vecRobot;

int EnvironmentClass::winWidth = 0;
int EnvironmentClass::winHeight = 0;

glColorVec EnvironmentClass::collidedColor = glColorVec(101, 106, 100);


EnvironmentClass::EnvironmentClass() : t_lastUpdate(0)
{

}

EnvironmentClass::~EnvironmentClass()
{
    for (std::size_t i = 0; i < vecRobot.size(); i++)
        delete vecRobot[i];
        
    for (std::size_t i = 0; i < vecbat.size(); i++)
        delete vecbat[i];
}


void EnvironmentClass::init(const GLint &width, const GLint &height)
{

    for (int i = 0; i < 1; i++)
    {

        GLPosition robotPos;
        robotPos.posX=400;
        robotPos.posY=400;
        GLint robotRadius=10;
        Ball *pRobot = new(std::nothrow) Ball(robotPos, robotRadius, 0);
        
        if (NULL == pRobot)
            continue;

        //pRobot->type = Object::eRobot;
        pRobot->setSpeed(100);
        pRobot->setOrientation(90);
        //pRobot->direction=120;
        
           
//        pRobot->setTarget(i * 2 + 1010);
        pRobot->render(glColorVec(0.0f, 80.0f, 100.0f));
//         
//        if (i % 2)
//            pRobot->setDirectionColor(glColorVec(100, 0, 0));
//        else
//            pRobot->setDirectionColor(glColorVec(200, 0, 100));
             
        vecRobot.push_back(pRobot);
        //printf("direction is %d\n",pRobot->direction);
        //printf("direction is %d\n",vecRobot[i]->getOrientation());
    }
    /**
     *@endcode
     */
    
    /**
     *@todo must create 2 robots
     */ 
    assert(1 == vecRobot.size());
   
    /** 
     * @code  
     * initialize obstacle objects,
     * rand generater radius for obstacle, it between [16, 48) pixels
     * generate a rand posion for the obstacle and new circular obstacle instance
     * set obstacle id,type, default color, 
     * if this obstacle is appointed to a robot, use the robot's direction line color to draw it
     * add to the obstacle vector
     */ 
    for (int i = 0; i < 2; i++)
    {

        GLPosition obsPos;
        obsPos.posX=300;
        obsPos.posY=790-i*790;
        
        Bat *pCircObs = new(std::nothrow) Bat(obsPos, 200, 10);
        
        if (NULL == pCircObs)
            continue;
            pCircObs->direction=90;
        pCircObs->motionless = false;
        pCircObs->id = 1010 + i;
       
        pCircObs->type = Object::eCircular;
        
        pCircObs->render(glColorVec(0, 100, 0));
        
        vecbat.push_back(pCircObs);
    }
    /**
     *@endcode
     */
    
    /**
     *@todo must create 6 circular obstacle
     */ 
    assert(2 == vecbat.size());
    
    /**
     *@todo remember the gui windows's size
     */ 
    winWidth = width;
    winHeight = height;
}



/**
 * @brief calculate the distance between @pos1 and @pos2
 * @pos1    - the start posion
 * @pos2    - the end posion
 * @return  - the distance between @pos1 and @pos2
 */
double EnvironmentClass::distance(const GLPosition &pos1, const GLPosition &pos2)
{
    double distance = -1.0;
    
    /**
     * @code
     * if the @pos1 and @pos2 form a right angled triangle, use the pythagorean theorem to calculate
     * the distance. otherwise, calculate it directly.
     */
    if (pos1.posX != pos2.posX && pos1.posY != pos2.posY)
    {
        GLint a = abs(pos1.posX - pos2.posX);
        GLint b = abs(pos1.posY - pos2.posY);
        
        distance = sqrt(pow(a, 2) + pow(b, 2));
    }
    else
    {
        if (pos1.posX == pos2.posX)
        {
            distance = abs(pos1.posY - pos2.posY);
        }
        
        if (pos1.posY == pos2.posY)
        {
            distance = abs(pos1.posX - pos2.posX);
        }
    }
    /**
     *@endcode
     */
     
    return distance;
}

  	void EnvironmentClass::CheckSuccessCatch(GLPosition &bat1, GLPosition &bat2){
     if (vecRobot[0]->position.posX>=bat1.posX&&vecRobot[0]->position.posX<=bat1.posX+200&& vecRobot[0]->position.posY>=790-vecRobot[0]->radius){
       if (vecRobot[0]->getOrientation()>0&&vecRobot[0]->getOrientation()<=90){
          if (vecbat[0]->getSpeed()==0){vecRobot[0]->setOrientation(360-vecRobot[0]->getOrientation());}
          else {
            if(vecbat[0]->getOrientation()==90) {
            vecRobot[0]->setOrientation(360-vecRobot[0]->getOrientation()+0.5*vecRobot[0]->getOrientation());
            }
            else {
            vecRobot[0]->setOrientation(360-vecRobot[0]->getOrientation()-0.5*(180-vecRobot[0]->getOrientation()));
            }
        
          }
        }
       if (vecRobot[0]->getOrientation()>90&&vecRobot[0]->getOrientation()<180){
          if (vecbat[0]->getSpeed()==0){vecRobot[0]->setOrientation(360-vecRobot[0]->getOrientation());}
          else {
            if(vecbat[0]->getOrientation()==90) {
            vecRobot[0]->setOrientation(360-vecRobot[0]->getOrientation()+0.5*vecRobot[0]->getOrientation());
            }
            else {
            vecRobot[0]->setOrientation(360-vecRobot[0]->getOrientation()-0.5*(180-vecRobot[0]->getOrientation()));
            }
        
          }         
       }
         
       
     
     }
   else if (vecRobot[0]->position.posX>=bat2.posX&&vecRobot[0]->position.posX<=bat2.posX+200&& vecRobot[0]->position.posY<=10+vecRobot[0]->radius){
       if (vecRobot[0]->getOrientation()>180&&vecRobot[0]->getOrientation()<=270){
          if (vecbat[1]->getSpeed()==0){vecRobot[0]->setOrientation(360-vecRobot[0]->getOrientation());}
          else {
            if(vecbat[1]->getOrientation()==90) {
            vecRobot[0]->setOrientation(360-vecRobot[0]->getOrientation()-0.5*(360-vecRobot[0]->getOrientation()));
            }
            else {
            vecRobot[0]->setOrientation(360-vecRobot[0]->getOrientation()+0.5*(vecRobot[0]->getOrientation()-180));
            }
        
          }
        }
       if (vecRobot[0]->getOrientation()>270&&vecRobot[0]->getOrientation()<360){
          if (vecbat[1]->getSpeed()==0){vecRobot[0]->setOrientation(360-vecRobot[0]->getOrientation());}
          else {
            if(vecbat[1]->getOrientation()==90) {
            vecRobot[0]->setOrientation(360-vecRobot[0]->getOrientation()-0.5*(360-vecRobot[0]->getOrientation()));
            }
            else {
            vecRobot[0]->setOrientation(360-vecRobot[0]->getOrientation()+0.5*(vecRobot[0]->getOrientation()-180));
            }
        
          }         
       }
         
       
     
     }
  };

void EnvironmentClass::CheckUnsuccessCatch(GLPosition &bat1, GLPosition &bat2){
  if ((vecRobot[0]->position.posX<bat1.posX|| vecRobot[0]->position.posX>bat1.posX+200)&&vecRobot[0]->position.posY > 790){
      vecbat[1]->score++;
      GLPosition newPos;
      newPos.posX=400;
      newPos.posY=400;
      vecRobot[0]-> updatePosition(newPos);
      vecRobot[0]-> setOrientation(rand()%360);
      vecbat[0]->position.posX=300;
      vecbat[1]->position.posX=300;
      printf("Player2 got 1 point!\n");
  }
  else if((vecRobot[0]->position.posX<bat1.posX|| vecRobot[0]->position.posX>bat1.posX+200)&&vecRobot[0]->position.posY < 10){
      vecbat[0]->score++;
      GLPosition newPos;
      newPos.posX=400;
      newPos.posY=400;
      vecRobot[0]-> updatePosition(newPos);
      vecRobot[0]-> setOrientation(rand()%360);
      vecbat[0]->position.posX=300;
      vecbat[1]->position.posX=300;
      printf("Player1 got 1 point!\n");
  
  }
};

void EnvironmentClass::update()
{
    /**
     * @todo calculate elapsed time
     */ 
    time_t t_now = time(NULL);

    if (0 == t_lastUpdate)
        t_lastUpdate = t_now;

    time_t elapsedTime = t_now - t_lastUpdate;
    
    
    
    GLPosition bat1=vecbat[0]->position;
    GLPosition bat2=vecbat[1]->position;

    for (std::size_t i = 0; i < 1 ; i++)
    {
        vecRobot[i]->move(elapsedTime);
        vecRobot[i]->CheackHitWall();
        
        time_t t_RotatePeriod = t_now - t_lastRotate;

    }
    for (std::size_t j = 0; j < vecbat.size(); j++)
    {

        
        vecbat[j]->move(elapsedTime);
    }

    t_lastUpdate = t_now;
    CheckSuccessCatch(vecbat[0]->position, vecbat[1]->position);
    CheckUnsuccessCatch(vecbat[0]->position, vecbat[1]->position);
}

