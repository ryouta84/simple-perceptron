OBJS	= main.o perceptron.o
PROGRAM = main.exe

all:			$(PROGRAM)

$(PROGRAM):		$(OBJS)
				g++  $(OBJS) -o $(PROGRAM)

main.o:			main.cpp
				g++ -std=c++14 -c main.cpp

perceptron.o:	perceptron.cpp
				g++ -std=c++14 -c perceptron.cpp
