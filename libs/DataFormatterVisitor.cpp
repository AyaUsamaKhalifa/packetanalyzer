#include "DataFormatterVisitor.h"

DataFormatterVisitor::DataFormatterVisitor()
{
}

std::string DataFormatterVisitor::VisitRawEthernetPacket(RawEthernetPacket* packet)
{
    std::string formattedData = "";
    formattedData += "CRC: " + packet->GetDataField(PacketDataFields::CRC) + "\n";
    formattedData += "Destination Address: " + packet->GetDataField(PacketDataFields::DestinationAddress) + "\n";
    formattedData += "Source Address: " + packet->GetDataField(PacketDataFields::SourceAddress) + "\n";
    formattedData += "Type: " + packet->GetDataField(PacketDataFields::Type) + "\n";
    return formattedData;
}
    

std::string DataFormatterVisitor::VisiteCPRIPacket(eCPRIPacket* packet)
{
    std::string formattedData = "";
    formattedData += "CRC: " + packet->GetDataField(PacketDataFields::CRC) + "\n";
    formattedData += "Concatenation Indicator: " + packet->GetDataField(PacketDataFields::ConcatenationIndicator) + "\n";
    formattedData += "Destination Address: " + packet->GetDataField(PacketDataFields::DestinationAddress) + "\n";
    formattedData += "Message Type: " + packet->GetDataField(PacketDataFields::MessageType) + "\n";
    formattedData += "Payload Size: " + packet->GetDataField(PacketDataFields::PayloadSize) + "\n";
    formattedData += "Protocol Version: " + packet->GetDataField(PacketDataFields::ProtocolVersion) + "\n";
    formattedData += "RTC ID: " + packet->GetDataField(PacketDataFields::RTCID) + "\n";
    formattedData += "Sequence ID: " + packet->GetDataField(PacketDataFields::SequenceID) + "\n";
    formattedData += "Source Address: " + packet->GetDataField(PacketDataFields::SourceAddress) + "\n";
    formattedData += "Type: " + packet->GetDataField(PacketDataFields::Type) + "\n";
    return formattedData;
}

DataFormatterVisitor::~DataFormatterVisitor()
{
}
