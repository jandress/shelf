//boost free
#ifndef ABSTRACT_DYNAMIC_HPP
#define ABSTRACT_DYNAMIC_HPP

#include <cstdint>

#include <string>

class AbstractDynamicEntry
{
public:
    AbstractDynamicEntry(std::uint64_t p_tag, std::uint64_t p_value);
    AbstractDynamicEntry(const AbstractDynamicEntry& p_rhs);
    ~AbstractDynamicEntry();

    std::uint64_t getTag() const;
    std::uint64_t getValue() const;

    bool hasString() const;
    void setString(const std::string& p_value);
    const std::string& getString() const;
    void createString(const char* p_strOffset);

    std::string printToStdOut() const;

private:

    //! Disable evil things
    AbstractDynamicEntry& operator=(const AbstractDynamicEntry& p_rhs);

private:
    std::uint64_t m_tag;
    std::uint64_t m_value;
    std::string m_stringValue;
};

#endif
