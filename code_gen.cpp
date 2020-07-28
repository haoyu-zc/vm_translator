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
    case Token::C_ARITHMETIC:
        writeArithmetic(_parser->cmd);
        break;
    default:
        break;
    }
}

void CodeGenerator::writeArithmetic(int command)
{
    switch (command)
    {
    case Token::ADD:
        fprintf(_hackfile, "@SP\n"
                           "M=M-1\n"
                           "A=M\n"
                           "D=M\n"
                           "@SP\n"
                           "M=M-1\n"
                           "A=M\n"
                           "M=M+D\n"
                           "@SP\n"
                           "M=M+1\n");
        break;
    case Token::SUB:
        fprintf(_hackfile, "@SP\n"
                           "M=M-1\n"
                           "A=M\n"
                           "D=M\n"
                           "@SP\n"
                           "M=M-1\n"
                           "A=M\n"
                           "M=M-D\n"
                           "@SP\n"
                           "M=M+1\n");
        break;
    case Token::NEG:
        fprintf(_hackfile, "@SP\n"
                           "M=M-1\n"
                           "A=M\n"
                           "M=-M\n"
                           "@SP\n"
                           "M=M+1\n");
        break;
    case Token::EQ:
        fprintf(_hackfile, "@SP\n"
                           "AM=M-1\n"
                           "D=M\n"
                           "A=A-1\n"
                           "D=M-D\n"
                           "@TRUE%d\n"
                           "D;JEQ\n"
                           "@SP\n"
                           "AM=M-1\n"
                           "M=0\n"
                           "@SP\n"
                           "M=M+1\n"
                           "@FALSE%d\n"
                           "0;JMP\n"
                           "(TRUE%d)\n"
                           "@SP\n"
                           "AM=M-1\n"
                           "M=-1\n"
                           "@SP\n"
                           "M=M+1\n"
                           "(FALSE%d)\n", index, index, index, index);
        index++;
        break;
    case Token::GT:
        fprintf(_hackfile, "@SP\n"
                           "AM=M-1\n"
                           "D=M\n"
                           "A=A-1\n"
                           "D=M-D\n"
                           "@TRUE%d\n"
                           "D;JGT\n"
                           "@SP\n"
                           "AM=M-1\n"
                           "M=0\n"
                           "@SP\n"
                           "M=M+1\n"
                           "@FALSE%d\n"
                           "0;JMP\n"
                           "(TRUE%d)\n"
                           "@SP\n"
                           "AM=M-1\n"
                           "M=-1\n"
                           "@SP\n"
                           "M=M+1\n"
                           "(FALSE%d)\n", index, index, index, index);
        index++;
        break;
    case Token::LT:
        fprintf(_hackfile, "@SP\n"
                           "AM=M-1\n"
                           "D=M\n"
                           "A=A-1\n"
                           "D=M-D\n"
                           "@TRUE%d\n"
                           "D;JLT\n"
                           "@SP\n"
                           "AM=M-1\n"
                           "M=0\n"
                           "@SP\n"
                           "M=M+1\n"
                           "@FALSE%d\n"
                           "0;JMP\n"
                           "(TRUE%d)\n"
                           "@SP\n"
                           "AM=M-1\n"
                           "M=-1\n"
                           "@SP\n"
                           "M=M+1\n"
                           "(FALSE%d)\n", index, index, index, index);
        index++;
        break;
    case Token::AND:
        fprintf(_hackfile, "@SP\n"
                           "M=M-1\n"
                           "A=M\n"
                           "D=M\n"
                           "@SP\n"
                           "M=M-1\n"
                           "A=M\n"
                           "M=M&D\n"
                           "@SP\n"
                           "M=M+1\n");
        break;
    case Token::OR:
        fprintf(_hackfile, "@SP\n"
                           "M=M-1\n"
                           "A=M\n"
                           "D=M\n"
                           "@SP\n"
                           "M=M-1\n"
                           "A=M\n"
                           "M=M|D\n"
                           "@SP\n"
                           "M=M+1\n");
        break;
    case Token::NOT:
        fprintf(_hackfile, "@SP\n"
                           "M=M-1\n"
                           "A=M\n"
                           "D=M\n"
                           "@SP\n"
                           "M=M-1\n"
                           "A=M\n"
                           "M=!D\n"
                           "@SP\n"
                           "M=M+1\n");
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