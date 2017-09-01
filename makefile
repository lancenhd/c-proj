Project2: p2Main.o llist.o 
	g++ p2Main.o llist.o -o Project2

p2Main.o: p2Main.cpp 
	g++ -D DEBUG -c p2Main.cpp

llist.o: llist.cpp
	g++ -D DEBUG -c llist.cpp 

clean:
	rm *.o Project2  
