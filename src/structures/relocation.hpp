//boost free
#ifndef RELOCATION_HPP
#define RELOCATION_HPP
#include <cstdint>
#include <cassert>

namespace elf
{
    struct relocation_32
    {
        std::uint32_t m_offset;
        std::uint32_t m_info;
    };

    static_assert(8 == sizeof(relocation_32), "Size of relocation_32 must be 8 bytes");

    struct relocation_64
    {
        std::uint64_t m_offset;
        std::uint64_t m_info;
    };

    static_assert(16 == sizeof(relocation_64), "Size of relocation_64 must be 16 bytes");

    #pragma pack(push, 1)
    struct rela_32
    {
        std::uint32_t m_offset;
        std::uint32_t m_info;
        std::uint32_t m_addend;
    };

    static_assert(12 == sizeof(rela_32), "Size of rela_32 must be 12 bytes");

    struct rela_64
    {
        std::uint64_t m_offset;
        std::uint64_t m_info;
        std::uint64_t m_addend;
    };
    #pragma pack(pop)
    static_assert(24 == sizeof(rela_64), "Size of rela_64 must be 24 bytes");
}

#endif
