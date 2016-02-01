#ifndef _ENVIRONMENTCLASS_H_
#define _ENVIRONMENTCLASS_H_
/** @file EnvironmentClass.h
  * @brief Class to contain physical objects, sizes/position of all objects and contains info on where the borders are in the window.
  **/

#include "Common.h"
#include "bat.h"
#include "Ball.h"

/**@brief Class to contain physical objects, sizes/position of all objects and contains info on where the borders are in the window. 
     */ 
class EnvironmentClass
{   /**
	 *@brief Friend for class test
	 */ 
    friend class EnvironmentClassTests;

public:
	EnvironmentClass();
	virtual ~EnvironmentClass();
	typedef std::vector< std::pair<std::pair<double, double>, double> > OffsetTriangle;
    /**@brief init the scene, create both robots and obstacles, place them randomly, 
     */ 
	static void init(const GLint &width, const GLint &height);
    /** update simulating scene, such as robot's angle, object's posiion, etc*/
	void update();
    /** the senser for *Touch* */
	static bool senseTouch(Object *pObject);
  void CheckSuccessCatch(GLPosition &bat1, GLPosition &bat2)  ;
  void CheckUnsuccessCatch(GLPosition &bat1, GLPosition &bat2);

protected:

    
    /** calculate the distance between @pos1 and @pos2 */
	static double distance(const GLPosition &pos1, const GLPosition &pos2);
    
public:
    /** set up the bat and Robot and also the Target */
 
	static std::vector<Bat *> vecbat;
	static std::vector<Ball *> vecRobot;

	static int winWidth;
	static int winHeight;

    static glColorVec collidedColor;
private:
	time_t t_lastUpdate, t_lastRotate;
};
#endif

