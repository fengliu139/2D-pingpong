
//generate baisc simulated control 


#ifndef SIMULATION_H
#define SIMULATION_H

#include "BaseGfxApp.h"
#include "EnvironmentClass.h"
#include "Common.h"

/**
 * @brief The Simulation class.  
 * This sets up the GUI and the drawing environment.
 */
class Simulation : public BaseGfxApp
{

/**
 * @brief enum the control type 
 * to setup button with four functions
 * start,pause,resume and quit
 */
public:
	enum UIControlType
	{
		UI_QUIT = 0,
		UI_START = 1,
		UI_PAUSE = 2,
		UI_RESUME = 3
	};
/**
 * @brief initialize Simulation class
 */
public:
	Simulation(int argc, char *argv[], int width, int height);
	~Simulation();
/**
 * @brief control with ctrlId
 * the control setup
 */
public:
	void gluiControl(int ctrlID);
	void display();
	void leftMouseDown(int x, int y);
	void leftMouseUp(int x, int y);
        void keyboard(unsigned char key, int x, int y);
        void keyboardUp(unsigned char c, int x, int y);
/**
 * @brief button's function
 */
public:
	static void Start();
	static void Pause();
	static void Resume();
/**
 * @brief environment
 */
protected:
	EnvironmentClass environment;
/**
 * @brief variable setting up to judge the condition for the movement
 * so that use it to control the button's function
 */ 
protected:
	static bool Unmoved; //for button
};
#endif




