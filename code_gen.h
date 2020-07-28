#pragma once
#include <string>
#include <map>
#include <fstream>
#include <initializer_list>
#include "parser.h"
#include "symbol_table.h"
#include "token.h"

using std::string;

class CodeGenerator
{
private:
    FILE* _hackfile;
    Parser* _parser;
    bool generate_comments = true;
    int index = 0;


public:
    CodeGenerator(FILE* file, Parser* parser);
    void writeHack();
    void writeArithmetic(int command);
    void writePush(int command, int arg1, int arg2);
    void writePop(int command, int arg1, int arg2);
    void writeFile(Parser &parser, string &filename, SymbolTable &symbolTable);
};

