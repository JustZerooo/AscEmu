/*
Copyright (c) 2014-2023 AscEmu Team <http://www.ascemu.org>
This file is released under the MIT license. See README-MIT for more information.
*/

#pragma once

#include <cstdint>

#include "ManagedPacket.h"
#include "WorldPacket.h"

namespace AscEmu::Packets
{
    class SmsgShowBank : public ManagedPacket
    {
    public:
        uint64_t guid;

        SmsgShowBank() : SmsgShowBank(0)
        {
        }

        SmsgShowBank(uint64_t guid) :
            ManagedPacket(SMSG_SHOW_BANK, 8),
            guid(guid)
        {
        }

    protected:
        bool internalSerialise(WorldPacket& packet) override
        {
            packet << guid;
            return true;
        }

        bool internalDeserialise(WorldPacket& /*packet*/) override
        {
            return false;
        }
    };
}
