#pragma once
#include "PacketDataFields.h"

#include <string>
#include <unordered_map>

class DataFormatterVisitor;

class EthernetPacket
{
private:
    std::unordered_map<PacketDataFields, std::string> DataFields;
public:
    EthernetPacket();
    std::string GetDataField(PacketDataFields fieldID);
    void SetDataField(PacketDataFields fieldID, std::string fieldValue);
    virtual std::string Accept(DataFormatterVisitor* visitor) = 0;
    virtual ~EthernetPacket();
};
