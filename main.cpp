#include <string>
#include "parser.h"
#include "code_gen.h"
#include "utils.h"
#include "file.h"
#include <stdio.h>
#include "file.h"
#include <vector>
#include <deque>

std::string program;
std::string filename_in;
std::string filename_out;
std::string filepath_in;
bool debug = false;
static bool only_preprocess = false;
static bool only_compile = false;
static bool specified_out_name = false;
static bool generate_comments = true;

namespace fsys = std::filesystem;

int main(int argc, char *argv[])
{
    if (!argv[1])
    {
        throw std::invalid_argument("ERROR. Assembly file name not provided!");
    }
    filepath_in = (argv[1]);
    filename_in = getNameStem(filepath_in);

    FILE *fp;
    if (specified_out_name)
        fp = fopen((filename_out + ".asm").c_str(), "w");

    // Parser for vm files.
    // Remove comments and white spaces.
    Token tk;
    auto fsys_path = fsys::path(filepath_in);

    // Directory
    if (fsys::is_directory(fsys_path))
    {
        // Use directory name as output asm file name.
        if (!specified_out_name)
            fp = fopen((getNameStem(filepath_in) + ".asm").c_str(), "w");

        CodeGenerator initiator(fp);
        initiator.writeInit();

        std::deque<std::string> file_list;

        for (const auto &entry : fsys::directory_iterator(fsys_path))
        {
            if (entry.path().extension().string() == ".vm" || entry.path().extension().string() == ".VM")
            {
                if (entry.path().stem().string() == "Sys" || entry.path().extension().string() == "SyS")
                    file_list.push_front(entry.path().string());
                else
                    file_list.push_back(entry.path().string());
            }
        }

        for (const auto &file : file_list)
        {
            Parser parser(file, tk);
            CodeGenerator cg(fp, &parser);
            while (parser.hasMoreCommands())
            {
                parser.advance();
                parser.parse();
                cg.writeHack();
            }
        }
        fclose(fp);
    }
    else // Single file
    {
        if (!specified_out_name)
            fp = fopen((getNameStem(filepath_in) + ".asm").c_str(), "w");
        Parser parser(filepath_in, tk);
        CodeGenerator cg(fp, &parser);
        while (parser.hasMoreCommands())
        {
            parser.advance();
            parser.parse();
            cg.writeHack();
        }
        fclose(fp);
        parser.closeFstream();
    }

    return 0;
}
