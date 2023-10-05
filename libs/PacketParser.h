#pragma once
#include "EthernetPacket.h"

#include <string>

class PacketParser
{
private:
    EthernetPacket * CurrentDataPacket;
public:
    PacketParser();
    std::string ParsePacket(std::string packet);
    std::string GetFormattedData();
    bool IseCPRIPacket(std::string packet);
    ~PacketParser();
};
