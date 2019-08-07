team:	*.h *.cpp
		g++ -c calculate.cpp
		g++ -c shared.cpp
		g++ Mean.o Median.o calculate.o shared.o testMedian.o testMean.o -o team
run:	team
		./team
clean:
		rm -rf *.o
