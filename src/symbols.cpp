//boost free
#include "symbols.hpp"

#include "abstract_symbol.hpp"
#include "abstract_segments.hpp"
#include "structures/symtable_entry.hpp"

#include <iostream>
#include <sstream>
#ifndef WINDOWS
#include <cxxabi.h>
#endif
#include <map>
#include <algorithm>
#include <cstdint>

namespace
{
    //! files that mark a specific functionality
    std::map<std::string, std::pair<elf::Capabilties, std::string>> files = {
        {"adler32.c", {elf::k_compression, "Compiled with adler32.c"}},
        {"gzip.c", {elf::k_compression, "Compiled with gzip.c"}}
    };

    //! functions that we think should be noted as dangerous
    std::map<std::string, std::pair<elf::Capabilties, std::string>> capabilities = {
        {"fclose", {elf::k_fileFunctions, "fclose() found"}},
        {"feof", {elf::k_fileFunctions, "feof() found"}},
        {"fopen", {elf::k_fileFunctions, "fopen() found"}},
        {"funlockfile", {elf::k_fileFunctions, "funlockfile() found"}},
        {"unlink", {elf::k_fileFunctions, "unlink() found"}},
        {"accept", {elf::k_networkFunctions, "accept() found"}},
        {"bind", {elf::k_networkFunctions, "bind() found"}},
        {"connect", {elf::k_networkFunctions, "connect() found"}},
        {"listen", {elf::k_networkFunctions, "listen() found"}},
        {"socket", {elf::k_networkFunctions, "socket() found"}},
        {"sendto", {elf::k_networkFunctions, "sendto() found"}},
        {"recv", {elf::k_networkFunctions, "recv() found"}},
        {"gethostbyname", {elf::k_networkFunctions, "gethostbyname() found"}},
        {"gethostbyname_r", {elf::k_networkFunctions, "gethostbyname_r() found"}},
        {"inet_addr", {elf::k_networkFunctions, "inet_addr() found"}},
        {"fork", {elf::k_processManipulation, "fork() found"}},
        {"kill", {elf::k_processManipulation, "kill() found"}},
        {"clone", {elf::k_processManipulation, "clone() found"}},
        {"execve", {elf::k_processManipulation, "execve() found"}},
        {"execl", {elf::k_processManipulation, "execl() found"}},
        {"execle", {elf::k_processManipulation, "execle() found"}},
        {"execve", {elf::k_processManipulation, "execve() found"}},
        {"raise", {elf::k_processManipulation, "raise() found"}},
        {"daemon", {elf::k_processManipulation, "daemon() found"}},
        {"pclose", {elf::k_pipeFunctions, "pclose() found"}},
        {"popen", {elf::k_pipeFunctions, "popen() found"}},
        {"rand", {elf::k_crypto, "rand() found"}},
        {"srand", {elf::k_crypto, "srand() found"}},
        {"srandom_r", {elf::k_crypto, "srandom_r() found"}},
        {"random_r", {elf::k_crypto, "random_r() found"}},
        {"phys_pages_info", {elf::k_infoGathering, "phys_pages_info() found"}},
        {"getpagesize", {elf::k_infoGathering, "getpagesize() found"}},
        {"fstat", {elf::k_infoGathering, "fstat() found"}},
        {"uname", {elf::k_infoGathering, "uname() found"}},
        {"access", {elf::k_infoGathering, "access() found"}},
        {"sysinfo", {elf::k_infoGathering, "sysinfo() found"}},
        {"setenv", {elf::k_envVariables, "setenv() found"}},
        {"clearenv", {elf::k_envVariables, "clearenv() found"}},
        {"unsetenv", {elf::k_envVariables, "unsetenv() found"}},
        {"getenv", {elf::k_envVariables, "getenv() found"}},
        {"secure_getenv", {elf::k_envVariables, "secure_getenv() found"}},
        {"chown", {elf::k_permissions, "chown() found"}},
        {"chmod", {elf::k_permissions, "chmod() found"}},
        {"openlog", {elf::k_syslog, "openlog() found"}},
        {"closelog", {elf::k_syslog, "closelog() found"}},
        {"vsyslog", {elf::k_syslog, "vsyslog() found"}},
        {"pcap_open_live", {elf::k_packetSniff, "pcap_open_live() found"}},
        {"pcap_close", {elf::k_packetSniff, "pcap_close() found"}},
        {"pcap_read", {elf::k_packetSniff, "pcap_read() found"}},
        {"pcap_loop", {elf::k_packetSniff, "pcap_loop() found"}},
        {"system", {elf::k_shell, "system() found"}},
        {"tshd_runshell", {elf::k_shell, "tinysh function found."}},
        {"dlsym", {elf::k_hooking, "dlsym() found in hooking context"}},
        {"ptrace", {elf::k_antidebug, "ptrace detection found"}}
    };

}



Symbols::Symbols() :
    m_isDY(false),
    m_symbols(),
    m_files()
{
}

Symbols::~Symbols()
{
}

const std::vector<AbstractSymbol>& Symbols::getSymbols() const
{
    return m_symbols;
}

std::set<std::string> Symbols::getFiles() const
{
    return m_files;
}


void Symbols::createSymbols(const char* p_data,
                            std::uint64_t p_dataSize,
                            std::uint64_t p_symTabOffset,
                            std::uint32_t p_symTabSize,
                            std::uint64_t p_strTabOffset,
                            std::uint64_t p_strTableSize,
                            const AbstractSegments& p_segments,
                            bool p_is64, bool p_isLE, bool p_isDY)
{
    (void)p_segments; //appears to be unused
    m_isDY = p_isDY;
    if (p_symTabOffset == 0 || p_strTabOffset == 0 || p_symTabSize == 0)
    {
        return;
    }


    std::uint8_t multiplier = p_is64 ? sizeof(elf::symbol::symtable_entry64) : sizeof(elf::symbol::symtable_entry32);
    for (std::uint32_t i = 0; p_symTabOffset + i < p_dataSize; i += multiplier)
    {
        // create a temp symbol to work with
        AbstractSymbol symbol(p_data, p_symTabOffset + i, p_is64, p_isLE);

        // we get the symbol table size from the hash in dynamic since we
        // can't rely on the section table. However, the size from the hash
        // can be less than what we expect. So just keep parsing the symbol
        // table until the values become nonsense.
        if (i >= p_symTabSize)
        {
            if (symbol.getNameIndex() >= p_strTableSize ||
                symbol.getType() > 6)
            {
                break;
            }
        }

        if (symbol.getNameIndex() < p_strTableSize)
        {
            // find a null terminator
            bool nullFound = false;
            for (std::size_t j = symbol.getNameIndex(); p_strTabOffset + j < p_dataSize; ++j)
            {
                if (p_data[p_strTabOffset + j] == 0)
                {
                    nullFound = true;
                    break;
                }
            }
            if (nullFound)
            {
                if (symbol.getType() == elf::symbol::k_function)
                {
#ifndef WINDOWS
                    char* unmangled = NULL;
                    std::size_t length = 0;
                    int status = 0;
                    unmangled  = abi::__cxa_demangle(p_data + p_strTabOffset + symbol.getNameIndex(), unmangled, &length, &status);
                    if (unmangled != NULL)
                    {
                        if (status == 0)
                        {
                            std::string fixed(unmangled);
                            symbol.setName(fixed);
                        }
                        else
                        {
                            symbol.setName("FailedDemangling");
                        }
                        free(unmangled);
                    }
                    else
#endif
                    {
                        symbol.setName(p_data + p_strTabOffset + symbol.getNameIndex());
                    }
                }
                else
                {
                    symbol.setName(p_data + p_strTabOffset + symbol.getNameIndex());
                }
            }
            else
            {
                symbol.setName("NoNullTerminator");
            }

            if ((symbol.getType() & 0x0f) == 4 && !symbol.getName().empty())
            {
                m_files.insert(symbol.getName());
            }
        }
        m_symbols.push_back(symbol);
    }
}


std::string Symbols::findSymbol(std::uint64_t p_address) const
{
    auto it = std::find_if(m_symbols.begin(), m_symbols.end(),
                           [p_address](const AbstractSymbol& entry) {
                               return entry.getValue() == p_address;
                           });

    if (it != m_symbols.end())
    {
        return it->getName();
    }

    return "";
}

void Symbols::evaluate(std::vector<std::pair<std::int32_t, std::string> >& p_reasons,
                       std::map<elf::Capabilties, std::set<std::string> >& p_capabilities) const
{
    (void)p_reasons; //appears to be unused
    std::uint32_t noType = 0;
    for (const auto& entry : m_symbols)
    {
        if ((entry.getType() & 0x0f) == elf::symbol::k_file)
        {
            std::map<std::string, std::pair<elf::Capabilties, std::string> >::const_iterator it = files.find(entry.getName());
            if (it != files.end())
            {
                p_capabilities[it->second.first].insert(it->second.second);
            }
        }
        else if ((entry.getType() & 0x0f) == elf::symbol::k_function ||
                 (entry.getType() & 0x0f) == elf::symbol::k_notype)
        {
            if ((entry.getType() & 0x0f) == elf::symbol::k_notype)
            {
                ++noType;
            }
            std::map<std::string, std::pair<elf::Capabilties, std::string> >::const_iterator it = capabilities.find(entry.getName());
            if (it != capabilities.end())
            {
                if (it->first == "dlsym" && !m_isDY)
                {
                    continue;
                }

                p_capabilities[it->second.first].insert(it->second.second);
            }
        }
    }
    if (m_symbols.size() > 10 && ((m_symbols.size() - 2) == noType))
    {
        // seen in Mayhem. Not sure what technique this is
        p_capabilities[elf::k_antidebug].insert("Almost all symbols marked as NO_TYPE in they symbol table");
    }
}

std::string Symbols::printToStdOut() const
{
    std::stringstream returnValue;
    returnValue << "Symbols (count=" << m_symbols.size() << ")\n";
    for (const auto& symbol : m_symbols)
    {
        returnValue << "\t" << "type=" << symbol.getTypeName() << ", binding="
                    << symbol.getBinding() << ", value=0x" << std::hex
                    << symbol.getValue() << ", name=" << symbol.getName() << "\n";
    }
    return returnValue.str();
}

