#include "symbol_table.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <initializer_list>
#include "parser.h"

using namespace std;

SymbolTable::SymbolTable()
{
    string tableFile = "./tables/symbols.txt";
    this->loadTable({tableFile});
}

// Load external predefined variables
void SymbolTable::loadTable(initializer_list<string> files)
{
    
    ifstream fin;
    string line;
    string symbol;
    int address;
    int tabPos;

    for (const string &file : files)
    {
        fin.open(file);
        while (fin.peek() != EOF)
        {
            getline(fin, line);
            tabPos = line.find('\t');
            symbol = line.substr(0, tabPos);
            address = stoi(line.substr(tabPos + 1));
            this->symbTable[symbol] = address;
            // cout << symbol << '\t' << symbTable[symbol] << '\t' << this->contains(symbol) << endl;
        }
        fin.close();
    }
}

void SymbolTable::loadSymbol(Parser &parser)
{
    // Rom addresss starting from 0. ++romAdd when encounter none-L commands.
    int romAddr = -1;
    while (parser.hasMoreCommands())
    {
        parser.advance();
        if (parser.commandType() == L_COMMAND)
        {
            addEntry(parser.symbol(), romAddr + 1);
            //cout << parser1.symbol() << '\t' << symbTable.getAddress(parser1.symbol()) << endl;
        }
        else
            ++romAddr;
    }
}

void SymbolTable::addEntry(string symbol, int address)
{
    if (this->contains(symbol))
        throw runtime_error("Key " + symbol + " already exsits!");
    else
        this->symbTable[symbol] = address;
}

bool SymbolTable::contains(string symbol)
{
    return this->symbTable.count(symbol);
}

int SymbolTable::getAddress(string symbol)
{
    return symbTable[symbol];
}