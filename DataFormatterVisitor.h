#pragma once
#include "RawEthernetPacket.h"
#include "eCPRIPacket.h"

#include<string>

class DataFormatterVisitor
{
private:
    
public:
    DataFormatterVisitor();
    std::string VisitRawEthernetPacket(RawEthernetPacket* packet);
    std::string VisiteCPRIPacket(eCPRIPacket* packet);
    ~DataFormatterVisitor();
};
