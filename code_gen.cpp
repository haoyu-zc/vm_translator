#include "code_gen.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <initializer_list>
#include <bitset>
#include <cstring>
#include "parser.h"
#include "file.h"
#include "utils.h"
#include "symbol_table.h"
#include "token.h"
#include <stdio.h>

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
    case Token::C_ARITHMETIC:
        writeArithmetic(_parser->cmd);
        break;
    default:
        break;
    }
}

const char *pop_stem = "@SP\n"
                       "AM=M-1\n"
                       "D=M\n"
                       "A=A-1\n";

const char *stack_dec = "@SP\n"
                        "AM=M-1\n";

const char *pointer_inc = "@SP\n"
                          "M=M+1\n";

void CodeGenerator::writeCompa(std::string compa_predicate)
{
    fprintf(_hackfile, "@SP\n"
                       "AM=M-1\n"
                       "D=M\n"
                       "A=A-1\n"
                       "D=M-D\n"
                       "@TRUE%d\n" // index
                       "D;%s\n"    // compa_predicate
                       "@SP\n"
                       "AM=M-1\n"
                       "M=0\n"
                       "@SP\n"
                       "M=M+1\n"
                       "@FALSE%d\n" // index
                       "0;JMP\n"
                       "(TRUE%d)\n" // index
                       "@SP\n"
                       "AM=M-1\n"
                       "M=-1\n"
                       "@SP\n"
                       "M=M+1\n"
                       "(FALSE%d)\n", // index
            index, compa_predicate.c_str(), index, index, index);
    index++;
}

void CodeGenerator::writeArithmetic(int command)
{
    switch (command)
    {
    case Token::ADD:
        fprintf(_hackfile, pop_stem);
        fprintf(_hackfile, "M=M+D\n");
        break;
    case Token::SUB:
        fprintf(_hackfile, pop_stem);
        fprintf(_hackfile, "M=M-D\n");
        break;
    case Token::NEG:
        fprintf(_hackfile, stack_dec);
        fprintf(_hackfile, "M=-M\n");
        fprintf(_hackfile, pointer_inc);
        break;
    case Token::EQ:
        writeCompa("JEQ");
        break;
    case Token::GT:
        writeCompa("JGT");
        break;
    case Token::LT:
        writeCompa("JLT");
        break;
    case Token::AND:
        fprintf(_hackfile, pop_stem);
        fprintf(_hackfile, "M=M&D\n");
        break;
    case Token::OR:
        fprintf(_hackfile, pop_stem);
        fprintf(_hackfile, "M=M|D\n");
        break;
    case Token::NOT:
        fprintf(_hackfile, stack_dec);
        fprintf(_hackfile, "M=!M\n");
        fprintf(_hackfile, pointer_inc);
        break;
    default:
        break;
    }
}

void CodeGenerator::writePush(int command, int arg1, int arg2)
{
    // Hack.asm of push constant c
    fprintf(_hackfile, "@%d\n", arg2);
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