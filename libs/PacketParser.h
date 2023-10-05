#pragma once
#include "EthernetPacket.h"

#include <string>

class PacketParser
{
private:
    EthernetPacket * CurrentDataPacket;
public:
    PacketParser();
    void ParsePacket(std::string packet);
    std::string GetFormattedData();
    bool IseCPRIPacket(std::string packet);
    ~PacketParser();
};
