# Compiler
CC = g++

# executable
EXE = main

# Object files
OBJS = ./libs/PacketParser.o ./libs/EthernetPacket.o ./libs/RawEthernetPacket.o ./libs/eCPRIPacket.o ./libs/DataFormatterVisitor.o main.o

# Compiler Flags
CFLAGS = -c -std=c++20

# Include files
INCLUDES = -I./libs

all: $(EXE)
	
$(EXE): makelibs main.o
	$(CC) $(OBJS) -o $(EXE)

makelibs:
	$(MAKE) -C libs

main.o: main.cpp
	$(CC) $(INCLUDES) $(CFLAGS) main.cpp

clean:
	$(MAKE) -C libs clean
	rm -f *.o $(EXE)