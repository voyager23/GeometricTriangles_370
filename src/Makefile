# Makefile for Geometric_Triangles_370/src
FLAGS =  -Wfatal-errors -Wall -Wno-unused-variable
FLAGS += -std=c++20
FLAGS += -g

	
csoln : c_soln.cxx toolbox.o Makefile
	g++ c_soln.cxx toolbox.o $(FLAGS) -o ./csoln

pfact : p_fact.cxx toolbox.o Makefile
	g++ p_fact.cxx toolbox.o $(FLAGS) -o ./pfact
	
toolbox.o : toolbox.cxx Makefile
	g++ toolbox.cxx -c -std=c++20 -Wfatal-errors -Wall -Wno-unused-variable -o ./toolbox.o
	
bsoln : b_soln.cxx toolbox.cxx Makefile
	g++ b_soln.cxx toolbox.cxx $(FLAGS) -o ./bsoln

asoln : a_soln.cxx Makefile
	g++ a_soln.cxx $(FLAGS) -o ./asoln
		
analyse: analyse.cxx Makefile
	g++ analyse.cxx $(FLAGS) -std=c++20 -o ./an
