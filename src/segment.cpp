//boost free
#include "segment.hpp"
#include "structures/sectionheader.hpp"

#include <iostream>
#include <cstdint>

Segment::Segment(const std::string& p_name, const std::string& p_type,
                 std::uint64_t p_physOffset, std::uint64_t p_virtAddress,
                 std::uint64_t p_size, std::uint32_t p_link,
                 bool p_executable, bool p_writable, bool p_isDynamic) :
    m_name(p_name),
    m_type(p_type),
    m_physOffset(p_physOffset),
    m_virtAddress(p_virtAddress),
    m_size(p_size),
    m_link(p_link),
    m_executable(p_executable),
    m_writable(p_writable),
    m_isDynamic(p_isDynamic)
{
}

Segment::~Segment()
{
}

std::uint64_t Segment::getVirtAddress() const
{
    return m_virtAddress;
}

std::uint64_t Segment::getSize() const
{
    return m_size;
}

std::uint64_t Segment::getPhysOffset() const
{
    return m_physOffset;
}

std::uint32_t Segment::getLink() const
{
    return m_link;
}

const std::string& Segment::getName() const
{
    return m_name;
}

const std::string& Segment::getType() const
{
    return m_type;
}

bool Segment::isDynamic() const
{
    return m_isDynamic;
}
