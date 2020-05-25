all: main

main: main.o point.o quadrate.o rectangle.o trigon.o factory.o
	g++ -pthread main.o point.o quadrate.o rectangle.o trigon.o factory.o -o oop_exercise_08

main.o: main.cpp
	g++ -c main.cpp 

point.o: point.cpp
	g++ -c point.cpp 

quadrate.o: quadrate.cpp
	g++ -c quadrate.cpp 

rectangle.o: rectangle.cpp
	g++ -c rectangle.cpp 

trigon.o: trigon.cpp
	g++ -c trigon.cpp 

factory.o: factory.cpp
	g++ -c factory.cpp

clean:
	rm -rf *.o
