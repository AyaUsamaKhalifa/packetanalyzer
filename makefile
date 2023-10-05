# Compiler
CC = g++

# Compiler Flags
CFLAGS = -c

# Object files
OBJS = PacketParser.o EthernetPacket.o RawEthernetPacket.o eCPRIPacket.o DataFormatterVisitor.o main.o

# executable
EXE = main

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $(EXE)

PacketParser.o: PacketParser.cpp PacketParser.h
	$(CC) $(CFLAGS) PacketParser.cpp

EthernetPacket.o: EthernetPacket.cpp EthernetPacket.h
	$(CC) $(CFLAGS) EthernetPacket.cpp

RawEthernetPacket.o: RawEthernetPacket.cpp RawEthernetPacket.h
	$(CC) $(CFLAGS) RawEthernetPacket.cpp

eCPRIPacket.o: eCPRIPacket.cpp eCPRIPacket.h
	$(CC) $(CFLAGS) eCPRIPacket.cpp

DataFormatterVisitor.o: DataFormatterVisitor.cpp DataFormatterVisitor.h
	$(CC) $(CFLAGS) DataFormatterVisitor.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -f *.o $(EXE)
