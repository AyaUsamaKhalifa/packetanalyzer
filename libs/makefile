# Compiler
CC = g++

# Compiler Flags
CFLAGS = -c -std=c++20

# Object files
OBJS = PacketParser.o EthernetPacket.o RawEthernetPacket.o eCPRIPacket.o DataFormatterVisitor.o

all: $(OBJS)

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

clean:
	rm -f *.o
