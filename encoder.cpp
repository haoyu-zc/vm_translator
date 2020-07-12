#include "encoder.h"
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

using namespace std;

Encoder::Encoder()
{
    string compa0File = "./tables/comp_a0.txt";
    string compa1File = "./tables/comp_a1.txt";
    string destFile = "./tables/dest.txt";
    string jumpFile = "./tables/jump.txt";

    this->loadTable({compa0File, compa1File, destFile, jumpFile});
}

// Load external files of command bit translation rules
void Encoder::loadTable(initializer_list<string> files)
{
    for (const string &file : files)
    {
        ifstream fin;
        fin.open(file);
        string line;
        string symbol;
        string binary;
        int tabPos;

        while (fin.peek() != EOF)
        {
            getline(fin, line);
            tabPos = line.find('\t');
            symbol = line.substr(0, tabPos);
            binary = line.substr(tabPos + 1);
            if (file.find("comp") != string::npos)
                this->compTable[symbol] = binary;
            else if (file.find("dest") != string::npos)
                this->destTable[symbol] = binary;
            else if (file.find("jump") != string::npos)
                this->jumpTable[symbol] = binary;
        }

        fin.close();
    }
}

string Encoder::comp(string compStr)
{
    return this->compTable[compStr];
}

string Encoder::dest(string destStr)
{
    return this->destTable[destStr];
}

string Encoder::jump(string jumpStr)
{
    return this->jumpTable[jumpStr];
}

string Encoder::aCmdEncoder(string aStr)
{
    // Convert the decimal value of an A-Command to a binary string with leading-zero padding.
    string binary = bitset<15>(stoi(aStr)).to_string();
    return "0" + binary;
}

void Encoder::writeFile(Parser &parser, string &filename, SymbolTable &symbTable)
{
    ofstream hackFile;
    hackFile.open(getNameStem(filename) + ".hack");
    int memOffset = 16;
    int memAddr;
    string symbol;
    string binary;

    while (parser.hasMoreCommands())
    {
        parser.advance();
        if (parser.commandType() == A_COMMAND)
        {
            //cout << " A_COMMAND!" << endl;
            symbol = parser.symbol();
            // @ a constant
            if (isNumber(symbol))
            {
                binary = aCmdEncoder(symbol);
            }
            // Check if this symbol is a label which already been mapped.
            else if (symbTable.contains(symbol))
            {
                memAddr = symbTable.getAddress(symbol);
                binary = aCmdEncoder(to_string(memAddr));
            }
            // Then the symbol must be a variable.
            else
            {
                symbTable.addEntry(symbol, memOffset);
                binary = aCmdEncoder(to_string(memOffset));
                ++memOffset;
            }
            hackFile << binary << endl;
        }
        else if (parser.commandType() == C_COMMAND)
        {
            binary = "111" + comp(parser.comp()) + dest(parser.dest()) + jump(parser.jump());
            hackFile << binary << endl;
        }
    }
    hackFile.close();
}