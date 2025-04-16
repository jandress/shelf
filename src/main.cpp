//boost free
#include <cstdlib>
#include <iostream>


#include <filesystem>

#include <CLI/CLI11.hpp>

#include "version.hpp"
#include "elfparser.hpp"

#ifdef QT_GUI
#include "ui/mainwindow.h"
#include <QApplication>
#endif

namespace
{
    [[maybe_unused]] bool parseCommandLine(int p_argCount, char* p_argArray[],
                          std::string& p_file, std::string& p_directory,
                          bool& p_print, bool& p_printReasons, bool& p_capabilities)
    {

        CLI::App app{"elfparser"};
        bool show_version = false;

        app.set_help_flag("-h,--help", "A list of command line options");
        app.add_flag("-v,--version",show_version,"Display version information");
        app.add_option("-f,--file", p_file, "The ELF file to examine");
        app.add_option("-d,--directory", p_directory, "The directory to look through.");
        app.add_flag("-r,--reasons", p_printReasons, "Print the scoring reasons");
        app.add_flag("-c,--capabilities", p_capabilities, "Print the files observed capabilities");
        app.add_flag("-p,--print", p_print, "Print the ELF files various parsed structures.");

        try
        {
            app.parse(p_argCount, p_argArray);
        }
        catch (const CLI::ParseError &e)
        {
            return app.exit(e);
        }

        if (app.got_subcommand("help"))
        {
            std::cout << app.help() << std::endl;
            return false;
        }

        if (show_version) {
            std::cout << elfparser::s_version << std::endl;
            std::exit(0);
        }

        if (!p_file.empty() && !p_directory.empty())
        {
            std::cout << app.help() << std::endl;
            return false;
        }

        return true;
    }

    /*!
     * Pass the file to the parser and print the score if an error doesn't
     * occur. Print other output based on passed in bools.
     * \param[in] p_fileName the file to parse
     * \param[in] p_printReasons indicates if we should print the score reasons
     * \param[in] p_printCapabilities print extra knowledge about the binary
     * \param[in] p_printELF print the various data structures we parse
     */
    [[maybe_unused]] void do_parsing(const std::string& p_fileName, bool p_printReasons,
                    bool p_printCapabilities, bool p_printELF)
    {
        ELFParser parser;

        try
        {
            parser.parse(p_fileName);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error in parsing " << p_fileName << ": "  << e.what() << std::endl;
            return;
        }

        parser.evaluate();
        std::cout << p_fileName << " - Score: " << parser.getScore();
        if (!parser.getFamily().empty())
        {
            std::cout << " [Family: " << parser.getFamily() << "]";
        }
        std::cout << std::endl;

        if (p_printReasons)
        {
            parser.printReasons();
        }
        if (p_printCapabilities)
        {
            parser.printCapabilities();
        }
        if (p_printELF)
        {
            parser.printAll();
        }
    }
}

#ifdef QT_GUI
int main(int p_argCount, char* p_argArray[])
{
    QApplication app(p_argCount, p_argArray);
    MainWindow window;
    window.show();
    return app.exec();
}
#else
/*!
 * Parse the command line options and process a file or a directory
 */
int main(int p_argCount, char* p_argArray[])
{
    bool printElf = false;
    bool printReasons = false;
    bool printCapabilities = false;
    std::string fileName;
    std::string directoryName;
    if (!parseCommandLine(p_argCount, p_argArray, fileName, directoryName,
        printElf, printReasons, printCapabilities))
    {
        return EXIT_FAILURE;
    }

    if (!fileName.empty())
    {
        do_parsing(fileName, printReasons, printCapabilities, printElf);
    }
    else if (!directoryName.empty())
    {
        for (std::filesystem::recursive_directory_iterator iter(directoryName);
             iter != std::filesystem::recursive_directory_iterator(); ++iter)
        {
            if (!std::filesystem::is_regular_file(iter->path()))
            {
                continue;
            }
            do_parsing(iter->path().string(), printReasons, printCapabilities, printElf);
        }
    }

    return EXIT_SUCCESS;
}
#endif
