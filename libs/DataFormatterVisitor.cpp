#include "DataFormatterVisitor.h"

DataFormatterVisitor::DataFormatterVisitor()
{
}

std::string DataFormatterVisitor::VisitRawEthernetPacket(RawEthernetPacket* packet)
{
    return "";
}
    

std::string DataFormatterVisitor::VisiteCPRIPacket(eCPRIPacket* packet)
{
    return "";
}

DataFormatterVisitor::~DataFormatterVisitor()
{
}
