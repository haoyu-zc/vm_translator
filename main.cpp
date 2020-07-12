#include <iostream>
#include <fstream>
#include <string>
#include "parser.h"
#include "encoder.h"
#include "symbol_table.h"
#include <stdexcept>
#include <algorithm>
#include <filesystem>
#include "utils.h"
#include "file.h"

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

    SymbolTable symbTable;
    // First scan to deal with labels.
    Parser parser1(filepath.string());
    symbTable.loadSymbol(parser1);

    // Second scan.
    Parser parser2(filepath.string());
    Encoder code;
    code.writeFile(parser2, filename_in, symbTable);

    return 0;
}
