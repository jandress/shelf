//boost free
#ifndef INIT_ARRAY_HPP
#define INIT_ARRAY_HPP

#include <string>
#include <vector>
#include <cstdint>

class InitArray
{
public:
    explicit InitArray(const std::string& p_name);
    ~InitArray();

    void set(const char* p_data, std::uint32_t p_size, std::uint32_t p_offset,
             std::uint32_t p_entries, bool p_is64, bool p_isLE);

    std::uint32_t getOffset() const;

    std::vector<std::pair<std::uint64_t, std::string> >& getEntries();

    std::string printToStd() const;

private:

    std::string m_name;
    std::uint32_t m_offset;
    std::vector<std::pair<std::uint64_t, std::string> > m_entries;
};

#endif
