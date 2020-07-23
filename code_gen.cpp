#include "code_gen.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <initializer_list>
#include <bitset>
#include "parser.h"
#include "file.h"
#include "utils.h"
#include "symbol_table.h"


CodeGenerator::CodeGenerator(FILE* file)
{
    hackfile = file;
}

void CodeGenerator::writePush(int command, int arg1, int arg2)
{
    // if(arg1 == Token::CONSTANT)
    // {
        //fprintf(hackfile, "@%d\nD=A\n", arg2);
        // std::cout << command << " " << arg1 << " " << arg2 << std::endl;
        fprintf(hackfile, "test\n");
    // }
}


void CodeGenerator::writeFile(Parser &parser, std::string &filename, SymbolTable &symbTable)
{
}