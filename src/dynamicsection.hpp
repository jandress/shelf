//boost free
#ifndef DYNAMICSECTION_HPP
#define DYNAMICSECTION_HPP

#include <map>
#include <set>
#include <string>
#include <vector>
// #include <boost/cstdint.hpp>
#include <cstdint>

#include "abstract_dynamic.hpp"
#include "structures/capabilities.hpp"

namespace elf
{
    namespace dynamic
    {
        struct dynamic_32;
        struct dynamic_64;
    }
}

class AbstractSegments;

class DynamicSection
{
public:
    DynamicSection();
    ~DynamicSection();

    // void createDynamic(const char* p_start, boost::uint32_t p_offset,
    void createDynamic(const char* p_start, std::uint32_t p_offset,
                    //    boost::uint32_t p_size, boost::uint64_t p_baseAddress,
                       std::uint32_t p_size, std::uint64_t p_baseAddress,
                       bool p_is64, bool p_isLE, const AbstractSegments& p_segments);

    // boost::uint64_t getOffset() const;
    // boost::uint64_t getSymbolTableVirtAddress() const;
    // boost::uint64_t getStringTableVirtualAddress() const;
    // boost::uint64_t getStringTableSize() const;
    // boost::uint32_t getSymbolTableSize() const;
    // boost::uint64_t getInitArray() const;
    // boost::uint32_t getInitArrayEntries() const;
    std::uint64_t getOffset() const;
    std::uint64_t getSymbolTableVirtAddress() const;
    std::uint64_t getStringTableVirtualAddress() const;
    std::uint64_t getStringTableSize() const;
    std::uint32_t getSymbolTableSize() const;
    std::uint64_t getInitArray() const;
    std::uint32_t getInitArrayEntries() const;

    /*!
     * Calls into the various segments for evaluation / scoring information.
     * \param[in,out] p_reasons stores the scoring and reasons
     * \param[in,out] p_capabilities stores information about what the binary does
     */
    // void evaluate(std::vector<std::pair<boost::int32_t, std::string> >& p_reasons,
    void evaluate(std::vector<std::pair<std::int32_t, std::string> >& p_reasons,
                  std::map<elf::Capabilties, std::set<std::string> >& p_capabilities) const;

    std::string printToStdOut() const;

private:

    void doDynamic64(const elf::dynamic::dynamic_64* p_dynamic,
                     const char* p_start, const char* p_end,
                    //  boost::uint64_t p_baseAddress, bool p_isLE);
                     std::uint64_t p_baseAddress, bool p_isLE);
    void doDynamic32(const elf::dynamic::dynamic_32* p_dynamic,
                     const char* p_start, const char* p_end,
                    //  boost::uint64_t p_baseAddress, bool p_isLE);
                    std::uint64_t p_baseAddress, bool p_isLE);

private:

    //! Disable evil things
    DynamicSection(const DynamicSection& p_rhs);
    DynamicSection& operator=(const DynamicSection& p_rhs);

private:

    // boost::uint64_t m_offset;
    // boost::uint64_t m_symbolTableVirtAddress;
    // boost::uint64_t m_stringTableVirtAddress;
    // boost::uint64_t m_stringTableSize;
    // boost::uint32_t m_symbolTableSize;
    // boost::uint64_t m_initArrayVirtAddress;
    // boost::uint32_t m_initArrayEntries;
    std::uint64_t m_offset;
    std::uint64_t m_symbolTableVirtAddress;
    std::uint64_t m_stringTableVirtAddress;
    std::uint64_t m_stringTableSize;
    std::uint32_t m_symbolTableSize;
    std::uint64_t m_initArrayVirtAddress;
    std::uint32_t m_initArrayEntries;
    std::vector<AbstractDynamicEntry> m_entries;
};

#endif
