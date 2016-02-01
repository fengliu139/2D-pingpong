/*
 * @file EnvironmentClassTest.h
 * @brief environment test for sensor,random position, distance
*/
#include <cxxtest/TestSuite.h>

#include "EnvironmentClass.h"
#include "Simulation.h"
/**
 * @brief environment test for sensor,random position, distance
 */
class EnvironmentClassTests : public CxxTest::TestSuite
{
public:
    void Test_Sensor(void)
    {
        EnvironmentClass::init(800, 800);
        
        bool touchResult =
            EnvironmentClass::senseTouch(EnvironmentClass::vecRobot[0]);
        
        TS_ASSERT_EQUALS(false, touchResult);
        
        double homingResult =
            EnvironmentClass::senseHoming(EnvironmentClass::vecRobot[0], EnvironmentClass::vecObstacle[2]);
        
        TS_ASSERT_EQUALS(true, homingResult > 0);
    }

    void Test_generateRandPosition()
    {
        GLPosition result = EnvironmentClass::generateRandPosition(800, 800, 10, 10);
        
        TS_ASSERT_EQUALS(false, GLPosition(0, 0, 0) == result);
    }

    void Test_distance()
    {
        GLPosition pos1(10, 10, 0), pos2(30, 30, 0);
        
        double distance = EnvironmentClass::distance(pos1, pos2);

        TS_ASSERT_EQUALS(round(28.28), round(distance));
    }
};


