#pragma once
#include <map>
#include <string>
#include <initializer_list>
#include "parser.h"

using std::map;
using std::string;
using std::initializer_list;

class SymbolTable
{
private:
    map<string, int> symbTable;

public:
    SymbolTable();
    void addEntry(string symbol, int address);
    bool contains(string symbol);
    int getAddress(string symbol);
    // Load symbols from external files
    void loadTable(initializer_list<string> files);
    // Load symbols(bariables, labels) when the parser is scanning through
    void loadSymbol(Parser &parser);
    void init();
};

