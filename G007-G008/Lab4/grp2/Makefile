testMean:  ../team/shared.h ../team/shared.cpp *.h *.cpp
			g++ -c ../team/shared.cpp
			g++ -c Median.cpp
			g++ -c testMedian.cpp
			g++ *.o -o testMedian
			#
			# Send files to team directory
			#
			cp -rf Median.h ../team
			mv -u Median.o ../team

run:        testMedian
			./testMedian

clean:
			rm -f testMedian
			rm -f *.o
