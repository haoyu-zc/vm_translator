#pragma once
#include <string>
#include <map>
#include <initializer_list>
#include "parser.h"
#include "symbol_table.h"

using std::string;
using std::map;
using std::initializer_list;

class Encoder
{
private:
    map<string, string> compTable;
    map<string, string> destTable;
    map<string, string> jumpTable;

public:
    Encoder();
    void loadTable(initializer_list<string> files);
    string comp(string compStr);
    string dest(string destStr);
    string jump(string jumpStr);
    string aCmdEncoder(string aStr);
    void writeFile(Parser &parser, string &filename, SymbolTable &symbolTable);
};

