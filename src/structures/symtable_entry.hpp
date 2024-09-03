//boost free
#ifndef SYMTABLE_ENTRY_HPP
#define SYMTABLE_ENTRY_HPP

#include <string>

//#include <boost/cstdint.hpp>
#include <cstdint>

//#include <boost/static_assert.hpp>
#include <cassert>

namespace elf
{
    namespace symbol
    {
        #pragma pack(push, 1)
        struct symtable_entry32
        {
            // boost::uint32_t m_name;
            // boost::uint32_t m_address;
            // boost::uint32_t m_size;
            // boost::uint8_t m_info;
            // boost::uint8_t m_other;
            // boost::uint16_t m_shndx;
            std::uint32_t m_name;
            std::uint32_t m_address;
            std::uint32_t m_size;
            std::uint8_t m_info;
            std::uint8_t m_other;
            std::uint16_t m_shndx;
        };

        //BOOST_STATIC_ASSERT(sizeof(symtable_entry32) == 16);
        static_assert(16 == sizeof(symtable_entry32), "Size of symtable_entry32 must be 16 bytes");

        struct symtable_entry64
        {
            // boost::uint32_t m_name;
            // boost::uint8_t m_info;
            // boost::uint8_t m_other;
            // boost::uint16_t m_shndx;
            // boost::uint64_t m_address;
            // boost::uint64_t m_size;
            std::uint32_t m_name;
            std::uint8_t m_info;
            std::uint8_t m_other;
            std::uint16_t m_shndx;
            std::uint64_t m_address;
            std::uint64_t m_size;
        };

        //BOOST_STATIC_ASSERT(sizeof(symtable_entry64) == 24);
        static_assert(24 == sizeof(symtable_entry64), "Size of symtable_entry64 must be 24 bytes");
        #pragma pack(pop)

        enum binding
        {
            k_local = 0,
            k_global,
            k_weak
        };

        enum type
        {
            k_notype = 0,
            k_object,
            k_function,
            k_section,
            k_file,
            k_common,
            k_tls
        };
    }
}

#endif
