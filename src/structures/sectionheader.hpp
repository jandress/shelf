//boost free
#ifndef SECTION_HEADER_HPP
#define SECTION_HEADER_HPP

#include <cstdint>
#include <cassert>

namespace elf
{
    struct section_header_32
    {
        std::uint32_t m_name;
        std::uint32_t m_type;
        std::uint32_t m_flags;
        std::uint32_t m_addr;
        std::uint32_t m_offset;
        std::uint32_t m_size;
        std::uint32_t m_link;
        std::uint32_t m_info;
        std::uint32_t m_addralign;
        std::uint32_t m_entsize;
    };

    static_assert(40 == sizeof(section_header_32), "Size of section_header_32 must be 40 bytes");
    

    struct section_header_64
    {
        std::uint32_t m_name;
        std::uint32_t m_type;
        std::uint64_t m_flags;
        std::uint64_t m_addr;
        std::uint64_t m_offset;
        std::uint64_t m_size;
        std::uint32_t m_link;
        std::uint32_t m_info;
        std::uint64_t m_addralign;
        std::uint64_t m_entsize;
    };

    static_assert(64 == sizeof(section_header_64), "Size of section_header_64 must be 64 bytes");

    enum section_type
    {
        k_null = 0,
        k_progbits,
        k_symtab,
        k_strtab,
        k_rela,
        k_hash,
        k_dynamic,
        k_note,
        k_nobits,
        k_rel,
        k_shlib,
        k_dynsym,
        k_initArray = 14,
        k_finiArray = 15,
        k_gnuHash = 0x6ffffff6,
        k_gnuVersionR = 0x6ffffffe,
        k_gnuVersion = 0x6fffffff
    };

    enum section_flags
    {
        k_shwrite = 1,
        k_shalloc = 2,
        k_shexec = 4
    };
}

#endif
