CC=g++
CFLAGS=-c -Wall
OBJECTS = main.o dll.o UserInfo.o test_dll.o
EXE=a.out


EXE: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXE)

%.o: %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.o *.out