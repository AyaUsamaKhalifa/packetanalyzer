#pragma once
#include "EthernetPacket.h"
#include "eCPRIPacket.h"
#include "RawEthernetPacket.h"
#include "DataFormatterVisitor.h"

#include <string>

class PacketParser
{
private:
    EthernetPacket *CurrentDataPacket;
    std::string GetFormattedData(DataFormatterVisitor* visitor);
    bool IseCPRIPacket(std::string packet);

public:
    PacketParser() = default;
    PacketParser(std::string);

    std::string ParsePacket(std::string packet);

    ~PacketParser();
};
