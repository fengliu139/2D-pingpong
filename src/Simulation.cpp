/**
* @file Simulation.cpp
* @brief generate basic simulated control
*/

#include "Simulation.h"
/**
 * @brief initialize the Unmoved as all the objects in the screen has started moving
 */
bool Simulation::Unmoved = false;

/** @brief initialize the Simulation class 
 *  inherited from BaseGfxApp
 */
Simulation::Simulation(int argc, char *argv[], int width, int height) :
BaseGfxApp(argc, argv, width, height, 50, 50, GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH, true, 851, 50)
{
	setCaption("Robot Simulation");

	/**
	 * @brief creates a basic UI panel with quit button
	 * create buttons on the UI panel
	 * reperate the UI control type and the functions 
	 * on each button
	 */
	GLUI_Panel *toolPanel = new GLUI_Panel(m_glui, "Control Panel");

	new GLUI_Button(m_glui, "Quit", UI_QUIT, (GLUI_Update_CB)exit);
	new GLUI_Button(m_glui, "Start", UI_START, (GLUI_Update_CB)Simulation::Start);
	new GLUI_Button(m_glui, "Pause", UI_PAUSE, (GLUI_Update_CB)Simulation::Pause);
	new GLUI_Button(m_glui, "Resume", UI_RESUME, (GLUI_Update_CB)Simulation::Resume);

	/** 
	 * @code Initialize OpenGL
	 */
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0, m_width, 0, m_height);
	glViewport(0, 0, m_width, m_height);
	
	

	EnvironmentClass::init(width, height);
	/**
	 * @endcode
	 */ 
}
void Simulation::keyboard(unsigned char key,int x,int y)
{
	if (key=='a'){
  EnvironmentClass::vecbat[0]->setOrientation(270);
  EnvironmentClass::vecbat[0]->setSpeed(100);
  }
  else if (key=='s'){
  EnvironmentClass::vecbat[0]->setOrientation(90);
  EnvironmentClass::vecbat[0]->setSpeed(100);
  
  }
  else if (key=='k'){
  EnvironmentClass::vecbat[1]->setOrientation(270);
  EnvironmentClass::vecbat[1]->setSpeed(100);
  }
  else if (key=='l'){
  EnvironmentClass::vecbat[1]->setOrientation(90);
  EnvironmentClass::vecbat[1]->setSpeed(100);  
  }
	// nothing here for now
}

void Simulation::keyboardUp(unsigned char c, int x, int y){
	if (c=='a'){
  EnvironmentClass::vecbat[0]->setOrientation(270);
  EnvironmentClass::vecbat[0]->setSpeed(0);
  }
  else if (c=='s'){
  EnvironmentClass::vecbat[0]->setOrientation(90);
  EnvironmentClass::vecbat[0]->setSpeed(0);
  
  }
  else if (c=='k'){
  EnvironmentClass::vecbat[1]->setOrientation(270);
  EnvironmentClass::vecbat[1]->setSpeed(0);
  }
  else if (c=='l'){
  EnvironmentClass::vecbat[1]->setOrientation(90);
  EnvironmentClass::vecbat[1]->setSpeed(0);  
  }

}
void Simulation::gluiControl(int controlID)
{
	
	// nothing here for now
}
/** 
 * @brief display the environment
 * call environment update to simulate anything
 */
void Simulation::display()
{
	if (!Simulation::Unmoved)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		environment.update();

		int err = GL_NO_ERROR;
		if ((err = glGetError()) != GL_NO_ERROR)
		{
			std::cerr << "GL is in an error state, error code: \"" << err << "\"." << std::endl;

			exit(err);
		}
                sleep(0);
                glFlush();
		glutSwapBuffers();
                glutPostRedisplay();
	}
}

/*
 * @brief for the environment and Robot,bat, Target object
 * can have the setup for theris reder ans sence function and so on
 */
Simulation::~Simulation()
{
	for (std::size_t i = 0; i < EnvironmentClass::vecbat.size(); i++)
		delete EnvironmentClass::vecbat[i];

	for (std::size_t i = 0; i < EnvironmentClass::vecRobot.size(); i++)
		delete EnvironmentClass::vecRobot[i];
}

void Simulation::leftMouseDown(int x, int y)
{
	// nothing here for now
}

void Simulation::leftMouseUp(int x, int y)
{
	// nohing here for now
}
/**
 * @brief the button function
 * update unmoved conditions after clicking each button
 */ 
void Simulation::Start()
{
	Unmoved = false;
}

void Simulation::Pause()
{
	Unmoved = true;
}

void Simulation::Resume()
{
	Unmoved = false;
}
