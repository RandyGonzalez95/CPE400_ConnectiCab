# Linux
CC=g++

#Libraries
LIBS=-lSDL2

# Paths, use this to set Include directories, or library directories; uncomment in all: if used
#PATHI=-I/usr/local/include/
#PATHL=-L/usr/local/lib/

# Compiler Flags
CXXFLAGS=-g -Wall -std=c++0x

# .o Compilation
O_FILES=main.o taxi.o simulation.o graphics.o

# Point to includes of local directories
INDLUDES=-I ../includes


all: $(O_FILES)
	$(CC) $(CXXFLAGS) -o ConnectiCab $(O_FILES) $(LIBS)  #$(PATHI) $(PATHL)

main.o: ../src/main.cpp
	$(CC) $(CXXFLAGS) -c ../src/main.cpp -o main.o $(INDLUDES)

graphics.o: ../src/graphics.cpp
	$(CC) $(CXXFLAGS) -c ../src/graphics.cpp -o graphics.o $(INDLUDES)

simulation.o: ../src/simulation.cpp
	$(CC) $(CXXFLAGS) -c ../src/simulation.cpp -o simulation.o $(INDLUDES)

taxi.o: ../src/taxi.cpp
	$(CC) $(CXXFLAGS) -c ../src/taxi.cpp -o taxi.o $(INDLUDES)


clean:
	rm *.o ConnectiCab 
