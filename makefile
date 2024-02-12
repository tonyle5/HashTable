all: program

program: main.o Table.o myUtil.o
	g++ -g -Wall -std=c++17 main.o RestaurantQueue.o Group.o PersonalInfo.o Stack.o myUtil.o -o program

main.o: main.cpp
	g++ -g -c -std=c++17 -Wall main.cpp -o main.o

Table.o: Table.cpp
	g++ -g -c -std=c++17 -Wall Table.cpp -o Table.o

myUtil.o: myUtil/myUtil.cpp
	g++ -g -c -std=c++17 -Wall myUtil/myUtil.cpp -o myUtil.o

clean:
	rm -f *.o
	rm -f ./program
