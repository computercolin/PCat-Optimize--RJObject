CFLAGS = -O3 -fPIC -Wall -Wextra -ansi -pedantic -DNDEBUG
LIBS = -ldnest3 -lgsl -lgslcblas -lboost_thread -lboost_system

default:
	g++ $(CFLAGS) -c *.cpp Distributions/*.cpp
	g++ -o main *.o $(LIBS)
	g++ -shared -o librjobject.so BasicCircular.o  ClassicMassInf.o  Distribution.o Pareto.o
	rm -f *.o

clean:
	rm -f *.o
	rm -f main
