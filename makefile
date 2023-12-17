
all: driver mydriver 

driver: driver.o 
	g++ -o driver -std=c++11 driver.o 
driver.o: driver.cpp
	g++ -c -std=c++11 driver.cpp
mydriver: mydriver.o 
	g++ -o mydriver -std=c++11 mydriver.o 
mydriver.o: mydriver.cpp 
	g++ -c -std=c++11 mydriver.cpp


clean:
	-rm *.o
	-rm *.h.gch