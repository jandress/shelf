//boost free
#ifndef ABSTRACT_SYMBOL_HPP
#define ABSTRACT_SYMBOL_HPP

#include <string>

// #include <boost/cstdint.hpp>
#include <cstdint>

namespace elf
{
    namespace symbol
    {
        struct symtable_entry32;
        struct symtable_entry64;
    }
}

class AbstractSymbol
{
public:
    // AbstractSymbol(const char* p_data, boost::uint32_t p_offset,
    AbstractSymbol(const char* p_data, std::uint32_t p_offset,
                   bool p_is64, bool p_isLE);
    AbstractSymbol(const AbstractSymbol& p_rhs);
    ~AbstractSymbol();

    // boost::uint32_t getStructSize() const;
    // boost::uint8_t getType() const;
    // boost::uint8_t getInfo() const;
    // std::string getTypeName() const;
    // std::string getBinding() const;
    // boost::uint64_t getValue() const;
    // boost::uint32_t getNameIndex() const;
    // const std::string& getName() const;
    // boost::uint16_t getSectionIndex() const;

    std::uint32_t getStructSize() const;
    std::uint8_t getType() const;
    std::uint8_t getInfo() const;
    std::string getTypeName() const;
    std::string getBinding() const;
    std::uint64_t getValue() const;
    std::uint32_t getNameIndex() const;
    const std::string& getName() const;
    std::uint16_t getSectionIndex() const;

    void setName(const std::string& p_name);

private:

    // disable evil things
    AbstractSymbol& operator=(const AbstractSymbol& p_rhs);

private:

    const elf::symbol::symtable_entry32* m_symbol32;
    const elf::symbol::symtable_entry64* m_symbol64;
    std::string m_name;
    bool m_is64;
    bool m_isLE;
};

#endif
