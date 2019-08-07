testMean:  ../team/shared.h ../team/shared.cpp *.h *.cpp
			g++ -c ../team/shared.cpp
			g++ -c Mean.cpp
			g++ -c testMean.cpp
			g++ -c main.cpp
			g++ *.o -o testMean
			#
			# Send files to team directory
			#
			cp -u *.h ../team
			mv -u *.o ../team

run:        testMean
			./testMean

clean:
			rm -f testMean
			rm -f *.o
