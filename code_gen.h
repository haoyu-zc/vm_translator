#pragma once
#include <string>
#include <map>
#include <fstream>
#include <initializer_list>
#include "parser.h"
#include "token.h"

using std::string;

class CodeGenerator
{
private:
    FILE *_hackfile;
    Parser *_parser;
    bool generate_comments = true;
    int index = 0;

public:
    CodeGenerator(FILE *file, Parser *parser);
    void writeHack();
    void writeArithmetic(int command);
    // Generate code of EQ, GT and LT
    void writeCompa(std::string compa_prediacte);
    void writePush(int arg1, int arg2);
    void writePushTemplate(const char *segment, int arg2);
    void writePopTemplate(const char *segment, int arg2);
    void writePop(int command, int arg1, int arg2);

    // Program control
    void writeInit();
    void writeLabel(std::string label);
    void writeGoto(std::string label);
    void writeIf(std::string label);
    void writeFunction(std::string label, int num_locals);
    void writeReturn();
    void writeCall(std::string label, int num_args);
};
