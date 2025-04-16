//boost free
#ifndef ELF_HEADER_HPP
#define ELF_HEADER_HPP
#include <string>
#include <cstdint>
#include <cassert>

namespace elf
{
    enum elf_class
    {
        k_32 = 1,
        k_64 = 2
    };

    enum elf_encoding
    {
        k_littleEndian = 1,
        k_bigEndian = 2
    };

    enum elf_type
    {
        k_etnone = 0,
        k_etrel,
        k_etexec,
        k_etdyn,
        k_etcore
    };

    enum elf_machine
    {
        k_emnone = 0,
        k_em386 = 3,
        k_emMIPS = 8,
        k_emPPC = 20,
        k_emARM = 40,
        k_emx8664 = 62
    };

    #pragma pack(push, 1)
    struct elf_header_32
    {
        union
        {
            std::uint8_t m_ident[16];
            struct
            {
                std::uint8_t m_magic0;
                std::uint8_t m_magic1;
                std::uint8_t m_magic2;
                std::uint8_t m_magic3;
                std::uint8_t m_class;
                std::uint8_t m_encoding;
                std::uint8_t m_fileversion;
                std::uint8_t m_os;
                std::uint8_t m_abi;
            };
        };
        std::uint16_t m_type;
        std::uint16_t m_machine;
        std::uint32_t m_version;
        std::uint32_t m_entry;
        std::uint32_t m_phoff;
        std::uint32_t m_shoff;
        std::uint32_t m_flags;
        std::uint16_t m_ehsize;
        std::uint16_t m_phentsize;
        std::uint16_t m_phnum;
        std::uint16_t m_shentsize;
        std::uint16_t m_shnum;
        std::uint16_t m_shtrndx;
    };

    static_assert(52 == sizeof(elf_header_32), "Size of elf_header_32 must be 52 bytes");

    struct elf_header_64
    {
        union
        {
            std::uint8_t m_ident[16];
            struct
            {
                std::uint8_t m_magic0;
                std::uint8_t m_magic1;
                std::uint8_t m_magic2;
                std::uint8_t m_magic3;
                std::uint8_t m_class;
                std::uint8_t m_encoding;
                std::uint8_t m_fileversion;
                std::uint8_t m_os;
                std::uint8_t m_abi;
            };
        };
        std::uint16_t m_type;
        std::uint16_t m_machine;
        std::uint32_t m_version;
        std::uint64_t m_entry;
        std::uint64_t m_phoff;
        std::uint64_t m_shoff;
        std::uint32_t m_flags;
        std::uint16_t m_ehsize;
        std::uint16_t m_phentsize;
        std::uint16_t m_phnum;
        std::uint16_t m_shentsize;
        std::uint16_t m_shnum;
        std::uint16_t m_shtrndx;
    };

    static_assert(64 == sizeof(elf_header_64), "Size of elf_header_64 must be 64 bytes");
    #pragma pack(pop)
}

#endif