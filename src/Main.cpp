


#include "Simulation.h"

int main(int argc, char* argv[])
{
	Simulation *pAppInst = new Simulation(argc, argv, 800, 800);
	pAppInst->runMainLoop();

	return EXIT_SUCCESS;
}

