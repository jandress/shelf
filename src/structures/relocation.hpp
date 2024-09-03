//boost free
#ifndef RELOCATION_HPP
#define RELOCATION_HPP

//#include <boost/cstdint.hpp>
#include <cstdint>

//#include <boost/static_assert.hpp>
#include <cassert>

namespace elf
{
    struct relocation_32
    {
        // boost::uint32_t m_offset;
        // boost::uint32_t m_info;
        std::uint32_t m_offset;
        std::uint32_t m_info;
    };

    //BOOST_STATIC_ASSERT(sizeof(relocation_32) == 8);
    static_assert(8 == sizeof(relocation_32), "Size of relocation_32 must be 8 bytes");

    struct relocation_64
    {
        // boost::uint64_t m_offset;
        // boost::uint64_t m_info;
        std::uint64_t m_offset;
        std::uint64_t m_info;
    };

    //BOOST_STATIC_ASSERT(sizeof(relocation_64) == 16);
    static_assert(16 == sizeof(relocation_64), "Size of relocation_64 must be 16 bytes");

    #pragma pack(push, 1)
    struct rela_32
    {
        // boost::uint32_t m_offset;
        // boost::uint32_t m_info;
        // boost::uint32_t m_addend;
        std::uint32_t m_offset;
        std::uint32_t m_info;
        std::uint32_t m_addend;
    };

    //BOOST_STATIC_ASSERT(sizeof(rela_32) == 12);
    static_assert(12 == sizeof(rela_32), "Size of rela_32 must be 12 bytes");

    struct rela_64
    {
        // boost::uint64_t m_offset;
        // boost::uint64_t m_info;
        // boost::uint64_t m_addend;
        std::uint64_t m_offset;
        std::uint64_t m_info;
        std::uint64_t m_addend;
    };
    #pragma pack(pop)
    //BOOST_STATIC_ASSERT(sizeof(rela_64) == 24);
    static_assert(24 == sizeof(rela_64), "Size of rela_64 must be 24 bytes");
}

#endif
