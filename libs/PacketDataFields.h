#pragma once

enum PacketDataFields
{
    RawData,
    CRC,
    ConcatenationIndicator,
    DestinationAddress,
    SourceAddress,
    MessageType,
    PayloadSize,
    ProtocolVersion,
    RTCID,
    SequenceID,
    Type
};