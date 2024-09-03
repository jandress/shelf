//boost free
#ifndef PROGRAM_HEADER_HPP
#define PROGRAM_HEADER_HPP

//#include <boost/cstdint.hpp>
#include <cstdint>

//#include <boost/static_assert.hpp>
#include <cassert>

namespace elf
{
    struct program_header_32
    {
        // boost::uint32_t m_type;
        // boost::uint32_t m_offset;
        // boost::uint32_t m_vaddr;
        // boost::uint32_t m_paddr;
        // boost::uint32_t m_filesz;
        // boost::uint32_t m_memsz;
        // boost::uint32_t m_flags;
        // boost::uint32_t m_align;
        std::uint32_t m_type;
        std::uint32_t m_offset;
        std::uint32_t m_vaddr;
        std::uint32_t m_paddr;
        std::uint32_t m_filesz;
        std::uint32_t m_memsz;
        std::uint32_t m_flags;
        std::uint32_t m_align;
    };

    //BOOST_STATIC_ASSERT(sizeof(program_header_32) == 32);
    static_assert(32 == sizeof(program_header_32), "Size of program_header_32 must be 32 bytes");


    struct program_header_64
    {
        // boost::uint32_t m_type;
        // boost::uint32_t m_flags;
        // boost::uint64_t m_offset;
        // boost::uint64_t m_vaddr;
        // boost::uint64_t m_paddr;
        // boost::uint64_t m_filesz;
        // boost::uint64_t m_memsz;
        // boost::uint64_t m_align;
        std::uint32_t m_type;
        std::uint32_t m_flags;
        std::uint64_t m_offset;
        std::uint64_t m_vaddr;
        std::uint64_t m_paddr;
        std::uint64_t m_filesz;
        std::uint64_t m_memsz;
        std::uint64_t m_align;
    };

    //BOOST_STATIC_ASSERT(sizeof(program_header_64) == 56);
    static_assert(56 == sizeof(program_header_64), "Size of program_header_64 must be 56 bytes");

    enum programheader_type
    {
        k_pnull = 0,
        k_pload,
        k_pdynamic,
        k_pinterp,
        k_pnote,
        k_pshlib,
        k_pphdr,
        k_ptls,
        k_gnuEh = 0x6474e550,
        k_gnuStack = 0x6474e551,
        k_gnuRelRo = 0x6474e552,
        k_reginfo = 0x70000000,
        k_exidx = 0x70000001
    };

    enum programheader_flags
    {
        k_pfexec = 1,
        k_pfwrite = 2,
        k_pfread = 4
    };
}

#endif
