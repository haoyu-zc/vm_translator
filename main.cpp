#include <string>
#include <filesystem>
#include "parser.h"
#include "code_gen.h"
#include "symbol_table.h"
#include "utils.h"
#include "file.h"

std::string program;
std::string filename_in;
std::string filename_out;
std::filesystem::path filepath_in;
bool debug = false;
static bool only_preprocess = false;
static bool only_compile = false;
static bool specified_out_name = false;

int main(int argc, char *argv[])
{
    if (!argv[1])
    {
        throw std::invalid_argument("ERROR. Assembly file name not provided!");
    }
    filepath_in = std::filesystem::path(argv[1]);
    filename_in = filepath_in.stem().string();

    FILE *fp = stdout;
    if (specified_out_name)
    {
        fp = fopen((filename_out + ".asm").c_str(), "w");
    }
    else
    {
        fp = fopen((getNameStem(filepath_in) + ".asm").c_str(), "w");
    }

    // Parser for vm files.
    // Remove comments and white spaces.
    Token tk;
    Parser parser(argv[1], tk);
    CodeGenerator cg(fp);
    while (parser.hasMoreCommands())
    {
        parser.advance();
        parser.parse();
        int type = parser.command_type;
        if (type == Token::C_PUSH)
        {
            cg.writePush(parser.cmd, parser.arg1, parser.arg2);
        }
    }
    parser.closeFstream();

    return 0;
}
