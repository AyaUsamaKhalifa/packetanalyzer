#include "RawEthernetPacket.h"
#include "DataFormatterVisitor.h"

RawEthernetPacket::RawEthernetPacket()
{
}

std::string RawEthernetPacket::Accept(DataFormatterVisitor* visitor)
{
    return visitor->VisitRawEthernetPacket(this);
}

RawEthernetPacket::~RawEthernetPacket()
{
}
