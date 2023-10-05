#include "eCPRIPacket.h"
#include "DataFormatterVisitor.h"

eCPRIPacket::eCPRIPacket()
{
}

std::string eCPRIPacket::Accept(DataFormatterVisitor* visitor)
{
    return visitor->VisiteCPRIPacket(this);
}

eCPRIPacket::~eCPRIPacket()
{
}
