//boost free
#include <cstdlib>
#include <iostream>


//#include <boost/filesystem.hpp> //replace with #include <filesystem>, this needs changes to the compiler flags in cmakelists.txt to get the C++17 features
#include <filesystem>

//#include <boost/program_options.hpp> //replace with CLI11
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
        // boost::program_options::options_description description("options");
        // description.add_options()
        // ("help", "A list of command line options")
        // ("version", "Display version information")
        // ("file,f", boost::program_options::value<std::string>(),
        //     "The ELF file to examine")
        // ("directory,d", boost::program_options::value<std::string>(),
        //     "The directory to look through.")
        // ("reasons,r", "Print the scoring reasons")
        // ("capabilities,c", "Print the files observed capabilities")
        // ("print,p", "Print the ELF files various parsed structures.");

        CLI::App app{"elfparser"};
        bool show_version = false;

        app.set_help_flag("-h,--help", "A list of command line options");
        app.add_flag("-v,--version",show_version,"Display version information");
        app.add_option("-f,--file", p_file, "The ELF file to examine");
        app.add_option("-d,--directory", p_directory, "The directory to look through.");
        app.add_flag("-r,--reasons", p_printReasons, "Print the scoring reasons");
        app.add_flag("-c,--capabilities", p_capabilities, "Print the files observed capabilities");
        app.add_flag("-p,--print", p_print, "Print the ELF files various parsed structures.");


        // boost::program_options::variables_map argv_map;
        // try
        // {
        //     boost::program_options::store(
        //         boost::program_options::parse_command_line(
        //             p_argCount, p_argArray, description), argv_map);
        // }
        // catch (const std::exception& e)
        // {
        //     std::cerr << e.what() << "\n" << std::endl;
        //     std::cout << description << std::endl;
        //     return false;
        // }

        // boost::program_options::notify(argv_map);
        // if (argv_map.empty() || argv_map.count("help"))
        // {
        //     std::cout << description << std::endl;
        //     return false;
        // }

        // if (argv_map.count("version"))
        // {
        //     std::cout << elfparser::s_version << std::endl;
        //     return false;
        // }

        // p_print = argv_map.count("print") != 0;
        // p_printReasons = argv_map.count("reasons") != 0;
        // p_capabilities = argv_map.count("capabilities") != 0;

        // if (argv_map.count("file") && argv_map.count("directory"))
        // {
        //     std::cout << description << std::endl;
        //     return false;
        // }

        // if (argv_map.count("file"))
        // {
        //     p_file.assign(argv_map["file"].as<std::string>());
        //     return true;
        // }

        // if (argv_map.count("directory"))
        // {
        //     p_directory.assign(argv_map["directory"].as<std::string>());
        //     return true;
        // }

        // return false;

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
        //for (boost::filesystem::recursive_directory_iterator iter(directoryName);
        for (std::filesystem::recursive_directory_iterator iter(directoryName);
             //iter != boost::filesystem::recursive_directory_iterator(); ++iter)
             iter != std::filesystem::recursive_directory_iterator(); ++iter)
        {
            //if (!boost::filesystem::is_regular_file(iter->path()))
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
