/**
 * @file CommonTest.h
 * @brief test the position, orientation, speed, detectWall, detectObstacles, detectTarget
 */


#include <cxxtest/TestSuite.h>

#include "Common.h"
#include "Obstacle.h"
#include "Simulation.h"

/**
 * @brief test function for GLposition struct, object overlapping and detectWall
 */
class CommonTests : public CxxTest::TestSuite
{
public:
    //test function operator== of struct GLpostion 
    void Test_GLPositionEQ(void)
    {
        GLPosition pos(200, 200);
        TS_ASSERT_EQUALS(pos, GLPosition(200, 200));
    }

public:
    //test function detectOverlapping of class Object
    void Test_Object_detectOverlapping()
    {
        Object *pObj = dynamic_cast<Object*>(new CircularObstacle());

        if (NULL != pObj)
            pObj->position = GLPosition(200, 200, 0);

        GLPosition posLeftTop(150, 200), posRightBottom(300, 180);

        TS_ASSERT_EQUALS(true, pObj->detectOverlapping(posLeftTop, posRightBottom, 64));
    }

    //test function detectWall of class Object
    void test_detectWall(void)
    {
        Object *pObj = dynamic_cast<Object*>(new CircularObstacle());
        
        if (NULL != pObj)
            pObj->position = GLPosition(200, 200);
        
        TS_ASSERT_EQUALS(true, pObj->detectWall(100, 100, 10));
    }
};


