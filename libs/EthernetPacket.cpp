#include "EthernetPacket.h"
#include <iostream>

EthernetPacket::EthernetPacket()
{
}

std::string EthernetPacket::GetDataField(PacketDataFields fieldID)
{
    if (DataFields.find(fieldID) != DataFields.end())
    {
        return DataFields[fieldID];
    }
    return "";
}

void EthernetPacket::SetDataField(PacketDataFields fieldID, std::string fieldValue)
{
    // std::cout << "set " << fieldID << " " << fieldValue << "\n";
    DataFields[fieldID] = fieldValue;
}

EthernetPacket::~EthernetPacket()
{
}
