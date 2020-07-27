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
#include "token.h"

CodeGenerator::CodeGenerator(FILE *file, Parser *parser)
{
    _hackfile = file;
    _parser = parser;
}

void CodeGenerator::writeHack()
{
    if (generate_comments)
        fprintf(_hackfile, "//%s\n", _parser->currentCmdLine.c_str());
    switch (_parser->command_type)
    {
    case Token::C_PUSH:
        writePush(_parser->cmd, _parser->arg1, _parser->arg2);
        break;
    
    default:
        break;
    }
    
}

void CodeGenerator::writePush(int command, int arg1, int arg2)
{
    // Hack.asm of push constant c
    fprintf(_hackfile, "@%d\n", arg1);
    fprintf(_hackfile, "D=A\n"
                       "@SP\n"
                       "A=M\n"
                       "M=D\n"
                       "@SP\n"
                       "M=M+1\n");
}

void CodeGenerator::writeFile(Parser &parser, std::string &filename, SymbolTable &symbTable)
{
}