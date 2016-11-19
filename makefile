CC=g++

#Compiler Flags
CXXFLAGS=-g -Wall -std=c++0x

# .o Compilation
O_FILES=main.o taxi.o

# Point to includes of local directories
INDLUDES=-I includes


all: $(O_FILES)
	$(CC) $(CXXFLAGS) -o ConnectiCab $(O_FILES) $(LIBS) #$(PATHI) $(PATHL)

main.o: src/main.cpp
	$(CC) $(CXXFLAGS) -c src/main.cpp -o main.o $(INDLUDES)

taxi.o: src/taxi.cpp
	$(CC) $(CXXFLAGS) -c src/taxi.cpp -o taxi.o $(INDLUDES)


clean:
	-@if rm *.o ConnectiCab 2>/dev/null || true; then echo "Main Removed"; else echo "No Main"; fi
