# Getting all the sources
SOURCE := $(wildcard *.cpp)

# Creating the list of objects by replacing the .cpp with .o for the
# sources
OBJECTS := $(SOURCE:.cpp=.o)

#Excluding the main functions  sfrom the general list of sources / objects, so we
# filter them out
MAINS := Wordle_Game_Project_Test.o Wordle_Game_Project.o
OBJECTS := $(filter-out $(MAINS), $(OBJECTS))

# by default, debug mode will be disabled
DEBUG = TRUE

CXXFLAGS := -Wall -Wextra -Wpedantic -Wshadow -g

ifeq (${DEBUG}, TRUE)
   CXXFLAGS += -g
else
   CXXFLAGS += -DNDEBUG -O3
endif

F90FLAGS := -O3 -g

# General ule for compiling a .cpp file to .o
%.o : %.cpp ${HEADERS}
	g++ ${CXXFLAGS} -c $<

# Rules for making the object files
Wordle_Game_Project_Test: Wordle_Game_Project_Test.o ${OBJECTS}
	g++ -o $@ Wordle_Game_Project_Test.o ${OBJECTS}

Wordle_Game_Project: Wordle_Game_Project.o $(OBJECTS)
	g++ -o $@ Wordle_Game_Project.o ${OBJECTS}

# 'make clean' will erase all the intermediate objects
clean:
	rm -f *.o Wordle_Game_Project_Test 
	rm -f *.o Wordle_Game_Project
