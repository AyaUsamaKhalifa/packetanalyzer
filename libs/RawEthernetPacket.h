#pragma once
#include "EthernetPacket.h"

class DataFormatterVisitor;

class RawEthernetPacket : public EthernetPacket
{
private:
    
public:
    RawEthernetPacket();
    virtual std::string Accept(DataFormatterVisitor* visitor) override;
    ~RawEthernetPacket();
};