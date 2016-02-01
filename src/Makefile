UNAME = $(shell uname)


CC 		= g++
CFLAGS 	= -Wall -g -pthread
LDFLAGS =

CXXDIR = ../bin/cxxtest
CXXTEST = $(CXXDIR)/bin/cxxtestgen
CXXFLAGS = --error-printer --abort-on-fail --have-eh

##
# List of cpp files to be compiled
# Note, if you add any cpp files to your project, you must also add them here
##
CPPFILES += Common.cpp 
CPPFILES += bat.cpp
CPPFILES += Ball.cpp
CPPFILES += BaseGfxApp.cpp 
CPPFILES += Simulation.cpp
CPPFILES += EnvironmentClass.cpp
CPPFILES += Main.cpp 

TESTCPPFILES += Common.cpp 
TESTCPPFILES += bat.cpp
TESTCPPFILES += Ball.cpp
TESTCPPFILES += BaseGfxApp.cpp 
TESTCPPFILES += Simulation.cpp
TESTCPPFILES += EnvironmentClass.cpp

##
# Lists all the cpp files in /src
# Note, this means you can make from /src, /lib, or /bin
##
SOURCES = $(addprefix ../src/,  $(CPPFILES))
OBJECTS = $(addprefix ../bin/.build/,  $(CPPFILES:.cpp=.o)) 

TESTOBJS = $(addprefix ../bin/.build/,  $(TESTCPPFILES:.cpp=.o)) 

GLUI = glui

LIBGLUT = -lglut
LIBGL = -lGLU -lGL
LIBS = -lpthread -lXmu -lXext -lX11 -lXi -lm

##
# Linking the GLUI libraries
##
LINK_LIBS += -L../lib/$(GLUI)/lib/ -lglui
LINK_LIBS += $(LIBGLUT)
LINK_LIBS += $(LIBGL)
LINK_LIBS += $(LIBS)

INCLUDE = -I../lib/$(GLUI)/include -I../src

###
## Linking GLUT and OpenGl for Mac
###
#ifeq ($(UNAME), Darwin)
	#LINK_LIBS += -framework glut -framework opengl
	#EXECUTABLE = ../bin/gorobot
	#TESTRUNNER = ../bin/testrobot
###
## Linking GLUT and OpenGl for Linux
###
#else
	#ifeq ($(UNAME), Linux)
		#LINK_LIBS += -lglut -lGL -lGLU
		#EXECUTABLE = ../bin/gorobot
		#TESTRUNNER = ../bin/testrobot
###
## Linking GLUT and OpenGl for Windows
## Note, you must have freeGlut installed; see the Resource page for details
###
	#else 
		#GLUTINCLUDEPATH = C:\Dev-Cpp\mingw32\freeglut\include\
		#GLUTLIBPATH = C:\Dev-Cpp\mingw32\freeglut\lib\
		#LINK_LIBS += -L$(GLUTLIBPATH) -lfreeglut -lopengl32 -Wl,--subsystem,windows
		#INCLUDE += -I$(GLUTPATH)
		#EXECUTABLE = gorobot.exe

	#endif
#endif

EXECUTABLE = ../bin/gorobot


##
# Sets up the /bin folder, checks for all cpp files, and compiles the executable
##

all: setup $(SOURCES) $(EXECUTABLE) $(TESTRUNNER) 

setup:
	mkdir -p ../bin
	mkdir -p ../bin/.build

$(EXECUTABLE): $(GLUI) $(OBJECTS) 
	$(CC) $(INCLUDE) $(OBJECTS) $(LINK_LIBS) -o $(EXECUTABLE)


run: $(EXECUTABLE)
	$(EXECUTABLE)

##
# This creates the object files in the /bin folder
##
../bin/.build/%.o: ../src/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) $(LINK_LIBS) -c -o $@ $<

clean:
	 rm -rf test.cpp $(OBJECTS) $(EXECUTABLE) $(TESTRUNNER)
	 $(MAKE)  -C ../lib/$(GLUI) clean

$(GLUI):
	$(MAKE) -C ../lib/$(GLUI) all
