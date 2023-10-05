#pragma once
#include "EthernetPacket.h"

class DataFormatterVisitor;

class eCPRIPacket: public EthernetPacket
{
private:
    
public:
    eCPRIPacket();
    virtual std::string Accept(DataFormatterVisitor* visitor) override;
    ~eCPRIPacket();
};
