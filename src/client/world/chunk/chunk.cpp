#include "chunk.h"

#include <iostream>

#include <common/coordinate_convertion.h>

namespace client {
    ClientChunk::ClientChunk(const ChunkPosition &chunkPosition)
        : ChunkTEMP(chunkPosition)
    {
    }

    sf::Packet &operator>>(sf::Packet &packet, ClientChunk &chunk)
    {
        for (auto &block : chunk.m_blocks) {
            u8 blockId;
            packet >> blockId;
            block = static_cast<BlockType>(blockId);
        }
        return packet;
    }
} // namespace client
