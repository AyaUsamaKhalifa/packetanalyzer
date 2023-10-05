#include "PacketParser.h"
#include <sstream>
#include <iostream>
#define ECPRI_TYPE "AEFE"

PacketParser::PacketParser(std::string line)
{
    ParsePacket(line);
}

std::string PacketParser::ParsePacket(std::string packet)
{
    // Check type of ethernet packet
    if (IseCPRIPacket(packet.substr(((20 * 2)), (2 * 2)))) // Type field is bytes number 21:23 (characters 41:45)
    {
        // Create eCPRI packet
        CurrentDataPacket = new eCPRIPacket();

        // Set data
        CurrentDataPacket->SetDataField(PacketDataFields::CRC, packet.substr((packet.size() - 4 * 2), (4 * 2))); // Last 4 bytes
        CurrentDataPacket->SetDataField(PacketDataFields::DestinationAddress, packet.substr((8 * 2), (6 * 2)));  // Bytes 9:14
        CurrentDataPacket->SetDataField(PacketDataFields::MessageType, packet.substr((23 * 2), (1 * 2)));        // Byte 24
        CurrentDataPacket->SetDataField(PacketDataFields::PayloadSize, packet.substr((24 * 2), (2 * 2)));        // Bytes 25:26
        CurrentDataPacket->SetDataField(PacketDataFields::ProtocolVersion, packet.substr((22 * 2), (1 * 1)));    // Left Nibble of Byte 23
        CurrentDataPacket->SetDataField(PacketDataFields::RTCID, packet.substr((26 * 2), (2 * 2)));              // Bytes 27:28
        CurrentDataPacket->SetDataField(PacketDataFields::SequenceID, packet.substr((28 * 2), (2 * 2)));         // Bytes 29:30
        CurrentDataPacket->SetDataField(PacketDataFields::SourceAddress, packet.substr((14 * 2), (6 * 2)));      // Bytes 15:20
        CurrentDataPacket->SetDataField(PacketDataFields::Type, packet.substr((20 * 2), (2 * 2)));               // Bytes 21:23

        // get last bit in byte 23
        int byte_23 = std::stoi(packet.substr(((22 * 2) - 1), (1 * 1)), nullptr, 16);
        std::stringstream sstring;
        sstring << std::hex << byte_23 % 2;
        std::string last_bit = sstring.str();                                                // int to hex string
        CurrentDataPacket->SetDataField(PacketDataFields::ConcatenationIndicator, last_bit); // Last bit of Byte 23
    }
    else
    {
        // Create Raw packet
        CurrentDataPacket = new RawEthernetPacket();

        // Set Data
        CurrentDataPacket->SetDataField(PacketDataFields::CRC, packet.substr((packet.size() - (4 * 2)), (4 * 2))); // Last 4 bytes
        CurrentDataPacket->SetDataField(PacketDataFields::DestinationAddress, packet.substr((8 * 2), (6 * 2)));    // Bytes 9:14
        CurrentDataPacket->SetDataField(PacketDataFields::SourceAddress, packet.substr((14 * 2), (6 * 2)));        // Bytes 15:20
        CurrentDataPacket->SetDataField(PacketDataFields::Type, packet.substr((20 * 2), (2 * 2)));                 // Bytes 21:23
    }

    DataFormatterVisitor formattedPacketVisitor;

    return GetFormattedData(&formattedPacketVisitor);
}

std::string PacketParser::GetFormattedData(DataFormatterVisitor *visitor)
{
    return CurrentDataPacket->Accept(visitor);
}

bool PacketParser::IseCPRIPacket(std::string packet)
{
    return packet == ECPRI_TYPE;
}

PacketParser::~PacketParser()
{
    delete CurrentDataPacket;
}
