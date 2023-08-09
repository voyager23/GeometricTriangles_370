# Makefile for Combinations/src
FLAGS =  -Wfatal-errors -Wall
###FLAGS += -lgmpxx -lgmp
FLAGS += -g

mppx : mapprimepowers.cxx toolbox.o Makefile
	g++ mapprimepowers.cxx toolbox.o $(FLAGS) -std=c++20 -o ./mpx
	
toolbox.o : ../src/toolbox.cxx
	g++ ../src/toolbox.cxx -c -std=c++20 -o toolbox.o
	
ppx : primepowers.cxx Makefile
	g++ primepowers.cxx $(FLAGS) -std=c++20 -o ./ppx
	
perim : perimeter.cxx Makefile
	g++ perimeter.cxx $(FLAGS) -std=c++20 -o ./perim
		
analyse: analyse.cxx Makefile
	g++ analyse.cxx $(FLAGS) -std=c++20 -o ./an
