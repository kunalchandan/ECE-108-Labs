testMean:  ../team/shared.h ../team/shared.cpp *.h *.cpp
			g++ -c ../team/shared.cpp
			g++ -c Median.cpp
			g++ -c testMedian.cpp
			g++ -c main.cpp
			g++ *.o -o testMedian
			#
			# Send files to team directory
			#
			cp -u *.h ../team
			mv -u *.o ../team

run:        testMedian
			./testMedian

clean:
			rm -f testMedian
			rm -f *.o
