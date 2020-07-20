#include <string>
#include <filesystem>
#include "parser.h"
#include "code_gen.h"
#include "symbol_table.h"
#include "utils.h"

using namespace std;

std::string program;
std::string filename_in;
std::string filename_out;
filesystem::path filepath;
bool debug = false;
static bool only_preprocess = false;
static bool only_compile = false;
static bool specified_out_name = false;


int main(int argc, char *argv[])
{
    if (!argv[1])
    {
        throw invalid_argument("ERROR. Assembly file name not provided!");
    }
    filepath = filesystem::path(argv[1]);
    filename_in = filepath.stem().string();

    // Parser for vm files.
    // Remove comments and white spaces.
    Parser parser(argv[1]);
    Token tk;
    parser.parse(tk);
    while (parser.hasMoreCommands())
    {
        parser.advance();
        parser.commandType();
    }
    parser.closeFstream();

    return 0;
}
