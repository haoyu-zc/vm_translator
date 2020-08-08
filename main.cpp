#include <string>
#include "parser.h"
#include "code_gen.h"
#include "utils.h"
#include "file.h"
#include <stdio.h>

std::string program;
std::string filename_in;
std::string filename_out;
std::string filepath_in;
bool debug = false;
static bool only_preprocess = false;
static bool only_compile = false;
static bool specified_out_name = false;
static bool generate_comments = true;

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
    {
        fp = fopen((filename_out + ".asm").c_str(), "w");
    }
    else
    {
        fp = fopen((getFilepath(filepath_in) + ".asm").c_str(), "w");
    }

    // Parser for vm files.
    // Remove comments and white spaces.
    Token tk;
    Parser parser(argv[1], tk);
    CodeGenerator cg(fp, &parser);
    while (parser.hasMoreCommands())
    {
        parser.advance();
        parser.parse();
        cg.writeHack();
    }
    fclose(fp);
    // parser.closeFstream();

    return 0;
}
